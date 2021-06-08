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
    float noise_seed [800];
    ofBackground (6,5,43);

    //city sillhouette
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


    //light
    if (mouseIsPressed){
        ofSetColor(240,236,175,5);
        for (int i = 0; i<50; i++){
            ofDrawCircle(mouseX, mouseY, i*3+30);
        }
    }


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
