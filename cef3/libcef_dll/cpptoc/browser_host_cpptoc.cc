// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/browser_host_cpptoc.h"
#include "libcef_dll/cpptoc/drag_data_cpptoc.h"
#include "libcef_dll/cpptoc/request_context_cpptoc.h"
#include "libcef_dll/ctocpp/client_ctocpp.h"
#include "libcef_dll/ctocpp/run_file_dialog_callback_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT int cef_browser_host_create_browser(
    const cef_window_info_t* windowInfo, struct _cef_client_t* client,
    const cef_string_t* url, const struct _cef_browser_settings_t* settings,
    struct _cef_request_context_t* request_context) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: windowInfo; type: struct_byref_const
  DCHECK(windowInfo);
  if (!windowInfo)
    return 0;
  // Verify param: settings; type: struct_byref_const
  DCHECK(settings);
  if (!settings)
    return 0;
  // Unverified params: client, url, request_context

  // Translate param: windowInfo; type: struct_byref_const
  CefWindowInfo windowInfoObj;
  if (windowInfo)
    windowInfoObj.Set(*windowInfo, false);
  // Translate param: settings; type: struct_byref_const
  CefBrowserSettings settingsObj;
  if (settings)
    settingsObj.Set(*settings, false);

  // Execute
  bool _retval = CefBrowserHost::CreateBrowser(
      windowInfoObj,
      CefClientCToCpp::Wrap(client),
      CefString(url),
      settingsObj,
      CefRequestContextCppToC::Unwrap(request_context));

  // Return type: bool
  return _retval;
}

CEF_EXPORT cef_browser_t* cef_browser_host_create_browser_sync(
    const cef_window_info_t* windowInfo, struct _cef_client_t* client,
    const cef_string_t* url, const struct _cef_browser_settings_t* settings,
    struct _cef_request_context_t* request_context) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: windowInfo; type: struct_byref_const
  DCHECK(windowInfo);
  if (!windowInfo)
    return NULL;
  // Verify param: settings; type: struct_byref_const
  DCHECK(settings);
  if (!settings)
    return NULL;
  // Unverified params: client, url, request_context

  // Translate param: windowInfo; type: struct_byref_const
  CefWindowInfo windowInfoObj;
  if (windowInfo)
    windowInfoObj.Set(*windowInfo, false);
  // Translate param: settings; type: struct_byref_const
  CefBrowserSettings settingsObj;
  if (settings)
    settingsObj.Set(*settings, false);

  // Execute
  CefRefPtr<CefBrowser> _retval = CefBrowserHost::CreateBrowserSync(
      windowInfoObj,
      CefClientCToCpp::Wrap(client),
      CefString(url),
      settingsObj,
      CefRequestContextCppToC::Unwrap(request_context));

  // Return type: refptr_same
  return CefBrowserCppToC::Wrap(_retval);
}


// MEMBER FUNCTIONS - Body may be edited by hand.

cef_browser_t* CEF_CALLBACK browser_host_get_browser(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefBrowser> _retval = CefBrowserHostCppToC::Get(self)->GetBrowser();

  // Return type: refptr_same
  return CefBrowserCppToC::Wrap(_retval);
}

void CEF_CALLBACK browser_host_close_browser(struct _cef_browser_host_t* self,
    int force_close) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->CloseBrowser(
      force_close?true:false);
}

void CEF_CALLBACK browser_host_set_focus(struct _cef_browser_host_t* self,
    int focus) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->SetFocus(
      focus?true:false);
}

void CEF_CALLBACK browser_host_set_window_visibility(
    struct _cef_browser_host_t* self, int visible) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->SetWindowVisibility(
      visible?true:false);
}

cef_window_handle_t CEF_CALLBACK browser_host_get_window_handle(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return kNullWindowHandle;

  // Execute
  cef_window_handle_t _retval = CefBrowserHostCppToC::Get(
      self)->GetWindowHandle();

  // Return type: simple
  return _retval;
}

