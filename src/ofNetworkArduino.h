//
//  ofNetworkArduino.h
//  glowglobe
//
//  Created by eric Gradman on 10/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef glowglobe_ofNetworkArduino_h
#define glowglobe_ofNetworkArduino_h

#include "ofMain.h"
#include "ofxTCPClient.h"

class ofNetworkArduino : public ofArduino
{
public:
    bool connect_tcpip(string ip, int port=2000);
    ~ofNetworkArduino();
    void disconnect();    
    void update();    
    void sendByte(unsigned char byte);


private:
    ofxTCPClient _socket;

};

#endif
