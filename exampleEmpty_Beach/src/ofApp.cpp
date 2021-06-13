#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    width = ofGetWidth();
    height = ofGetHeight();

    //myArduino.connect("/dev/tty/usb0", 9600);
    mySerial.getDeviceList();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSeedRandom(38); 


}

//--------------------------------------------------------------
void ofApp::draw(){
    float noise_seed [800];
    ofBackground (6,5,43);

    //star
    for (int i = 0 ; i<100; i++){
        ofSetColor(255, ofMap(ofRandom(1000), 0, 1000, 0, 200));
        ofDrawCircle(ofRandom(width), ofRandom(height), ofMap(ofRandom(1000), 0, 1000, 0.5, 3));
    }

    
    //city sillhouette
    /*
    ofSetColor(0);
    ofBeginShape();
    int temp;
    for (int x = 0; x <= width; x ++) {
        int y ;
        if (x%30 == 0){
            y = ofMap(ofNoise(ofRandom(1000), (x * 0.01)), 0, 1, height/5*3-200, height/5*3-100);
            temp = y;
        }
        else {
            y = temp;
        }

        ofVertex(x, y);
	}
    ofVertex(width, height);
    ofVertex(0, height);
    ofEndShape();    
    */

    ofSetColor(255);
    /*
    int temp;
    for (int x = -180; x <= 0; x ++) {
        ofBeginShape();
        int ty ;
        if (mouseX%30 == 0){
            ty = ofMap(ofNoise(ofRandom(1000), (mouseX * 0.01)), 0, 1, height/5*3-200, height/5*3-100);
            temp = ty;
        }
        else {
            ty = temp;
        }

        ofVertex(mouseX + (x+180)*glm::cos(glm::radians((float)x)), mouseY + ofClamp(ty, mouseY+(x+180)*glm::sin(glm::radians((float)x)), height));
        ofVertex(mouseX + (x+180), height);
        ofVertex(mouseX - (x+180), height);
        ofEndShape();  
	}
    */


    for (int r = 30; r<=180; r=30+r*3){

        //ofDrawCircle(mouseX, mouseY, r);
    }

        int r = 50;
        ofBeginShape();
        for (float x = mouseX-r; x <= mouseX+r; x +=1) {
            float theta = glm::acos((x-mouseX)/r);
            ofVertex(mouseX+r*glm::cos(theta), mouseY+r*glm::sin(theta));
        }
        for (float x = mouseX+r; x <= mouseX-r; x -=1) {
            float theta = glm::acos((x-mouseX)/r);
            ofVertex(mouseX+r*glm::cos(theta), mouseY+r*glm::sin(theta));
        }
        ofEndShape();

    /*
    //light
    if (mouseIsPressed){
        ofSetColor(240,236,175,5);
        for (int i = 0; i<50; i++){
            ofDrawCircle(mouseX, mouseY, i*3+30);
        }
    }
    */

    //shapes
    for (int i = 0 ; i<25; i += 2){
        noise_seed[i] = ofRandom(1000);
        float val = ofMap(noise_seed[i], 0, 1000, 20, 35);
        ofSetColor(ofMap(noise_seed[i], 0, 1000, 30, 80), ofMap(noise_seed[i], 0, 1000, 130, 80), ofMap(noise_seed[i], 0, 1000, 150, 200), ofMap(noise_seed[i], 0, 1000, 30, 85) );
        
        ofBeginShape();
        for (int x = 0; x <= width; x += 1) {
		    auto y = ofMap(ofNoise(noise_seed[i], ((x + ofGetFrameNum()) * 0.01)), 0, 1, height/5*3+i*val-val/2, height/5*3+i*val+val/2);
            ofVertex(x, y+val*glm::cos(glm::radians((float)ofGetFrameNum())));
	    }
        ofVertex(width, height);
        ofVertex(0, height);
	    ofEndShape();

        noise_seed[i+1] = ofRandom(1000);
        val = ofMap(noise_seed[i+1], 0, 1000, 20, 35);
        ofSetColor(ofMap(noise_seed[i+1], 0, 1000, 70, 100), ofMap(noise_seed[i+1], 0, 1000, 200, 130), ofMap(noise_seed[i+1], 0, 1000, 200, 255), ofMap(noise_seed[i+1], 0, 1000, 30, 85) );
        
        ofBeginShape();
        for (int x = 0; x <= width; x += 1) {
		    auto y = ofMap(ofNoise(noise_seed[i+1], ((x + ofGetFrameNum()) * 0.01)), 0, 1, height/5*3+(i+1)*val-val/2, height/5*3+(i+1)*val+val/2);
            ofVertex(x, y+val*glm::sin(glm::radians((float)ofGetFrameNum())));
	    }
        ofVertex(width, height);
        ofVertex(0, height);
	    ofEndShape();
    }


    //lines
    /*
    for (int i = 0 ; i<25; i++){
        noise_seed[i] = ofRandom(1000);
        float val = ofMap(noise_seed[i], 0, 1000, 20, 35);
        ofSetColor(ofMap(noise_seed[i], 0, 1000, 70, 100), ofMap(noise_seed[i], 0, 1000, 200, 130), ofMap(noise_seed[i], 0, 1000, 200, 255));
            
        ofBeginShape();
        for (int x = 0; x <= width; x += 1) {
            auto y = ofMap(ofNoise(noise_seed[i], ((x + ofGetFrameNum()) * 0.01)), 0, 1, height/5*3+i*val-val/2, height/5*3+i*val+val/2);
            ofVertex(x, y);
        }
        
        for (int x = width; x >= 0; x -= 1) {
            auto y = ofMap(ofNoise(noise_seed[i], ((x + ofGetFrameNum()) * 0.01)), 0, 1, height/5*3+i*val-val/2+2, height/5*3+i*val+val/2+2);
            ofVertex(x, y);
        }
        ofEndShape();
    } 
    */

    //moons
    /*
    ofSetColor(240, 236, 175);
    ofDrawCircle(width/5*4, height/5, 40); 
    */


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ 
    mouseIsPressed = true;
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseIsPressed = true;
 }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ 
    mouseIsPressed = false;
}
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
