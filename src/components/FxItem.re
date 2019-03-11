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
            fontSize(Float(32.)),
            fontWeight(`_100),
            color(String(Colors.grey)),
            letterSpacing(4.),
          ]),
      },
    );
};
let component = ReasonReact.statelessComponent("FxItem");

let make = (~item, _children) => {
  ...component,
  render: (_self) =>
  <View>
    <Text style=Styles.styles##currency>{item##currency ->nullableStringToElement}</Text>
    <Text style=Styles.styles##currency>{item##rate ->nullableStringToElement}</Text>
  </View>
};