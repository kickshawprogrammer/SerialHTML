#pragma once
//+-----------------------------------------------------------------------------
// 
//  File:         SerialHTML.h
//  Description:  provide serial printout functionality to a web-server for access
//                when the device is not plugged directly into a computer via USB
//
//  Credits to:   concept taken from https://github.com/ayushsharma82/WebSerial
// 
//  Notes:        This class will be derived from the ESP's Print class to take 
//                advantage of that classes' pre-defined print support functions. 
//                All we have to do is provide our own versions of the write()
//                methods to forward the various message types to the underlying 
//                AsyncWebSocket.
//
//  History:      06/19/2022 - Original version.
//  
//------------------------------------------------------------------------------
//  Feel free to use in any way you wish; but please, be kind and do good!
//------------------------------------------------------------------------------
#include <functional>
#include <Print.h>

// Forward declares
class AsyncWebServer;
class AsyncWebSocket;

namespace serial_html_ns {

  typedef std::function<void(uint8_t* data, size_t length)> ReceiveHandler;

  class serial_html_class : public Print {
    public:
      void begin(AsyncWebServer *server, const char* url="/serial");
      ReceiveHandler setReceiveHandler(ReceiveHandler handler);

      virtual size_t write(uint8_t ch) override;
      virtual size_t write(const uint8_t *buffer, size_t size) override;

    private:
      AsyncWebServer *m_webServer;
      AsyncWebSocket *m_webSocket;
      ReceiveHandler  m_receiveHandler;

  }; // class serial_html_class

} // namespace serial_html_ns

extern serial_html_ns::serial_html_class SerialHTML;

