// Entry point

[@bs.val] external document: Js.t({..}) = "document";


let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= Styles.style;

let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

ReactDOMRe.render(
  <FetchData />,
  makeContainer("Trading Data Fetcher"),
);
