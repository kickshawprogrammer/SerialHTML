// NOTE: Cut & Paste copied directly from the browser-code/index.html file
//
//       char index_html[] PROGMEM = R"=====(
//          ...
//          ALL THIS DATA IS COPIED DIRECTLY IN FROM THE SOURCE FILE
//          ...
//        )====="; 
//
// In this way, I can make changes to the web-page interface, test it on
// my desktop/laptop to make sure it looks/feels the way I want before
// uploading the changes to the device. For me, this simplifies things
//
//------------------------------------------------------------------------------
//  Feel free to use in any way you wish; but please, be kind and do good!
//------------------------------------------------------------------------------
#include <pgmspace.h>

namespace serial_html_ns {

  char index_html[] PROGMEM = R"=====(
    <!DOCTYPE html>
    <html>
      <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="mobile-web-app-capable" content="yes">
        <title>HTML Serial Monitor</title>
        <link rel="stylesheet" type="text/css" href="serial_index.css">
        <script type="application/javascript" src="serial_index.js" defer></script>
      </head>
      
      <body class="centered-wrapper">
        <h1>HTML Serial Monitor</h1>
      
        <form>
          <table width="95%" height="10%">
            <tr>
              <td><input id="command-text" type="text" value="Type here" size="40" align="left"></td>
              <td><input id="command-button" type="button" value="Send" align="right" autofocus></td>
            </tr>
        </table class="table-data">
          <table width="95%">
            <tr>
              <td width="100%" height="90%"><textarea id="command-data" rows="15" cols="45" name="text" placeholder="Enter text"></textarea></td>
            </tr>
          </table>
        </form>
      
      </body>
    </html>
  )=====";

} // namespace serial_html_ns
