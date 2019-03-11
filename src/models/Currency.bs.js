// Generated by BUCKLESCRIPT VERSION 5.0.0-dev.4, PLEASE EDIT WITH CARE
'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");

function decodeFx(json) {
  return /* record */[
          /* currency */Json_decode.field("currency", Json_decode.string, json),
          /* rate */Json_decode.field("rate", Json_decode.string, json)
        ];
}

function decodeFxs(json) {
  return Json_decode.array(decodeFx, json);
}

function json(json$1) {
  var json$2 = JSON.parse(Belt_Option.getExn(Caml_option.undefined_to_opt(JSON.stringify(json$1))));
  return Json_decode.array(decodeFx, json$2);
}

exports.decodeFx = decodeFx;
exports.decodeFxs = decodeFxs;
exports.json = json;
/* No side effect */