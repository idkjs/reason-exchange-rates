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
        "currencyWrapperWithoutBorder":
          style([
            padding(Pt(20.)),
            flexDirection(Row),
            justifyContent(SpaceBetween),
            alignItems(FlexStart),
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
    let exchangeRateQuery = ExchangeRateQuery.make(~currency, ());
    <FxQuery variables=exchangeRateQuery##variables>
      ...{({result}) =>
        switch (result) {
        | Loading => <ActivityIndicator color={String(Colors.teal)} />
        | Error(_e) => <Text> {"Error:" |> ReasonReact.string} </Text>
        | Data(response) =>
          switch (response##rates) {
          | None => <Text> {"Loading" |> ReasonReact.string} </Text>
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

            let renderItem = (index,{currency, rate}: Currency.t) =>{
              Js.log2(currency,index);
              <TouchableOpacity
                key=currency
                accessibilityLabel="button"
                onPress={_e => onCurrencyChange(currency)}
                style={
                  index == 3 ?
                    Styles.styles##currencyWrapperWithoutBorder :
                    Styles.styles##currencyWrapper
                }>
                <Text style=Styles.styles##currency> currency->s </Text>
                <Text style=Styles.styles##currency> rate->s </Text>
              </TouchableOpacity>};
            let filterFx = (index,item: Currency.t) =>
              switch (item.currency) {
              | "USD"
              | "EUR"
              | "BTC"
              | "LTC"
              | "JPY"
              | "ETH" =>
                currency !== item.currency ?
                  renderItem(index, item) : ReasonReact.null
              | _ => ReasonReact.null
              };
            <View style=Styles.styles##container>
                {decodedFx->Belt.Array.mapWithIndex(filterFx)->ReasonReact.array}
            </View>;
          }
        }
      }
    </FxQuery>;
  },
};
