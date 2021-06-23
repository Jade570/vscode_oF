#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    width = ofGetWidth();
    height = ofGetHeight();
    for (int i =0 ; i<width+400; i++){
        rand[i] = ofRandom(1000);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){ 

    //background
    for (int x = 0 ; x < width; x+=10){
        for (int y = 0 ; y<height; y+= 10){
            ofSetColor(ofMap(ofNoise(x/(width), y/(height)), 0, 1, 0.8, 1.5)*59, ofMap(ofNoise(x/(width), y/(height)), 0, 1, 0.8, 1.5)*54, ofMap(ofNoise(x/(width), y/(height)), 0, 1, 0.8, 1.5)*50);
            ofDrawRectangle(x, y, 10, 10); 
        }      
    }

    // waves
    float morphed = (glm::cos(glm::radians((float)ofGetFrameNum()))+1)*0.5+0.1;
    if (mouseIsEntered){
        for (int i = -3 ; i< 6; i++){
            ofSetColor(20+ofMap(ofNoise(i*0.008), 0.3, 0.8, -2, 2),35+ofMap(ofNoise(i*0.02), 0.8, 0.3, -2, 2),40+ofMap(ofNoise(i*0.01), 0.3, 0.7, 0, 30),30+ofMap(ofNoise((i+3)*0.01), 0.3, 0.8, -20, 5));

            ofBeginShape();
            for (int x = -400 ; x<mouseX-400; x+=100){
                ofCurveVertex(x+ofMap(ofNoise(ofGetFrameNum()*0.0018, i*0.01), 0, 1, -50, 50), ofLerp(0,-i*30+ofMap(rand[400+x/64]+ofMap(ofNoise(i*0.01), 0.3, 0.8, -200, 200), 0, 1000, (mouseY/3)*2, mouseY*0.8),morphed));   
            }
            ofCurveVertex(mouseX-200+ofMap(ofNoise(ofGetFrameNum()*0.00001, i*0.01), 0.4, 0.7, -50, 50), ofLerp(0,-i*30+mouseY*0.5*ofMap(ofNoise(ofGetFrameNum()*0.00001), 0, 1, 0.7, 2),morphed));
            ofCurveVertex(mouseX, ofLerp(0,-i*30+mouseY+100,morphed));
            ofCurveVertex(mouseX+200+ofMap(ofNoise(ofGetFrameNum()*0.000005, i*0.01),  0.4, 0.7, -50, 50), ofLerp(0,-i*30+mouseY*0.5*ofMap(ofNoise(ofGetFrameNum()*0.000001), 0, 1, 0.7, 2),morphed));
            for (int x = mouseX+400 ; x<width+400; x+=100){
                ofCurveVertex(x+ofMap(ofNoise(ofGetFrameNum()*0.002, i*0.001), 0, 1, -50, 50), ofLerp(0,-i*30+ofMap(rand[400+x/64]+ofMap(ofNoise(i*0.01), 0.3, 0.7, -200, 2000), 0, 1000, (mouseY/3)*2, mouseY*0.8),morphed));   
            }
            ofVertex(width+400, 0);
            ofVertex(-400,0);
            ofEndShape();
        }
    }
    

    /* 2D perlin noise test
    for (int x = 0 ; x < width; x+=10){
        for (int y = 0 ; y<height; y+= 10){
            //1d
            //ofSetColor(ofMap(ofNoise(x/width), 0, 1, 0, 255));
            //2d
            ofSetColor(ofMap(ofNoise(x/(width)+ofGetFrameNum()*0.001, y/(height)), 0, 1, 0, 10), ofMap(ofNoise(x/(width)+ofGetFrameNum()*0.002, y/(height)), 0, 1, 20, 0), ofMap(ofNoise(x/(width)+ofGetFrameNum()*0.004, y/(height)), 0, 1, 40, 255));
            ofDrawRectangle(x, y, 10, 10); 
        }      
    }*/
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