cef_window_handle_t CEF_CALLBACK browser_host_get_opener_window_handle(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return kNullWindowHandle;

  // Execute
  cef_window_handle_t _retval = CefBrowserHostCppToC::Get(
      self)->GetOpenerWindowHandle();

  // Return type: simple
  return _retval;
}

struct _cef_client_t* CEF_CALLBACK browser_host_get_client(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefClient> _retval = CefBrowserHostCppToC::Get(self)->GetClient();

  // Return type: refptr_diff
  return CefClientCToCpp::Unwrap(_retval);
}

struct _cef_request_context_t* CEF_CALLBACK browser_host_get_request_context(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefRequestContext> _retval = CefBrowserHostCppToC::Get(
      self)->GetRequestContext();

  // Return type: refptr_same
  return CefRequestContextCppToC::Wrap(_retval);
}

double CEF_CALLBACK browser_host_get_zoom_level(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  double _retval = CefBrowserHostCppToC::Get(self)->GetZoomLevel();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK browser_host_set_zoom_level(struct _cef_browser_host_t* self,
    double zoomLevel) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->SetZoomLevel(
      zoomLevel);
}

void CEF_CALLBACK browser_host_run_file_dialog(struct _cef_browser_host_t* self,
    cef_file_dialog_mode_t mode, const cef_string_t* title,
    const cef_string_t* default_file_name, cef_string_list_t accept_types,
    cef_run_file_dialog_callback_t* callback) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback)
    return;
  // Unverified params: title, default_file_name, accept_types

  // Translate param: accept_types; type: string_vec_byref_const
  std::vector<CefString> accept_typesList;
  transfer_string_list_contents(accept_types, accept_typesList);

  // Execute
  CefBrowserHostCppToC::Get(self)->RunFileDialog(
      mode,
      CefString(title),
      CefString(default_file_name),
      accept_typesList,
      CefRunFileDialogCallbackCToCpp::Wrap(callback));
}

void CEF_CALLBACK browser_host_start_download(struct _cef_browser_host_t* self,
    const cef_string_t* url) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->StartDownload(
      CefString(url));
}

void CEF_CALLBACK browser_host_print(struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->Print();
}

void CEF_CALLBACK browser_host_find(struct _cef_browser_host_t* self,
    int identifier, const cef_string_t* searchText, int forward, int matchCase,
    int findNext) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: searchText; type: string_byref_const
  DCHECK(searchText);
  if (!searchText)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->Find(
      identifier,
      CefString(searchText),
      forward?true:false,
      matchCase?true:false,
      findNext?true:false);
}

void CEF_CALLBACK browser_host_stop_finding(struct _cef_browser_host_t* self,
    int clearSelection) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->StopFinding(
      clearSelection?true:false);
}

void CEF_CALLBACK browser_host_show_dev_tools(struct _cef_browser_host_t* self,
    const cef_window_info_t* windowInfo, struct _cef_client_t* client,
    const struct _cef_browser_settings_t* settings,
    const cef_point_t* inspect_element_at) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: windowInfo; type: struct_byref_const
  DCHECK(windowInfo);
  if (!windowInfo)
    return;
  // Verify param: client; type: refptr_diff
  DCHECK(client);
  if (!client)
    return;
  // Verify param: settings; type: struct_byref_const
  DCHECK(settings);
  if (!settings)
    return;
  // Unverified params: inspect_element_at

  // Translate param: windowInfo; type: struct_byref_const
  CefWindowInfo windowInfoObj;
  if (windowInfo)
    windowInfoObj.Set(*windowInfo, false);
  // Translate param: settings; type: struct_byref_const
  CefBrowserSettings settingsObj;
  if (settings)
    settingsObj.Set(*settings, false);
  // Translate param: inspect_element_at; type: simple_byref_const
  CefPoint inspect_element_atVal =
      inspect_element_at?*inspect_element_at:CefPoint();

  // Execute
  CefBrowserHostCppToC::Get(self)->ShowDevTools(
      windowInfoObj,
      CefClientCToCpp::Wrap(client),
      settingsObj,
      inspect_element_atVal);
}

