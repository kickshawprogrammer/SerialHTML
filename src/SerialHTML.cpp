//+-----------------------------------------------------------------------------
// 
//  File:         SerialHTML.cpp
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
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>

#include "SerialHTML.h"

#ifndef unused_variable
#  define unused_variable_defined
#  define unused_variable(x) (sizeof(x))
#endif

#ifdef DEBUG_SERIAL_HTML
#  define SERIAL_HTML_DEBUG_PRINT(msg) Serial.print(msg)
#  define SERIAL_HTML_DEBUG_PRINTLN(msg) Serial.println(msg)
#else
#  define SERIAL_HTML_DEBUG_PRINT(msg) (sizeof(msg))
#  define SERIAL_HTML_DEBUG_PRINTLN(msg) (sizeof(msg))
#endif

namespace serial_html_ns {

  extern const char index_html[]; // Declared in index.html.cpp
  extern const char index_js[];   // Declared in index.js.cpp
  extern const char index_css[];  // Declared in index.css.cpp

  serial_html_class::~serial_html_class(void) {
    if (nullptr != m_webSocket) {
      delete m_webSocket;
      m_webSocket = nullptr;
    }
  }

  void serial_html_class::begin(AsyncWebServer *server, const char* url) {
    m_webServer = server;
    m_webSocket = new AsyncWebSocket("/serialhtmlws");

    // First, define what happens when we get data back from the web-based serial monitor
    m_webSocket->onEvent([&](AsyncWebSocket* server, AsyncWebSocketClient* client, 
                             AwsEventType type, void* arg, uint8_t* data, size_t len) -> void {
      
      unused_variable(server);
      unused_variable(client);
      unused_variable(arg);

      if(type == WS_EVT_CONNECT) { 
        SERIAL_HTML_DEBUG_PRINTLN(F("Client connection received"));
        if (m_connectHandler != NULL) {
          m_connectHandler(client);
        }
      }
      else if(type == WS_EVT_DISCONNECT) {
        SERIAL_HTML_DEBUG_PRINTLN(F("Client disconnected"));
        if (m_disconnectHandler != NULL) {
          m_disconnectHandler(client);
        }
      }
      else if(type == WS_EVT_ERROR) {
        SERIAL_HTML_DEBUG_PRINTLN(F("Client error"));
        if (m_errorHandler != NULL) {
          m_errorHandler(client, *(uint16_t*)arg, (const char*)data, len);
        }
      }
      else if(type == WS_EVT_DATA) {
        SERIAL_HTML_DEBUG_PRINTLN(F("Received Websocket Data"));
        if(m_messageHandler != NULL) {
          m_messageHandler(client, data, len);
        }
      }
    });

    // Now, define what happens when we get requests for web-pages
    m_webServer->on(url, HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send_P(200,"text/html", serial_html_ns::index_html);
    });

    m_webServer->on("/serial_index.css", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send_P(200,"text/css", serial_html_ns::index_css);
    });

    m_webServer->on("/serial_index.js", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send_P(200,"application/javascript", serial_html_ns::index_js);
    });

    m_webServer->addHandler(m_webSocket);
  }

  void serial_html_class::onMessage(MessageHandler handler) {
    m_messageHandler = handler;
  }

  void serial_html_class::onError(ErrorHandler handler) {
    m_errorHandler = handler;
  }

  void serial_html_class::onConnect(ConnectHandler handler) {
    m_connectHandler = handler;
  }

  void serial_html_class::onDisconnect(DisconnectHandler handler) {
    m_disconnectHandler = handler;
  }

  size_t serial_html_class::write(uint8_t ch) {
    if (m_webSocket->count()) {
      m_webSocket->textAll((char*) &ch, 1);
      SERIAL_HTML_DEBUG_PRINT((char)ch);
      return 1;
    }

    return 0;
  }
  
  size_t serial_html_class::write(const uint8_t *buffer, size_t size) {
    if (m_webSocket->count()) {
      m_webSocket->textAll((const char*) buffer, size);
      SERIAL_HTML_DEBUG_PRINT((const char*) buffer);
      return size;
    }

    return 0;
  }

} // namespace serial_html_ns

serial_html_ns::serial_html_class SerialHTML;

#ifdef unused_variable_defined 
#  undef unused_variable_defined
#  undef unused_variable
#endif
