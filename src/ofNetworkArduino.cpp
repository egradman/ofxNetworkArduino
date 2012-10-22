//
//  ofNetworkArduino.cpp
//  glowglobe
//
//  Created by eric Gradman on 10/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "ofNetworkArduino.h"

bool ofNetworkArduino::connect_tcpip(string ip, int port){
	connectTime = ofGetElapsedTimef();
	_initialized = false;
    
    connected = _socket.setup(ip, port, false);
	return connected;
}

ofNetworkArduino::~ofNetworkArduino() {
	_socket.close();
}

void ofNetworkArduino::disconnect(){
	_socket.close();
}

void ofNetworkArduino::update(){
    char buf[255];
    int numbytes = _socket.receiveRawBytes(buf, 255);
    if (numbytes > 0) {
        for (int i=0; i<numbytes; i++) {
            processData(buf[i]);
        }
    }
}

void ofNetworkArduino::sendByte(unsigned char byte){
	//char msg[100];
	//sprintf(msg, "Sending Byte: %i", byte);
	//Logger::get("Application").information(msg);
    const char *bytes = (const char *)&byte;
	_socket.sendRawBytes(bytes, 1);
}



