// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef CEF_TESTS_UNITTESTS_TEST_HANDLER_H_
#define CEF_TESTS_UNITTESTS_TEST_HANDLER_H_
#pragma once

#include <list>
#include <map>
#include <string>
#include <utility>

#include "base/synchronization/waitable_event.h"

#include "include/cef_browser.h"
#include "include/cef_client.h"
#include "include/cef_frame.h"
#include "include/cef_task.h"
#include "testing/gtest/include/gtest/gtest.h"

class TrackCallback {
 public:
  TrackCallback(): gotit_(false) {}
  void yes() { gotit_ = true; }
  bool isSet() { return gotit_; }
  void reset() { gotit_ = false; }
  operator bool() const { return gotit_; }
 protected:
  bool gotit_;
};


// Base implementation of CefClient for unit tests. Add new interfaces as needed
// by test cases.
class TestHandler : public CefClient,
                    public CefDialogHandler,
                    public CefDisplayHandler,
                    public CefDownloadHandler,
                    public CefGeolocationHandler,
                    public CefJSDialogHandler,
                    public CefLifeSpanHandler,
                    public CefLoadHandler,
                    public CefRequestHandler {
 public:
  // Tracks the completion state of related test runs.
  class CompletionState {
   public:
    // |total| is the number of times that TestComplete() must be called before
    // WaitForTests() will return.
    explicit CompletionState(int total);

    // Call this method to indicate that a test has completed.
    void TestComplete();

    // This method blocks until TestComplete() has been called the required
    // number of times.
    void WaitForTests();

    int total() const { return total_; }
    int count() const { return count_; }

   private:
    int total_;
    int count_;

    // Handle used to notify when the test is complete
    base::WaitableEvent event_;
  };

  // Represents a collection of related tests that need to be run
  // simultaniously.
  class Collection {
   public:
    // The |completion_state| object must outlive this class.
    explicit Collection(CompletionState* completion_state);

    // The |test_handler| object must outlive this class and it must share the
    // same CompletionState object passed to the constructor.
    void AddTestHandler(TestHandler* test_handler);

    // Manages the test run.
    // 1. Calls TestHandler::SetupTest() for all of the test objects.
    // 2. Waits for all TestHandler objects to report that initial setup is
    //    complete by calling TestHandler::SetupComplete().
    // 3. Calls TestHandler::RunTest() for all of the test objects.
    // 4. Waits for all TestHandler objects to report that the test is
    //    complete by calling TestHandler::DestroyTest().
    void ExecuteTests();

   private:
    CompletionState* completion_state_;

    typedef std::list<TestHandler*> TestHandlerList;
    TestHandlerList handler_list_;
  };

  typedef std::map<int, CefRefPtr<CefBrowser> > BrowserMap;

  // The |completion_state| object if specified must outlive this class.
  explicit TestHandler(CompletionState* completion_state = NULL);
  ~TestHandler() override;

  // Implement this method to set up the test. Only used in combination with a
  // Collection. Call SetupComplete() once the setup is complete.
  virtual void SetupTest() {}

  // Implement this method to run the test. Call DestroyTest() once the test is
  // complete.
  virtual void RunTest() =0;

  // CefClient methods. Add new methods as needed by test cases.
  CefRefPtr<CefDialogHandler> GetDialogHandler() override {
    return this;
  }
  CefRefPtr<CefDisplayHandler> GetDisplayHandler() override {
    return this;
  }
  CefRefPtr<CefDownloadHandler> GetDownloadHandler() override {
    return this;
  }
  CefRefPtr<CefGeolocationHandler> GetGeolocationHandler() override {
    return this;
  }
  CefRefPtr<CefJSDialogHandler> GetJSDialogHandler() override {
    return this;
  }
  CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override {
    return this;
  }
  CefRefPtr<CefLoadHandler> GetLoadHandler() override {
    return this;
  }
  CefRefPtr<CefRequestHandler> GetRequestHandler() override {
    return this;
  }

  // CefDownloadHandler methods
  void OnBeforeDownload(
      CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefDownloadItem> download_item,
      const CefString& suggested_name,
      CefRefPtr<CefBeforeDownloadCallback> callback) override {}

  // CefLifeSpanHandler methods
  void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
  void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

  // CefRequestHandler methods
  CefRefPtr<CefResourceHandler> GetResourceHandler(
      CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefFrame> frame,
      CefRefPtr<CefRequest> request) override;

  // These methods should only be used if at most one non-popup browser exists.
  CefRefPtr<CefBrowser> GetBrowser();
  int GetBrowserId();

  // Copies the map of all the currently existing browsers into |map|. Must be
  // called on the UI thread.
  void GetAllBrowsers(BrowserMap* map);

  // Called by the test function to execute the test. This method blocks until
  // the test is complete. Do not reference the object after this method
  // returns. Do not use this method if the CompletionState object is shared by
  // multiple handlers or when using a Collection object.
  void ExecuteTest();

  // Returns true if a browser currently exists.
  static bool HasBrowser() { return browser_count_ > 0; }

 protected:
  // Indicate that test setup is complete. Only used in combination with a
  // Collection.
  virtual void SetupComplete();

  // Close any existing non-popup browsers. Test completion will be signaled
  // once all the browsers have closed if
  // |signal_completion_when_all_browsers_close_| is true (default value).
  // If no browsers exist then this method will do nothing and
  // TestComplete() must be called manually.
  virtual void DestroyTest();

  void CreateBrowser(const CefString& url,
                     CefRefPtr<CefRequestContext> request_context = NULL);

  void AddResource(const std::string& url,
                   const std::string& content,
                   const std::string& mimeType);
  void ClearResources();

  void SetSignalCompletionWhenAllBrowsersClose(bool val) {
    signal_completion_when_all_browsers_close_ = val;
  }
  bool SignalCompletionWhenAllBrowsersClose() const {
    return signal_completion_when_all_browsers_close_;
  }

  // Signal that the test is complete. This will be called automatically when
  // all existing non-popup browsers are closed if
  // |signal_completion_when_all_browsers_close_| is true (default value). It
  // is an error to call this method before all browsers have closed.
  void TestComplete();

 private:
  // Used to notify when the test is complete. Can be accessed on any thread.
  CompletionState* completion_state_;
  bool completion_state_owned_;

  // Map browser ID to browser object for non-popup browsers. Only accessed on
  // the UI thread.
  BrowserMap browser_map_;

  // Values for the first created browser. Modified on the UI thread but can be
  // accessed on any thread.
  int first_browser_id_;
  CefRefPtr<CefBrowser> first_browser_;

  // Map of resources that can be automatically loaded. Only accessed on the
  // IO thread.
  typedef std::map<std::string, std::pair<std::string, std::string> >
      ResourceMap;
  ResourceMap resource_map_;

  // If true test completion will be signaled when all browsers have closed.
  bool signal_completion_when_all_browsers_close_;

  // Used to track the number of currently existing browser windows.
  static int browser_count_;

  // Include the default reference counting implementation.
  IMPLEMENT_REFCOUNTING(TestHandler);

  DISALLOW_COPY_AND_ASSIGN(TestHandler);
};


