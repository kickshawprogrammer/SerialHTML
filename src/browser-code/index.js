var gateway = `ws://${window.location.hostname}/webserialws`;
var websocket;

initWebPage();

function initWebPage() {
  initWebSocket();
  initButton();
  trapEnterKeyPress();
}

function initWebSocket() {
  console.log('Trying to open a WebSocket connection...');
  
  websocket = new WebSocket(gateway);
  websocket.onopen    = onOpen;
  websocket.onclose   = onClose;
  websocket.onmessage = onMessage;
}

function initButton() {
  document.getElementById('command-button').addEventListener('click', sendCommand);
}

function trapEnterKeyPress() {
  document.getElementById('command-button').addEventListener('keypress', enterPressed);
  document.getElementById('command-text').addEventListener('keypress', enterPressed);
  document.getElementById('command-data').addEventListener('keypress', enterPressed);
}

function enterPressed(event) {
  if (event.key === 'Enter') {
    event.preventDefault();
	document.getElementById('command-button').click();
  }
}

function onOpen(event) {
  console.log('Connection opened');
}

function onClose(event) {
  console.log('Connection closed');
  setTimeout(initWebSocket, 2000);
}

function onMessage(event) {
  console.log('Data Received:');
  console.log(event.data);
  
  var textArea = document.getElementById('command-data');
  textArea.value += event.data;
  textArea.scrollTop = textArea.scrollHeight;
}

function sendCommand(){
  websocket.send(document.getElementById('command-text').value);
}

