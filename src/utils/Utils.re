let s = ReasonReact.string;

let nullableStringToElement = obj =>
  (
    switch (obj) {
    | None => "No data"
    | Some(str) => str
    }
  )
  |> s;

let filter = (~f, list) => list |> ListLabels.filter(~f);
let find = (~f, list) => list |> ListLabels.find(~f);
