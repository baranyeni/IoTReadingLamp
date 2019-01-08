# IoTReadingLamp
Online switched reading lamp.

## ABOUT
  When This code flashes into ESP8266 Wifi Module, ESP Module starts hosting a html file which can be reachable at it's ip adress.
  Page variable is a HTML doc which converted to C++ strings (escape quotes, I mean.) (You must convert the document to prevent faulty invokes an alternative interpretation)
  And controls I/O's depends on the directory which you are in. (in my case /LEDOff turns off, /LEDOn turns on the light.)
  
## HARDWARE
  ###ESP8266 NodeMCU
  ###Relay Module (If you want to control something more then LED.)
  ###Adapter (To power ESP Module)