// Post a task to the specified thread and wait for the task to execute as
// indication that all previously pending tasks on that thread have completed.
void WaitForThread(CefThreadId thread_id);
void WaitForThread(CefRefPtr<CefTaskRunner> task_runner);

#define WaitForIOThread() WaitForThread(TID_IO)
#define WaitForUIThread() WaitForThread(TID_UI)

// Returns true if the currently running test has failed.
bool TestFailed();

#define EXPECT_UI_THREAD()       EXPECT_TRUE(CefCurrentlyOn(TID_UI));
#define EXPECT_IO_THREAD()       EXPECT_TRUE(CefCurrentlyOn(TID_IO));
#define EXPECT_FILE_THREAD()     EXPECT_TRUE(CefCurrentlyOn(TID_FILE));
#define EXPECT_RENDERER_THREAD() EXPECT_TRUE(CefCurrentlyOn(TID_RENDERER));

// Helper macros for executing checks in a method with a boolean return value.
// For example:
//
// bool VerifyVals(bool a, bool b) {
//   V_DECLARE();
//   V_EXPECT_TRUE(a);
//   V_EXPECT_FALSE(b);
//   V_RETURN();
// }
//
// EXPECT_TRUE(VerifyVals(true, false));

#define V_DECLARE() \
    bool __verify = true; \
    bool __result

#define V_RETURN() \
    return __verify

#define V_EXPECT_TRUE(condition) \
    __result = !!(condition); \
    __verify &= __result; \
    GTEST_TEST_BOOLEAN_(__result, #condition, false, true, \
                        GTEST_NONFATAL_FAILURE_)

#define V_EXPECT_FALSE(condition) \
    __result = !!(condition); \
    __verify &= !__result; \
    GTEST_TEST_BOOLEAN_(!(__result), #condition, true, false, \
                        GTEST_NONFATAL_FAILURE_)

#endif  // CEF_TESTS_UNITTESTS_TEST_HANDLER_H_
