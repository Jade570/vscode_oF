#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    width = ofGetWidth();
    height = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSeedRandom(38);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground (0);
    
    for (int i = 0 ; i < ripPond.size() ; i++ ){
        ripPond[i].render();
    }   

    if (mouseIsPressed == true){
        ripple *temp = new ripple(mx,my);
        ripPond.push_back(*temp);
    }
    
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
 }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    mouseIsPressed = true;
    mx = x;
    my = y;
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){ }
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
