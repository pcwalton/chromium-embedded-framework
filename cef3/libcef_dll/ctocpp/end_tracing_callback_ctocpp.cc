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

#include "libcef_dll/ctocpp/end_tracing_callback_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

void CefEndTracingCallbackCToCpp::OnEndTracingComplete(
    const CefString& tracing_file) {
  if (CEF_MEMBER_MISSING(struct_, on_end_tracing_complete))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: tracing_file; type: string_byref_const
  DCHECK(!tracing_file.empty());
  if (tracing_file.empty())
    return;

  // Execute
  struct_->on_end_tracing_complete(struct_,
      tracing_file.GetStruct());
}


#ifndef NDEBUG
template<> base::AtomicRefCount CefCToCpp<CefEndTracingCallbackCToCpp,
    CefEndTracingCallback, cef_end_tracing_callback_t>::DebugObjCt = 0;
#endif

