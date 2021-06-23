#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	// using programmable pipeline


	// or default setup 
	//ofSetupOpenGL(700,700, OF_WINDOW);			// <-------- setup the GL context
	//ofSetupOpenGL(100, 1080, OF_WINDOW);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofSetupOpenGL(100, 100, OF_WINDOW);
	ofRunApp( new ofApp());
}

