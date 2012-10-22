ofNetworkArduino
================

This is just like ofArduino except that instead of using `connect(portname, baudrate)` you should use `connect_tcpip(string ipaddress, int port)`

Under the hood, it uses ofxTCPClient (you'll need to include ofNetwork) to handle sending and receiving bytes.

I use this to communicate with Arduino+Firmata devices connected to a WiFi network (in my case, using Roving Networks RN-XV devices available from Sparkfun.

