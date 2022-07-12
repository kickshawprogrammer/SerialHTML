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
class AsyncWebSocketClient;

namespace serial_html_ns {

  typedef std::function<void(AsyncWebSocketClient*)> ConnectHandler;
  typedef std::function<void(AsyncWebSocketClient*)> DisconnectHandler;
  typedef std::function<void(AsyncWebSocketClient*, uint8_t* data, size_t length)> MessageHandler;
  typedef std::function<void(AsyncWebSocketClient*, uint16_t code, const char *reason, size_t reason_length)> ErrorHandler;

  class serial_html_class : public Print {
    public:
      virtual ~serial_html_class(void);
      
      void begin(AsyncWebServer *server, const char* url="/serial");
      
      void onMessage(MessageHandler handler);
      void onError(ErrorHandler handler);
      void onConnect(ConnectHandler); 
      void onDisconnect(DisconnectHandler);

      virtual size_t write(uint8_t ch) override;
      virtual size_t write(const uint8_t *buffer, size_t size) override;

    private:
      AsyncWebServer   *m_webServer;
      AsyncWebSocket   *m_webSocket;

      MessageHandler    m_messageHandler;
      ErrorHandler      m_errorHandler;
      ConnectHandler    m_connectHandler;
      DisconnectHandler m_disconnectHandler;

  }; // class serial_html_class

} // namespace serial_html_ns

extern serial_html_ns::serial_html_class SerialHTML;