void CEF_CALLBACK browser_host_close_dev_tools(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->CloseDevTools();
}

void CEF_CALLBACK browser_host_set_mouse_cursor_change_disabled(
    struct _cef_browser_host_t* self, int disabled) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->SetMouseCursorChangeDisabled(
      disabled?true:false);
}

int CEF_CALLBACK browser_host_is_mouse_cursor_change_disabled(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserHostCppToC::Get(self)->IsMouseCursorChangeDisabled();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK browser_host_replace_misspelling(
    struct _cef_browser_host_t* self, const cef_string_t* word) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: word; type: string_byref_const
  DCHECK(word);
  if (!word)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->ReplaceMisspelling(
      CefString(word));
}

void CEF_CALLBACK browser_host_add_word_to_dictionary(
    struct _cef_browser_host_t* self, const cef_string_t* word) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: word; type: string_byref_const
  DCHECK(word);
  if (!word)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->AddWordToDictionary(
      CefString(word));
}

int CEF_CALLBACK browser_host_is_window_rendering_disabled(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefBrowserHostCppToC::Get(self)->IsWindowRenderingDisabled();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK browser_host_was_resized(struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->WasResized();
}

void CEF_CALLBACK browser_host_was_hidden(struct _cef_browser_host_t* self,
    int hidden) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->WasHidden(
      hidden?true:false);
}

void CEF_CALLBACK browser_host_notify_screen_info_changed(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->NotifyScreenInfoChanged();
}

void CEF_CALLBACK browser_host_invalidate(struct _cef_browser_host_t* self,
    cef_paint_element_type_t type) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->Invalidate(
      type);
}

void CEF_CALLBACK browser_host_send_key_event(struct _cef_browser_host_t* self,
    const struct _cef_key_event_t* event) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: event; type: struct_byref_const
  DCHECK(event);
  if (!event)
    return;

  // Translate param: event; type: struct_byref_const
  CefKeyEvent eventObj;
  if (event)
    eventObj.Set(*event, false);

  // Execute
  CefBrowserHostCppToC::Get(self)->SendKeyEvent(
      eventObj);
}

void CEF_CALLBACK browser_host_send_mouse_click_event(
    struct _cef_browser_host_t* self, const struct _cef_mouse_event_t* event,
    cef_mouse_button_type_t type, int mouseUp, int clickCount) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: event; type: struct_byref_const
  DCHECK(event);
  if (!event)
    return;

  // Translate param: event; type: struct_byref_const
  CefMouseEvent eventObj;
  if (event)
    eventObj.Set(*event, false);

  // Execute
  CefBrowserHostCppToC::Get(self)->SendMouseClickEvent(
      eventObj,
      type,
      mouseUp?true:false,
      clickCount);
}

void CEF_CALLBACK browser_host_send_mouse_move_event(
    struct _cef_browser_host_t* self, const struct _cef_mouse_event_t* event,
    int mouseLeave) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: event; type: struct_byref_const
  DCHECK(event);
  if (!event)
    return;

  // Translate param: event; type: struct_byref_const
  CefMouseEvent eventObj;
  if (event)
    eventObj.Set(*event, false);

  // Execute
  CefBrowserHostCppToC::Get(self)->SendMouseMoveEvent(
      eventObj,
      mouseLeave?true:false);
}

void CEF_CALLBACK browser_host_send_mouse_wheel_event(
    struct _cef_browser_host_t* self, const struct _cef_mouse_event_t* event,
    int deltaX, int deltaY) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: event; type: struct_byref_const
  DCHECK(event);
  if (!event)
    return;

  // Translate param: event; type: struct_byref_const
  CefMouseEvent eventObj;
  if (event)
    eventObj.Set(*event, false);

  // Execute
  CefBrowserHostCppToC::Get(self)->SendMouseWheelEvent(
      eventObj,
      deltaX,
      deltaY);
}

