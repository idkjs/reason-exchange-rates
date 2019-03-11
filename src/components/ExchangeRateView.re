open BsReactNative;
open Utils;
let styles = StyleSheet.create(
    Style.{
    "container": style([
      alignItems(Center),
      justifyContent(Center),
      flex(1.),
      ]),
    "heading": style([
      fontSize(Float(96.)),
      fontWeight(`_200),
      color(String(Colors.white)),
      letterSpacing(6.)
    ]),
});

type state = {
  currency:string
};
type action = | OnCurrencyChange(string);

let component = ReasonReact.reducerComponent("ExchangeRateView");
let make = (_children) => {
  ...component,
  initialState: () => {currency: "USD"},
  reducer: (action, _state) =>
  switch action {
    | OnCurrencyChange(text) => ReasonReact.Update({currency:text})
},
  render: (self) =>
   <View style=styles##container>
        <Text style=styles##heading>
          ("1 " ++ self.state.currency)->s
        </Text>
        <FxList
          currency=self.state.currency
          onCurrencyChange={currency =>  self.send(OnCurrencyChange(currency))}
        />
      </View>
};