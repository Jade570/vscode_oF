#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    width = ofGetWidth();
    height = ofGetHeight();

    //myArduino.connect("/dev/tty/usb0", 9600);
    mySerial.getDeviceList();

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
        city[x] = y;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSeedRandom(38); 
}

//--------------------------------------------------------------
void ofApp::draw(){
    float noise_seed [5000];
    //ofBackground (6,5,43);
    ofBackground(0);

    //star
    for (int i = 0 ; i<100; i++){
        ofSetColor(255, ofMap(ofRandom(1000), 0, 1000, 0, 200));
        ofDrawCircle(ofRandom(width), ofRandom(height), ofMap(ofRandom(1000), 0, 1000, 0.5, 3));
    }

    //tried to drop shadow the city silhouette
    /*
    ofSetColor(0);
    for (float r = 50; r<=180; r+=3){
        float xPos, yPosDown, yPosUp;
        ofBeginShape();
        for (float x = mouseX-r; x <= mouseX+r; x +=5) {
            float theta = glm::acos((x-mouseX)/r);
            xPos = mouseX+r*glm::cos(theta);
            yPosDown = mouseY+r*glm::sin(theta);
            if (city[(int)glm::roundEven(xPos)]<=yPosDown){
                ofVertex(xPos, yPosDown);
            }
            else{               
            }
        }
        for (float x = mouseX+r; x >= mouseX-r; x -=5) {
            float theta = glm::acos((x-mouseX)/r);
            xPos = mouseX+r*glm::cos(theta);
            yPosUp = mouseY-r*glm::sin(theta);
            if (city[(int)glm::roundEven(xPos)]<=yPosUp && city[(int)glm::roundEven(xPos)]>mouseY-r){
                ofVertex(xPos, city[(int)glm::roundEven(xPos)]);
            }
        }
        ofEndShape();
    }
    */

    // flash light
    float opacity = ofMap(mouseY, height-height/5, height/5*2, 50, 0);     
    for (float r = 30; r<=300; r*=1.3){
        ofSetColor(255, 251, 222, opacity/2-r/15); 
        ofDrawCircle(mouseX, mouseY, r);        
        /*float xPos, yPosDown, yPosUp;
        ofBeginShape();
        for (float x = mouseX-r; x <= mouseX+r; x +=5) {
            float theta = glm::acos((x-mouseX)/r);
            xPos = mouseX+r*glm::cos(theta);
            yPosDown = mouseY+r*glm::sin(theta);
            ofVertex(xPos, yPosDown);
        }
        for (float x = mouseX+r; x >= mouseX-r; x -=5) {
            float theta = glm::acos((x-mouseX)/r);
            xPos = mouseX+r*glm::cos(theta);
            yPosUp = mouseY-r*glm::sin(theta);
            ofVertex(xPos, yPosUp);
        }
        ofEndShape();*/
    }

    // aurora
    if (mouseY < height/5*4){
        if (pX != mouseX || pY != mouseY){
            Aurora[i].Create(pX, pY, mouseX, mouseY, ofGetFrameNum());
            if (i < 1000){
                i++;
            }
            else{
                i = 0;
            } 
        }  
    }

    for(int i = 0 ; i<1000; i++){
        Aurora[i].Show(0,255,210,100, ofMap(ofNoise(ofRandom(1000)*0.001),0, 1, 0.5, 1.5), height);   
    }

    /*
    for (int i = 0 ; i<9; i++){
        printf("%f, ", Aurora[i].Noise);
    }
    printf("%f\n", Aurora[10].Noise);*/
    //printf("%f\n", ofMap(ofNoise(ofGetFrameNum()*0.01),0, 1, 0.5, 1.5));

    //wave in shapes 
    for (int i = 0 ; i<25; i += 2){
        noise_seed[i] = ofRandom(1000);
        float val = ofMap(noise_seed[i], 0, 1000, 20, 35);
        ofSetColor(ofMap(noise_seed[i], 0, 1000, 30/5, 80/5), ofMap(noise_seed[i], 0, 1000, 130/5, 80/5), ofMap(noise_seed[i], 0, 1000, 150/5, 200/5), ofMap(noise_seed[i], 0, 1000, 5, 45) );
        
        // 영상용
        //ofSetColor(ofMap(noise_seed[i], 0, 1000, 30*1.5, 80*1.5), ofMap(noise_seed[i], 0, 1000, 130*1.5, 80*1.5), ofMap(noise_seed[i], 0, 1000, 150*1.5, 200*1.5), ofMap(noise_seed[i], 0, 1000, 5, 45) );

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
    


    /*
    ofBeginShape();
    for (int x = 0; x <= width; x+= 3){
        noise_seed[x] = ofRandom(1000);
        int y = height/2+ofNoise(noise_seed[x], ofGetFrameNum()*0.01)*10;
        //ofDrawCircle(x, y, 3);
        ofVertex(x, y);
    }
    for (int x = width; x >= 0; x-= 3){
        int y = height/2+ofNoise(noise_seed[x], ofGetFrameNum()*0.01)*10;
        ofVertex(x, y+3);
    }
    ofEndShape();
    */

    //wave in lines  
    /*
    noise_seed[0] = ofRandom(1000);
    for (int i = 0 ; i<25; i++){      
        float val = ofMap(noise_seed[0], 0, 1000, 20, 35);
        ofSetColor(ofMap(noise_seed[0], 0, 1000, 70, 100), ofMap(noise_seed[0], 0, 1000, 200, 130), ofMap(noise_seed[0], 0, 1000, 200, 255));
                             
        ofBeginShape();
        for (int x = 0; x <= width; x += 10) {
            noise_seed[x+1] = ofRandom(1000);
            auto y = ofMap(ofNoise(noise_seed[x+1], ((x + ofGetFrameNum()) * 0.01)), 0, 1, height/5*3+i*val-val/2, height/5*3+i*val+val/2);
            ofVertex(x, y);
        }             
                   
        for (int x = width; x >= 0; x -= 10) {
            auto y = ofMap(ofNoise(noise_seed[x+1], ((x + ofGetFrameNum()) * 0.01)), 0, 1, height/5*3+i*val-val/2+5, height/5*3+i*val+val/2+5);
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
    pX = mouseX;
    pY = mouseY;
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
