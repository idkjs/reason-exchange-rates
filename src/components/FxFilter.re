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
