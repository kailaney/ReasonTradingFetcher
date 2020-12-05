

// The {j|...|j} feature is just string interpolation, from
// bucklescript.github.io/docs/en/interop-cheatsheet#string-unicode-interpolation
// This allows us to conveniently write CSS, together with variables, by
// constructing a string
let style = {j|
  body {
    background-color: #2F4F4F;
    display: flex;
    flex-direction: column;
    align-items: center;
  }
  button {
    background-color: white;
    color: black;
    padding: 8px;
    position: center;
    border: 2px solid #2F4F4F;
    border-radius: 3px;
    margin: auto;
    margin-top: 5px;
    display: block;
    font-size: 16px;
  }
  input{
    width: 25%;
    font-size: 20px;
    padding: 10px;
    border: 1px solid #2F4F4F;
    border-radius: 10px;
    display: block;
    margin: auto;
    position: center;
  }
  ::placeholder {
    color: gray;
    font-size: 15px;
    text-align: left;
  }
  .parent {
    display: flex;
  }
  .lalign {
    margin-left: 65%;
    margin-right: 5px;
  }
  .ralign {
    flex-grow: 1;
  }
  li {
    margin: 10px 0;
  }
  a:link, a:visited {
    background-color: white;
    border: 1px solid #2F4F4F;
    color: black;
    padding: 14px 25px;
    text-align: center; 
    text-decoration: none;
    display: inline-block;
  }
  .container {
    margin: 12px 0px;
    box-shadow: 0px 4px 16px rgb(200, 200, 200);
    width: 720px;
    border-radius: 12px;
    font-family: sans-serif;
  }
  .containerTitle {
    background-color: rgb(242, 243, 245);
    border-radius: 12px 12px 0px 0px;
    padding: 12px;
    font-weight: bold;
  }
  .containerContent {
    background-color: white;
    padding: 16px;
    border-radius: 0px 0px 12px 12px;
  }
|j};
