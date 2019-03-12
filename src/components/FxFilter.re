open Utils;

type fx =
  | USD
  | BTC
  | LTC
  | JPY
  | ETH
  | EUR;

let rates = (curr: fx): string => {
  switch (curr) {
  | USD => "USD"
  | BTC => "BTC"
  | LTC => "LTC"
  | JPY => "JPY"
  | ETH => "ETH"
  | EUR => "EUR"
  };
};
let filtered = (list:Currency.currencies) => Belt.List.reduce(list, Belt.Map.String.empty, (acc, p) => {
  Belt.Map.String.update(acc, p.currency, fun
    | None => Some([p])
    | Some(places) => switch (p.currency) {
    | "USD" | "EUR" | "BTC"
              | "LTC"
              | "JPY"
              | "ETH" => Some([p, ...places])
    }
  )
  }
);
