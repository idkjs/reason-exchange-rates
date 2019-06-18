open ReactNative;
open Utils;
let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(~flex=1., ~justifyContent=`center, ~alignItems=`center, ()),
      "heading":
        style(
          ~fontSize=96.,
          ~fontWeight=`_200,
          ~color=Colors.white,
          ~letterSpacing=6.,
          (),
        ),
    })
  );

type state = {currency: string};
type action =
  | OnCurrencyChange(string);

let initialState = {currency: "USD"};
let reducer = (_state, action) =>
  switch (action) {
  | OnCurrencyChange(text) => {currency: text}
  };
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  <View style=styles##container>
    <Text style=styles##heading> {("1 " ++ state.currency)->s} </Text>
    <FxList
      currency=state.currency
      onCurrencyChange={currency => dispatch(OnCurrencyChange(currency))}
    />
  </View>;
};