/*
 * This file is part of Espruino, a JavaScript interpreter for Microcontrollers
 *
 * Copyright (C) 2013 Gordon Williams <gw@pur3.co.uk>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * ----------------------------------------------------------------------------
 * JavaScript JSON-handling Functions
 * ----------------------------------------------------------------------------
 */
#include "jsvar.h"

JsVar *jswrap_json_stringify(JsVar *v, JsVar *replacer, JsVar *space);
JsVar *jswrap_json_parse(JsVar *v);

typedef enum {
  JSON_NONE,
  JSON_SOME_NEWLINES     = 1, //< insert newlines in non-simple arrays and objects
  JSON_ALL_NEWLINES      = 2, //< insert newlines after everything
  JSON_PRETTY            = 4, //< insert extra spaces between commas
  JSON_LIMIT             = 8, //< limit the amount we print (for the console)
  JSON_IGNORE_FUNCTIONS  = 16, //< don't output functions
  JSON_SHOW_DEVICES      = 32, //< Show built-in device names like SPI/etc
  JSON_NO_UNDEFINED      = 64, //< don't output undefined keys in objects, and use null for undefined in arrays
  JSON_ARRAYBUFFER_AS_ARRAY = 128, //< dump arraybuffers as arrays
  JSON_SHOW_OBJECT_NAMES    = 256, //< Show 'Promise {}'/etc for objects if the type is global
  JSON_DROP_QUOTES       = 512, //< When outputting objects, drop quotes for alphanumeric field names
  JSON_UNICODE_ESCAPE    = 1024, //< Only use unicode for escape characters - needed for JSON compatibility
  // ...
  JSON_INDENT            = 2048, // MUST BE THE LAST ENTRY IN JSONFlags - we use this to count the amount of indents
} JSONFlags;

/* This is like jsfGetJSONWithCallback, but handles ONLY functions (and does not print the initial 'function' text) */
void jsfGetJSONForFunctionWithCallback(JsVar *var, JSONFlags flags, vcbprintf_callback user_callback, void *user_data);
/* Dump to JSON, using the given callbacks for printing data */
void jsfGetJSONWithCallback(JsVar *var, JSONFlags flags, const char *whitespace, vcbprintf_callback user_callback, void *user_data);

/* Convenience function for using jsfGetJSONWithCallback - print to var */
void jsfGetJSONWhitespace(JsVar *var, JsVar *result, JSONFlags flags, const char *whitespace);
/* Convenience function for using jsfGetJSONWithCallback - print to var */
void jsfGetJSON(JsVar *var, JsVar *result, JSONFlags flags);

/* Convenience function for using jsfGetJSONWithCallback - print to console */
void jsfPrintJSON(JsVar *var, JSONFlags flags);
/* Convenience function for using jsfGetJSONForFunctionWithCallback - print to console */
void jsfPrintJSONForFunction(JsVar *var, JSONFlags flags);
