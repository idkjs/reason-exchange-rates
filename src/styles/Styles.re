open BsReactNative;

module FontSize = {
  let large = "96px";
  let medium = "64px";
  let small = "32px";
};

  let styles =
    StyleSheet.create(
      Style.{
        "container":
          style([
            height(Pct(100.)),
            backgroundColor(String(Colors.darkBlue)),
          ]),
      },
    );
