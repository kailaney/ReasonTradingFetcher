'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

function FetchData(Props) {
  var match = React.useState(function () {
        return /* NotLoadedData */0;
      });
  var setFetched = match[1];
  var match$1 = React.useState(function () {
        return [];
      });
  var setData = match$1[1];
  var match$2 = React.useState(function () {
        return "";
      });
  var setTicker = match$2[1];
  var ticker = match$2[0];
  var match$3 = React.useState(function () {
        return "";
      });
  var setCompany = match$3[1];
  var match$4 = React.useState(function () {
        return "";
      });
  var setChart = match$4[1];
  var onSubmit = function (e) {
    e.preventDefault();
    fetch("https://cloud.iexapis.com/stable/stock/" + (ticker + "/quote?token=pk_d487e77ce9834ee0a867b040d38f795a")).then(function (response) {
              return response.json();
            }).then(function (jsonResponse) {
            if (jsonResponse.hasOwnProperty("symbol")) {
              Curry._1(setFetched, (function (_previousState) {
                      return /* LoadedData */2;
                    }));
              Curry._1(setCompany, (function (_previousState) {
                      return jsonResponse.companyName;
                    }));
              if (jsonResponse.isUSMarketOpen) {
                Curry._1(setData, (function (_previousState) {
                        return [
                                "Market Cap: " + jsonResponse.marketCap,
                                "Price: " + jsonResponse.latestPrice,
                                "Volume: " + jsonResponse.latestVolume,
                                "Low: " + jsonResponse.low,
                                "High: " + jsonResponse.high,
                                "PE Ratio: " + jsonResponse.peRatio,
                                "Bid Price: " + jsonResponse.iexBidPrice,
                                "Bid Size: " + jsonResponse.iexBidSize,
                                "Ask Price: " + jsonResponse.iexAskPrice,
                                "Ask Size: " + jsonResponse.iexAskSize
                              ];
                      }));
              } else {
                Curry._1(setData, (function (_previousState) {
                        return [
                                "Market Cap: " + jsonResponse.marketCap,
                                "Price: " + jsonResponse.latestPrice,
                                "Volume: " + jsonResponse.latestVolume,
                                "Low: " + jsonResponse.low,
                                "High: " + jsonResponse.high,
                                "PE Ratio: " + jsonResponse.peRatio
                              ];
                      }));
              }
              Curry._1(setChart, (function (_previousState) {
                      return "https://stockcharts.com/c-sc/sc?s=" + (ticker + "&p=D&b=5&g=0&i=0&r=1607054908229");
                    }));
            } else {
              Curry._1(setFetched, (function (_previousState) {
                      return /* ErrorFetchingData */1;
                    }));
            }
            return Promise.resolve(undefined);
          }).catch(function (_err) {
          Curry._1(setFetched, (function (_previousState) {
                  return /* ErrorFetchingData */1;
                }));
          return Promise.resolve(undefined);
        });
    
  };
  var tmp;
  switch (match[0]) {
    case /* NotLoadedData */0 :
        tmp = "Search for a company";
        break;
    case /* ErrorFetchingData */1 :
        tmp = "Error Loading Data!";
        break;
    case /* LoadedData */2 :
        tmp = React.createElement("div", undefined, React.createElement("h1", undefined, match$3[0]), React.createElement("ul", undefined, Belt_Array.map(match$1[0], (function (value) {
                        return React.createElement("li", undefined, value);
                      }))), React.createElement("div", {
                  className: "parent"
                }, React.createElement("div", {
                      className: "lalign"
                    }, React.createElement("a", {
                          href: match$4[0],
                          target: "_blank"
                        }, "MACD")), React.createElement("div", {
                      className: "ralign"
                    }, React.createElement("a", {
                          href: "https://robinhood.com/us/en/",
                          target: "_blank"
                        }, "Robinhood"))));
        break;
    
  }
  return React.createElement("div", undefined, React.createElement("form", {
                  onSubmit: onSubmit
                }, React.createElement("input", {
                      className: "input",
                      id: "ticker",
                      name: "ticker",
                      placeholder: "Ticker",
                      type: "text",
                      value: ticker,
                      onChange: (function (e) {
                          return Curry._1(setTicker, e.target.value.toLowerCase());
                        })
                    }), React.createElement("button", {
                      type: "submit"
                    }, "Fetch")), tmp);
}

var make = FetchData;

exports.make = make;
/* react Not a pure module */
