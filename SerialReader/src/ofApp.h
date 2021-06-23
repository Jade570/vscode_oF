#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
public:
	
	void setup();
	void update();
	
	ofArduino myArduino;
	ofSerial mySerial;
};
