#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    width = ofGetWidth();
    height = ofGetHeight();
    for (int i = 0 ; i<width; i++){
        rand[i] = ofMap(ofRandom(1000), 0, 1000, height/3, height/3*2);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(59, 54, 50);
    //ofBackground(0);
    ofSetColor(35,35,40, 30);
    /*
    float morphed = (glm::cos(glm::radians((float)ofGetFrameNum()))+1)*0.5;
    if (mouseIsEntered){
        for (int i = 0 ; i< 50; i++){
            ofBeginShape();
            for (int x = -400 ; x<mouseX-400; x+=100){
                ofCurveVertex(x, ofLerp(0,rand[x/64],morphed));   
            }
            ofCurveVertex(mouseX-200, ofLerp(0,mouseY-100,morphed));
            ofCurveVertex(mouseX, ofLerp(0,mouseY+100,morphed));
            ofCurveVertex(mouseX+200, ofLerp(0,mouseY-100,morphed));
            for (int x = mouseX+400 ; x<width+400; x+=100){
                ofCurveVertex(x, ofLerp(0,rand[x/64],morphed));   
            }
            ofVertex(width+400, 0);
            ofVertex(-400,0);
            ofEndShape();
        }
    }*/
    
    for (int x = 0 ; x < width; x+=10){
        for (int y = 0 ; y<height; y+= 10){
            //1d
            //ofSetColor(ofMap(ofNoise(x/width), 0, 1, 0, 255));
            //2d
            ofSetColor(ofMap(ofNoise(x/(width)+ofGetFrameNum()*0.001, y/(height)), 0, 1, 0, 10), ofMap(ofNoise(x/(width)+ofGetFrameNum()*0.002, y/(height)), 0, 1, 20, 0), ofMap(ofNoise(x/(width)+ofGetFrameNum()*0.004, y/(height)), 0, 1, 40, 255));
            ofDrawRectangle(x, y, 10, 10); 
        }      
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

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    mouseIsEntered = true;
}
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){ 
    mouseIsEntered = false;
}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
