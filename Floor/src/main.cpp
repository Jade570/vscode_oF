#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	// using programmable pipeline


	// or default setup 
	//ofSetupOpenGL(700,700, OF_WINDOW);			// <-------- setup the GL context
	ofSetupOpenGL(2000, 1080, OF_WINDOW);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofHideCursor();
	ofRunApp( new ofApp());
}

