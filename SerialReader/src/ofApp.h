#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
public:
	void setup();
	void update();


	ofSerial serial;

	int x, y, z;
	int angX, angY, angZ;
};
