
let websock = null;

let elm_status = document.getElementById("status");

document.getElementById("btn_debug").addEventListener("click",
function(evt)
{
  console.log("Pressed debug button.");
  
  websock.send("debug");

}, false);

let buttons = ["00", "01", "02", "10", "11", "12", "20", "21", "22"];
for (const btn of buttons) {
  let elm = document.getElementById(btn)
  elm.addEventListener("click",
  function (evt) {
    if (state != 0) {
      console.log("player tried to go not on their turn!");
      return;
    }
    state = 1;
    elm.innerHTML = "x";
    elm_status.innerHTML = "NN turn.";

    let msg = "bu:";
    for (const btn2 of buttons) {
      msg += document.getElementById(btn2).innerHTML;
    }
    websock.send(msg);
  }, false);
}

websock = new WebSocket("ws://localhost:8001");

websock.onmessage = function(evt) {
  console.log(evt.data);
};

///////////////////////////////////////////////////////////////////////////////
// Program.

let state = 0; // 0=player turn, 1=nn turn

