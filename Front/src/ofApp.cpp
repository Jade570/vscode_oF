#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    width = ofGetWidth();
    height = ofGetHeight()-200;
    for (int i =0 ; i<width+400; i++){
        rand[i] = ofRandom(1000);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){ 
    
    //ofBackground(0);
    //ofBackground(59, 54, 50);
    //background
    for (int x = 0 ; x < width; x+=30){
        for (int y = 0 ; y<height+400; y+= 30){
            ofSetColor(ofMap(ofNoise(x/(width), y/(height)), 0.2, 0.8, 0.8, 1.5)*59, ofMap(ofNoise(x/(width), y/(height)), 0.2, 0.8, 0.8, 1.5)*54, ofMap(ofNoise(x/(width), y/(height)), 0.2, 0.8, 0.8, 1.5)*50);
            ofDrawRectangle(x, y, 30, 30); 
        }      
    }

    // waves
    float morphed = (glm::cos(glm::radians((float)ofGetFrameNum()))+1)*0.5+0.1;
    /*if (mouseIsEntered){
        for (int i = -3 ; i< 10; i++){
            if (i == -3){
                ofSetColor(255,255,255, 25);
            }
            else{
                ofSetColor(20/3+ofMap(ofNoise(i*0.008), 0.3, 0.8, -2, 2),35/3+ofMap(ofNoise(i*0.02), 0.8, 0.3, -2, 2),40/3+ofMap(ofNoise(i*0.01), 0.3, 0.7, 0, 30),30+ofMap(ofNoise((i+3)*0.01), 0.3, 0.8, -10, 15));   
            }

            ofBeginShape();
            for (int x = -400 ; x<mouseX-400; x+=100){
                ofCurveVertex(x+ofMap(ofNoise(ofGetFrameNum()*0.0018, i*0.01), 0, 1, -50, 50), ofLerp(0,-i*30+ofMap(rand[400+x/64]+ofMap(ofNoise(i*0.01), 0.3, 0.8, -200, 200), 0, 1000, (mouseY/3), mouseY*0.6),morphed));   
            }
            ofCurveVertex(mouseX-200+ofMap(ofNoise(ofGetFrameNum()*0.00001, i*0.01), 0.4, 0.7, -50, 50), ofLerp(0,-i*30+mouseY*0.5*ofMap(ofNoise(ofGetFrameNum()*0.00001), 0, 1, 0.7, 2),morphed));
            ofCurveVertex(mouseX, ofLerp(0,ofClamp(-i*30+mouseY, 0, height),morphed));
            ofCurveVertex(mouseX+200+ofMap(ofNoise(ofGetFrameNum()*0.000005, i*0.01),  0.4, 0.7, -50, 50), ofLerp(0,-i*30+mouseY*0.5*ofMap(ofNoise(ofGetFrameNum()*0.000001), 0, 1, 0.7, 2),morphed));
            for (int x = mouseX+400 ; x<width+400; x+=100){
                ofCurveVertex(x+ofMap(ofNoise(ofGetFrameNum()*0.002, i*0.001), 0, 1, -50, 50), ofLerp(0,-i*30+ofMap(rand[400+x/64]+ofMap(ofNoise(i*0.01), 0.3, 0.7, -200, 2000), 0, 1000, (mouseY/3), mouseY*0.6),morphed));   
            }
            ofVertex(width+400, 0);
            ofVertex(-400,0);
            ofEndShape();
        }
    }
    else{*/
        for (int i = -3 ; i< 10; i++){
            if (i == -3){
                ofSetColor(255,255,255, 25);
            }
            else{
                ofSetColor(20/3+ofMap(ofNoise(i*0.008), 0.3, 0.8, -2, 2),35/3+ofMap(ofNoise(i*0.02), 0.8, 0.3, -2, 2),40/3+ofMap(ofNoise(i*0.01), 0.3, 0.7, 0, 30),30+ofMap(ofNoise((i+3)*0.01), 0.3, 0.8, -10, 15));   
            }

            ofBeginShape();
            for (int x = -400 ; x<width+400; x+=100){
                ofCurveVertex(x+ofMap(ofNoise(ofGetFrameNum()*0.0018, i*0.01), 0, 1, -50, 50), ofLerp(0,-i*30+ofMap(rand[400+x/64]+ofMap(ofNoise(i*0.01), 0.3, 0.8, -200, 200), 0, 1000, (height/3), height*0.6),morphed));   
            }
            ofVertex(width+400, 0);
            ofVertex(-400,0);
            ofEndShape();
        } 
    //}
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
