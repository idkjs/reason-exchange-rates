open ReactNative;
open Utils;
module Styles = {
  let styles =
    Style.(
      StyleSheet.create({
        "container":
          style(
            ~width=100.->pct,
            ~flex=1.,
            ~justifyContent=`center,
            ~alignItems=`center,
            ~backgroundColor="#F5FCFF",
            (),
          ),
        "currencyWrapper":
          style(
            ~padding=20.->dp,
            ~flexDirection=`row,
            ~justifyContent=`spaceBetween,
            ~alignItems=`center,
            ~borderBottomWidth=1.,
            ~borderBottomColor=Colors.teal,
            (),
          ),
        "currencyWrapperWithoutBorder":
          style(
            ~padding=20.->dp,
            ~flexDirection=`row,
            ~justifyContent=`spaceBetween,
            ~alignItems=`flexStart,
            (),
          ),
        "currency":
          style(
            ~fontSize=64.,
            ~fontWeight=`_100,
            ~color=Colors.grey,
            ~letterSpacing=4.,
            (),
          ),
        "welcome":
          style(~fontSize=20., ~textAlign=`center, ~margin=10.->dp, ()),
        "instructions":
          style(
            ~textAlign=`center,
            ~color="#333333",
            ~marginBottom=5.->dp,
            (),
          ),
      })
    );
};
// StyleSheet.create(
//   Style.{
//     "container": style(width(Pct(100.)), padding(Pt(20.))),
//     "currencyWrapper":
//       style(
//         padding(Pt(20.)),
//         flexDirection(Row),
//         justifyContent(SpaceBetween),
//         alignItems(Center),
//         borderBottomWidth(1.),
//         borderBottomColor(String(Colors.teal)),
//       ),
//     "currencyWrapperWithoutBorder":
//       style(
//         padding(Pt(20.)),
//         flexDirection(Row),
//         justifyContent(SpaceBetween),
//         alignItems(FlexStart),
//       ),
//     "currency":
//       style(
//         fontSize(Float(64.)),
//         fontWeight(`_100),
//         color(String(Colors.grey)),
//         letterSpacing(4.),
//       ),
//   },
// );

module ExchangeRateQuery = [%graphql
  {|
  query rates($currency: String!) {
    rates(currency: $currency) {
      currency
      rate
    }
  }
|}
];

module FxQuery = ReasonApollo.CreateQuery(ExchangeRateQuery);

[@react.component]
let make = (~currency, ~onCurrencyChange) => {
  let exchangeRateQuery = ExchangeRateQuery.make(~currency, ());
  <FxQuery variables=exchangeRateQuery##variables>
    ...{({result}) =>
      switch (result) {
      | Loading => <ActivityIndicator color=Colors.teal />
      | Error(_e) => <Text> {"Error:" |> React.string} </Text>
      | Data(response) =>
        switch (response##rates) {
        | None => <Text> {"Loading" |> React.string} </Text>
        | Some(rates) =>
          let realMatches = rates->Belt.Array.keepMap(match => match);
          let decodedFx: array(Currency.t) = Currency.json(realMatches);
          let filterFxRaw = (item: Currency.t) =>
            switch (item.currency) {
            | "USD"
            | "EUR"
            | "BTC"
            | "LTC"
            | "JPY"
            | "ETH" => Some(item)
            | _ => None
            };
          // let filteredFx = decodedFx->Belt.Array.map(filterFxRaw);
          // let filteredFxWithIndex = filteredFx->Belt.Array.mapWithIndex;

          let renderItem = (index, {currency, rate}: Currency.t) => {
            Js.log2(currency, index);
            <TouchableOpacity
              key=currency
              accessibilityLabel="button"
              onPress={_e => onCurrencyChange(currency)}
              style={
                index == 3
                  ? Styles.styles##currencyWrapperWithoutBorder
                  : Styles.styles##currencyWrapper
              }>
              <Text style=Styles.styles##currency> currency->s </Text>
              <Text style=Styles.styles##currency> rate->s </Text>
            </TouchableOpacity>;
          };
          let filterFx = (index, item: Currency.t) =>
            switch (item.currency) {
            | "USD"
            | "EUR"
            | "BTC"
            | "LTC"
            | "JPY"
            | "ETH" =>
              currency !== item.currency
                ? renderItem(index, item) : React.null
            | _ => React.null
            };
          <View style=Styles.styles##container>
            {decodedFx->Belt.Array.mapWithIndex(filterFx)->React.array}
          </View>;
        }
      }
    }
  </FxQuery>;
};