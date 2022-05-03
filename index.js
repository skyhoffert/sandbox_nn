
let websock = null;

document.getElementById("btn_tic-tac-toe").addEventListener("click",
function(evt)
{
  console.log("Pressed tic-tac-toe button.");
  
  websock.send("hi");

}, false);

websock = new WebSocket("ws://localhost:8001");

websock.onmessage = function(evt) {
  console.log(evt);
};