void CEF_CALLBACK browser_host_send_focus_event(
    struct _cef_browser_host_t* self, int setFocus) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->SendFocusEvent(
      setFocus?true:false);
}

void CEF_CALLBACK browser_host_send_capture_lost_event(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->SendCaptureLostEvent();
}

void CEF_CALLBACK browser_host_notify_move_or_resize_started(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->NotifyMoveOrResizeStarted();
}

cef_text_input_context_t CEF_CALLBACK browser_host_get_nstext_input_context(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  cef_text_input_context_t _retval = CefBrowserHostCppToC::Get(
      self)->GetNSTextInputContext();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK browser_host_handle_key_event_before_text_input_client(
    struct _cef_browser_host_t* self, cef_event_handle_t keyEvent) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->HandleKeyEventBeforeTextInputClient(
      keyEvent);
}

void CEF_CALLBACK browser_host_handle_key_event_after_text_input_client(
    struct _cef_browser_host_t* self, cef_event_handle_t keyEvent) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->HandleKeyEventAfterTextInputClient(
      keyEvent);
}

void CEF_CALLBACK browser_host_drag_target_drag_enter(
    struct _cef_browser_host_t* self, struct _cef_drag_data_t* drag_data,
    const struct _cef_mouse_event_t* event,
    cef_drag_operations_mask_t allowed_ops) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: drag_data; type: refptr_same
  DCHECK(drag_data);
  if (!drag_data)
    return;
  // Verify param: event; type: struct_byref_const
  DCHECK(event);
  if (!event)
    return;

  // Translate param: event; type: struct_byref_const
  CefMouseEvent eventObj;
  if (event)
    eventObj.Set(*event, false);

  // Execute
  CefBrowserHostCppToC::Get(self)->DragTargetDragEnter(
      CefDragDataCppToC::Unwrap(drag_data),
      eventObj,
      allowed_ops);
}

void CEF_CALLBACK browser_host_drag_target_drag_over(
    struct _cef_browser_host_t* self, const struct _cef_mouse_event_t* event,
    cef_drag_operations_mask_t allowed_ops) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: event; type: struct_byref_const
  DCHECK(event);
  if (!event)
    return;

  // Translate param: event; type: struct_byref_const
  CefMouseEvent eventObj;
  if (event)
    eventObj.Set(*event, false);

  // Execute
  CefBrowserHostCppToC::Get(self)->DragTargetDragOver(
      eventObj,
      allowed_ops);
}

void CEF_CALLBACK browser_host_drag_target_drag_leave(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->DragTargetDragLeave();
}

void CEF_CALLBACK browser_host_drag_target_drop(
    struct _cef_browser_host_t* self, const struct _cef_mouse_event_t* event) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: event; type: struct_byref_const
  DCHECK(event);
  if (!event)
    return;

  // Translate param: event; type: struct_byref_const
  CefMouseEvent eventObj;
  if (event)
    eventObj.Set(*event, false);

  // Execute
  CefBrowserHostCppToC::Get(self)->DragTargetDrop(
      eventObj);
}

void CEF_CALLBACK browser_host_drag_source_ended_at(
    struct _cef_browser_host_t* self, int x, int y,
    cef_drag_operations_mask_t op) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->DragSourceEndedAt(
      x,
      y,
      op);
}

void CEF_CALLBACK browser_host_drag_source_system_drag_ended(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->DragSourceSystemDragEnded();
}

void CEF_CALLBACK browser_host_composite(struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->Composite();
}

void CEF_CALLBACK browser_host_initialize_compositing(
    struct _cef_browser_host_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserHostCppToC::Get(self)->InitializeCompositing();
}


// CONSTRUCTOR - Do not edit by hand.

