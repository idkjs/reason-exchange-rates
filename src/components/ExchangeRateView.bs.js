// Generated by BUCKLESCRIPT VERSION 5.0.0-dev.4, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Text$BsReactNative = require("bs-react-native/src/components/text.js");
var View$BsReactNative = require("bs-react-native/src/components/view.js");
var Style$BsReactNative = require("bs-react-native/src/style.js");
var Utils$ReactTemplate = require("../utils/Utils.bs.js");
var Colors$ReactTemplate = require("../styles/Colors.bs.js");
var FxList$ReactTemplate = require("./FxList.bs.js");
var StyleSheet$BsReactNative = require("bs-react-native/src/styleSheet.js");

var styles = StyleSheet$BsReactNative.create({
      container: Style$BsReactNative.style(/* :: */[
            Style$BsReactNative.alignItems(/* Center */2),
            /* :: */[
              Style$BsReactNative.justifyContent(/* Center */2),
              /* :: */[
                Style$BsReactNative.flex(1),
                /* [] */0
              ]
            ]
          ]),
      heading: Style$BsReactNative.style(/* :: */[
            Style$BsReactNative.fontSize(/* Float */Block.__(0, [96])),
            /* :: */[
              Style$BsReactNative.fontWeight(/* _200 */1056006067),
              /* :: */[
                Style$BsReactNative.color(/* String */Block.__(0, [Colors$ReactTemplate.white])),
                /* :: */[
                  Style$BsReactNative.letterSpacing(6),
                  /* [] */0
                ]
              ]
            ]
          ])
    });

var component = ReasonReact.reducerComponent("ExchangeRateView");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Caml_option.some(styles.container), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                              ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Caml_option.some(styles.heading), undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* array */[Utils$ReactTemplate.s("1 " + self[/* state */1][/* currency */0])])),
                              ReasonReact.element(undefined, undefined, FxList$ReactTemplate.make(self[/* state */1][/* currency */0], (function (currency) {
                                          return Curry._1(self[/* send */3], /* OnCurrencyChange */[currency]);
                                        }), /* array */[]))
                            ]));
            }),
          /* initialState */(function (param) {
              return /* record */[/* currency */"USD"];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _state) {
              return /* Update */Block.__(0, [/* record */[/* currency */action[0]]]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.styles = styles;
exports.component = component;
exports.make = make;
/* styles Not a pure module */
