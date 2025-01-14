#pragma once

#include "ofMain.h"
#include "aurora.h"

class ofApp : public ofBaseApp{
public:
	
	void setup();
	void update();
	void draw();
	
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	

	int timer = 0;
	float width, height;
	bool mouseIsPressed = false;

	ofSerial serial;
	aurora Aurora [1000];
	float noise_seed [5000];
	
	int pX = 0, pY = 0;
	int i = 0;

	int x, y, z;
	int angX, angY, angZ;
};
