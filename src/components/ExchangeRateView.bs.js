// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReactNative = require("react-native");
var Utils$ReactTemplate = require("../utils/Utils.bs.js");
var Colors$ReactTemplate = require("../styles/Colors.bs.js");
var FxList$ReactTemplate = require("./FxList.bs.js");

var styles = ReactNative.StyleSheet.create({
      container: {
        alignItems: "center",
        flex: 1,
        justifyContent: "center"
      },
      heading: {
        color: Colors$ReactTemplate.white,
        fontSize: 96,
        fontWeight: "200",
        letterSpacing: 6
      }
    });

var initialState = /* record */[/* currency */"USD"];

function reducer(_state, action) {
  return /* record */[/* currency */action[0]];
}

function ExchangeRateView(Props) {
  var match = React.useReducer(reducer, initialState);
  var dispatch = match[1];
  var state = match[0];
  return React.createElement(ReactNative.View, {
              style: styles.container,
              children: null
            }, React.createElement(ReactNative.Text, {
                  style: styles.heading,
                  children: Utils$ReactTemplate.s("1 " + state[/* currency */0])
                }), React.createElement(FxList$ReactTemplate.make, {
                  currency: state[/* currency */0],
                  onCurrencyChange: (function (currency) {
                      return Curry._1(dispatch, /* OnCurrencyChange */[currency]);
                    })
                }));
}

var make = ExchangeRateView;

exports.styles = styles;
exports.initialState = initialState;
exports.reducer = reducer;
exports.make = make;
/* styles Not a pure module */
