# IoTReadingLamp
Online switched reading lamp.

## ABOUT
  When This code flashes into ESP8266 Wifi Module, ESP Module starts hosting a html file which can be reachable at it's ip adress.  
  Page variable is a HTML doc which converted to C++ strings (escape quotes, I mean.) (You must convert the document to prevent faulty invokes an alternative interpretation)  
  And controls I/O's depends on the directory which you are in. (in my case /LEDOff turns off, /LEDOn turns on the light.)  
  
## HARDWARE
  ESP8266 NodeMCU  
  Relay Module (If you want to control something more than a LED light.)  
  Adapter, SMPS in my case (To power ESP Module)  

## NEED
  If anyone who is reading this does have a knowledge about creating a local domain name, please contact me at info@baranyeni.com 
  Using ip adress on browser is is mess and using special domain name in my home is cool. (Such as rest-room-reading-lamp.com)
