# SerialHTML

A web-based class to mimic the Arduino IDE Serial Monitor for use with an ESP8266 microcontroller to log, monitor ord debug your code remotely.

* **NOTE:** This project was heavily inspired by the [WebSerial](https://github.com/ayushsharma82/WebSerial.git) project.

## Dependencies
----------------

Like the original [WebSerial](https://github.com/ayushsharma82/WebSerial.git) project, this library also requires some external dependencies:

* [ESP8266 Arduino Core](https://github.com/esp8266/Arduino) Async HTTP and WebSocket Server for ESP8266 Arduino

* [ESPAsyncTCP - v1.2.2](https://github.com/me-no-dev/ESPAsyncTCP) Async TCP Library for ESP8266 Arduino

* [ESPAsyncWebServer - v1.2.3](https://github.com/me-no-dev/ESPAsyncWebServer) Async HTTP and WebSocket Server for ESP8266 Arduino

## Wish-List
-------------

Right now, I've done the development using Platform IO as a part of a personal project. I've only recently decided that others may need an alternative option for a web-based serial monitor so I have decided to make it available for them as it is.

With that in mind, there are several things that I'd like to see done/do in the coming updates.

* Add proper Arduino IDE support.

  I have been able to place this entire directory structure into the Arduino/libraries directory and get it to work in the Arduino IDE; however, a proper library manager implementation would be wonderful.
  
* Add proper Platform IO support.

  Outside of my project, I've not gotten it working with Platform IO yet. Within Platform IO (my project), it is a sub-directory of the project's /lib directory structure.

* Provide a proper README file and related documentation.

I'm sure there are others, but those will do for now...

## A Note About the Handlers
----

I've created four web-socket handlers in this latest update: onMessage(), onError(), onConnect() and onDisconnect(). Care must be taken when defining these callbacks because SerialHTML does not, in itself, distinguish outputs from one web-socket to another and instead flushes all output to all available sockets at once.

## License
-----------

Feel free to use in any way you wish; but please, be kind and do good!
