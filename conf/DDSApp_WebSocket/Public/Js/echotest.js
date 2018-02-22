/* chotest.js
 *
 * Derived from Echo Test of WebSocket.org (http://www.websocket.org/echo.html).
 *
 * Copyright (c) 2012 Kaazing Corporation.
 */

var url = "ws://10.40.81.76:4649/DGWFactoryWarRoom/v1";
//var url = "ws://127.0.0.1:8080/Echo";
//var url = "ws://10.40.81.76:4649/Echo";//?name=MyNameStsven";
//var url = "wss://127.0.0.1:5963/Echo";
var output;

function init () {
  //alert(1);
  output = document.getElementById ("output");
  //alert(2);
  doWebSocket ();
  //alert(3);
}

function doWebSocket () 
{
  websocket = new WebSocket (url);

  websocket.onopen = function (e) {
    onOpen (e);
  };

  websocket.onmessage = function (e) {
    onMessage (e);
  };

  websocket.onerror = function (e) {
    onError (e);
  };

  websocket.onclose = function (e) {
    onClose (e);
  };
}

function onOpen (event) {
  writeToScreen ("CONNECTED");
  
  send ("{ event_type:'0,1,2', event_object:'MU-145' }");
  //send ("WebSocket rocks");
}

function onMessage (event) {
  writeToScreen ('<span style="color: blue;">RESPONSE: ' + event.data + '</span>');
  //websocket.close ();
}

function onError (event) {
  writeToScreen ('<span style="color: red;">ERROR: ' + event.data + '</span>');
}

function onClose (event) {
  writeToScreen ("DISCONNECTED");
}

function send (message) {
  writeToScreen ("SENT: " + message);
  websocket.send (message);
}

//var outputP;

function writeToScreen (message) 
{
  var pre = document.getElementById ("outputP");
  
  if (!pre) 
  {
    console.log('1');
    
    pre = document.createElement ("p");
    pre.id = 'outputP';
    pre.style.wordWrap = "break-word";
    pre.innerHTML = message;
    output.appendChild (pre);
  }
  else
  {
    console.log('2');
    console.log(message);
    
    pre.innerHTML = message;
  }
  
  //var pre = document.createElement ("p");
  //pre.id = 'outputP';
  //pre.style.wordWrap = "break-word";
  //pre.innerHTML = message;
  //output.appendChild (pre);
}

window.addEventListener ("load", init, false);
