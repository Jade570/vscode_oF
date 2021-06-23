#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	// using programmable pipeline


	// or default setup 
	// ofSetupOpenGL(1280,800, OF_WINDOW);			// <-------- setup the GL context
	//ofSetupOpenGL(3840,2160, OF_FULLSCREEN);
	ofSetupOpenGL(1920, 1080, OF_FULLSCREEN);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());
}
