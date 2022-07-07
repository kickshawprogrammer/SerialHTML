// NOTE: Cut & Paste copied directly from the browser-code/index.css file
//
//       char index_css[] PROGMEM = R"=====(
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

  char index_css[] PROGMEM = R"=====(
    .centered-wrapper {
      position: relative;
      text-align: center;
    }

    h1 {
      font-size: 30px;
      color: darkslateblue;
    }

    #command-text {
      color: #777;
      border: 2px solid grey;
      margin-left: auto;
      margin-right: 0;
      outline: none;
      height: 25px;
      width: 97%;
      font-size: 20px;
      -webkit-border-radius: 15px 50px 50px 15px;
      -moz-border-radius: 15px 50px 50px 15px;
      -ms-border-radius: 15px 50px 50px 15px;
      -o-border-radius: 15px 50px 50px 15px;
      -khtml-border-radius: 15px 50px 50px 15px;
      border-radius: 10px 10px 10px 10px;
      padding: 5px;
      white-space: nowrap;
    }

    #command-text:active,
    #command-text:focus,
    #command-text:hover {
      color: #000;
      border: 2px solid black;
    }

    #command-button {
      color: #fff;
      background-color: darkturquoise;
      background: linear-gradient(white, teal);
      margin-left: auto;
      margin-right: auto;
      outline: none;
      width: 100%;
      height: 40px;
      font-size: 20px;
      -webkit-border-radius: 15px 50px 50px 15px;
      -moz-border-radius: 15px 50px 50px 15px;
      -ms-border-radius: 15px 50px 50px 15px;
      -o-border-radius: 15px 50px 50px 15px;
      -khtml-border-radius: 15px 50px 50px 15px;
      border-radius: 10px 10px 10px 10px;
      padding: 5px;
    }

    #command-button:hover {
      color: #000;
      background-color: paleturquoise;
    }

    #command-button:active,
    #command-button:target {
      border-style:inset;
      background-color: darkslategrey;
      background: linear-gradient(white, darkslategrey);
    }

    #command-data {
      color: #000;
      border: 2px solid grey;
      font-size: 20px;
      -webkit-border-radius: 50px 15px 15px 50px;
      -moz-border-radius: 50px 15px 15px 50px;
      -ms-border-radius: 50px 15px 15px 50px;
      -o-border-radius: 50px 15px 15px 50px;
      -khtml-border-radius: 50px 15px 15px 50px;
      border-radius: 10px 10px 10px 10px;
      white-space: nowrap;
      margin: 0;
      padding: 0;
      width: 100%;
      height: 100%;
      vertical-align:top;
    }

  )=====";

} // namespace serial_html_nsrrrrrrrrrrrrrrrrrrrrrrrrrrrr
