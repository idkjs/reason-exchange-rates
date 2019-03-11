open BsReactNative;
open Utils;
module Styles = {
  let styles =
    StyleSheet.create(
      Style.{
        "container": style([width(Pct(100.)), padding(Pt(20.))]),
        "currencyWrapper":
          style([
            padding(Pt(20.)),
            flexDirection(Row),
            justifyContent(SpaceBetween),
            alignItems(Center),
            borderBottomWidth(1.),
            borderBottomColor(String(Colors.teal)),
          ]),
        "currency":
          style([
            fontSize(Float(64.)),
            fontWeight(`_100),
            color(String(Colors.grey)),
            letterSpacing(4.),
          ]),
      },
    );
};

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


let component = ReasonReact.statelessComponent("FxList");

let make = (~currency, ~onCurrencyChange, _children) => {
  ...component,
  render: _self => {
    let exchangeRateQuery =
      ExchangeRateQuery.make(
        ~currency,
        (),
      );
    <FxQuery variables=exchangeRateQuery##variables>
      ...{({result}) =>
        switch (result) {
        | Loading => <ActivityIndicator color=String(Colors.teal) />
        | Error(_e) => <Text> {"Error:" |> ReasonReact.string} </Text>
        | Data(response) =>
        switch(response##rates) {
          | None => <Text> {"Loading" |> ReasonReact.string} </Text>
          | Some(rates) =>
               let realMatches = rates->Belt.Array.keepMap(match => match);
              let decodedFx:array(Currency.t) = Currency.json(realMatches);
              let renderItem = ({currency, rate}:Currency.t) =>
                  <TouchableOpacity key=currency accessibilityLabel="button"
                  onPress={_e => onCurrencyChange(currency)}
                  style=Styles.styles##currencyWrapper>
                    <Text style=Styles.styles##currency>
                    currency->s
                    </Text>
                    <Text style=Styles.styles##currency>
                    rate->s
                    </Text>
                  </TouchableOpacity>;
              let filterFx = (item:Currency.t) => switch(item.currency) {
                | "USD" | "EUR"| "BTC" | "LTC" | "JPY" | "ETH" => (currency !== item.currency) ? renderItem(item) : ReasonReact.null
                | _ => ReasonReact.null;
              };
              <View style=Styles.styles##container>
               {
                 Belt.Array.map((decodedFx), x => filterFx(x)) |> ReasonReact.array
                 }
               </View>

        }}
      }
    </FxQuery>;
  },
};