CefBrowserHostCppToC::CefBrowserHostCppToC(CefBrowserHost* cls)
    : CefCppToC<CefBrowserHostCppToC, CefBrowserHost, cef_browser_host_t>(cls) {
  struct_.struct_.get_browser = browser_host_get_browser;
  struct_.struct_.close_browser = browser_host_close_browser;
  struct_.struct_.set_focus = browser_host_set_focus;
  struct_.struct_.set_window_visibility = browser_host_set_window_visibility;
  struct_.struct_.get_window_handle = browser_host_get_window_handle;
  struct_.struct_.get_opener_window_handle =
      browser_host_get_opener_window_handle;
  struct_.struct_.get_client = browser_host_get_client;
  struct_.struct_.get_request_context = browser_host_get_request_context;
  struct_.struct_.get_zoom_level = browser_host_get_zoom_level;
  struct_.struct_.set_zoom_level = browser_host_set_zoom_level;
  struct_.struct_.run_file_dialog = browser_host_run_file_dialog;
  struct_.struct_.start_download = browser_host_start_download;
  struct_.struct_.print = browser_host_print;
  struct_.struct_.find = browser_host_find;
  struct_.struct_.stop_finding = browser_host_stop_finding;
  struct_.struct_.show_dev_tools = browser_host_show_dev_tools;
  struct_.struct_.close_dev_tools = browser_host_close_dev_tools;
  struct_.struct_.set_mouse_cursor_change_disabled =
      browser_host_set_mouse_cursor_change_disabled;
  struct_.struct_.is_mouse_cursor_change_disabled =
      browser_host_is_mouse_cursor_change_disabled;
  struct_.struct_.replace_misspelling = browser_host_replace_misspelling;
  struct_.struct_.add_word_to_dictionary = browser_host_add_word_to_dictionary;
  struct_.struct_.is_window_rendering_disabled =
      browser_host_is_window_rendering_disabled;
  struct_.struct_.was_resized = browser_host_was_resized;
  struct_.struct_.was_hidden = browser_host_was_hidden;
  struct_.struct_.notify_screen_info_changed =
      browser_host_notify_screen_info_changed;
  struct_.struct_.invalidate = browser_host_invalidate;
  struct_.struct_.send_key_event = browser_host_send_key_event;
  struct_.struct_.send_mouse_click_event = browser_host_send_mouse_click_event;
  struct_.struct_.send_mouse_move_event = browser_host_send_mouse_move_event;
  struct_.struct_.send_mouse_wheel_event = browser_host_send_mouse_wheel_event;
  struct_.struct_.send_focus_event = browser_host_send_focus_event;
  struct_.struct_.send_capture_lost_event =
      browser_host_send_capture_lost_event;
  struct_.struct_.notify_move_or_resize_started =
      browser_host_notify_move_or_resize_started;
  struct_.struct_.get_nstext_input_context =
      browser_host_get_nstext_input_context;
  struct_.struct_.handle_key_event_before_text_input_client =
      browser_host_handle_key_event_before_text_input_client;
  struct_.struct_.handle_key_event_after_text_input_client =
      browser_host_handle_key_event_after_text_input_client;
  struct_.struct_.drag_target_drag_enter = browser_host_drag_target_drag_enter;
  struct_.struct_.drag_target_drag_over = browser_host_drag_target_drag_over;
  struct_.struct_.drag_target_drag_leave = browser_host_drag_target_drag_leave;
  struct_.struct_.drag_target_drop = browser_host_drag_target_drop;
  struct_.struct_.drag_source_ended_at = browser_host_drag_source_ended_at;
  struct_.struct_.drag_source_system_drag_ended =
      browser_host_drag_source_system_drag_ended;
  struct_.struct_.composite = browser_host_composite;
  struct_.struct_.initialize_compositing = browser_host_initialize_compositing;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefBrowserHostCppToC, CefBrowserHost,
    cef_browser_host_t>::DebugObjCt = 0;
#endif

