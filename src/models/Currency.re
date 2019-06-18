type t = {
  currency: string,
  rate: string,
};

type currencies = list(t);

let decodeFx = json =>
  Json.Decode.{
    currency: json |> field("currency", string),
    rate: json |> field("rate", string),
  };
let decodeFxs = json => Json.Decode.array(decodeFx, json);
let json = json =>
  json->Js.Json.stringifyAny->Belt.Option.getExn->Js.Json.parseExn->decodeFxs;
