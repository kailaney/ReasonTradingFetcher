[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";


type fetched =
  | NotLoadedData
  | ErrorFetchingData
  | LoadedData;

[@react.component]
let make = () => {
  let (fetched, setFetched) = React.useState(() => NotLoadedData);
  let (data, setData) = React.useState(() => [||]);
  let (ticker, setTicker) = React.useState(() => "");
  let (company, setCompany) = React.useState(() => "");
  let (chart, setChart) = React.useState(() => "");
  let apiKey = "pk_d487e77ce9834ee0a867b040d38f795a";

  let onSubmit = (e: ReactEvent.Form.t): unit => {
    ReactEvent.Form.preventDefault(e);
    Js.Promise.(
      fetch("https://cloud.iexapis.com/stable/stock/" ++ ticker ++ "/quote?token=" ++ apiKey)
      |> then_(response => response##json())
      |> then_(jsonResponse => {
          if(jsonResponse##hasOwnProperty("symbol")){
          setFetched(_previousState => LoadedData);
          setCompany(_previousState => jsonResponse##companyName);
          if(jsonResponse##isUSMarketOpen){
            setData(_previousState => [|"Market Cap: " ++ jsonResponse##marketCap, "Price: " ++ jsonResponse##latestPrice, "Volume: " ++ jsonResponse##latestVolume, "Low: " ++ jsonResponse##low, "High: " ++ jsonResponse##high,  "PE Ratio: " ++ jsonResponse##peRatio, "Bid Price: " ++ jsonResponse##iexBidPrice, "Bid Size: " ++ jsonResponse##iexBidSize, "Ask Price: " ++ jsonResponse##iexAskPrice, "Ask Size: " ++ jsonResponse##iexAskSize|]);
          }
          else{
            setData(_previousState => [|"Market Cap: " ++ jsonResponse##marketCap, "Price: " ++ jsonResponse##latestPrice, "Volume: " ++ jsonResponse##latestVolume, "Low: " ++ jsonResponse##low, "High: " ++ jsonResponse##high,  "PE Ratio: " ++ jsonResponse##peRatio|]);
          }
          setChart(_previousState => "https://stockcharts.com/c-sc/sc?s=" ++ ticker ++ "&p=D&b=5&g=0&i=0&r=1607054908229");
          }else{
            setFetched(_previousState => ErrorFetchingData);
          }
          Js.Promise.resolve();
      })
      |> catch(_err => {
          setFetched(_previousState => ErrorFetchingData);
           Js.Promise.resolve();
      })
      |> ignore
    );
  };

  <div>
  <form onSubmit>
  <input className="input" type_="text" id="ticker" placeholder	="Ticker" name="ticker" value=ticker onChange={
    e => {
      setTicker(ReactEvent.Form.target(e)##value##toLowerCase());
    }
  } />
  <button type_="submit"> {React.string("Fetch")} </button>
  </form>

  {switch (fetched) {
    | NotLoadedData => React.string("Search for a company")
    | ErrorFetchingData => React.string("Error Loading Data!")
    | LoadedData => 
      <div>
        <h1> (React.string(company)) </h1>
        <ul>
          (
            data
            ->Belt.Array.map((value) => {
              <li>{React.string(value)}</li>;
            })
            ->React.array
          )
        </ul>
        <div className="parent">
          <div className="lalign">
            <a href={chart} target="_blank">(React.string("MACD"))</a>
          </div>
          <div className="ralign">
            <a href="https://robinhood.com/us/en/" target="_blank">(React.string("Robinhood"))</a>
          </div>
        </div>
      </div>
      
    }
  }
  </div>;
};


