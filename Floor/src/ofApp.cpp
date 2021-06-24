#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    width = ofGetWidth();
    height = ofGetHeight();
    //serial.setup("/dev/ttyUSB0", 9600);
    for (int i = 0 ; i<5000; i++){
        noise_seed[i] = ofRandom(1000);
    }
}


//--------------------------------------------------------------
void ofApp::update(){
   /* //serial.listDevices();
    

   // we want to read 8 bytes
    int bytesRequired = 36;
    unsigned char bytes[bytesRequired];
    int bytesRemaining = bytesRequired;
    // loop until we've read everything
    while ( bytesRemaining > 0 )
    {
        // check for data
        if ( serial.available() > 36 )
        {
            // try to read - note offset into the bytes[] array, this is so
            // that we don't overwrite the bytes we already have
            int bytesArrayOffset = bytesRequired - bytesRemaining;
            int result = serial.readBytes( &bytes[bytesArrayOffset], bytesRemaining );

            // check for error code
            if ( result == OF_SERIAL_ERROR )
            {
            // something bad happened
            ofLog( OF_LOG_ERROR, "unrecoverable error reading from serial" );
            // bail out
            break;
            }
            else if ( result == OF_SERIAL_NO_DATA )
            {
            // nothing was read, try again
            }
            else
            {
            // we read some data!
            bytesRemaining -= result;

            //cout << bytes << endl;
            char temp[4]; 

            //x Coordinate
            for (int i = 3; i<6; i++){
                temp[i-3] = bytes[i];
            }
            temp[3] = 0;
            x = atoi(temp);

            //y Coordinate
            for (int i = 9; i<12; i++){
                temp[i-9] = bytes[i];
            }
            temp[3] = 0;
            y = atoi(temp);

            
            //z Coordinate
            for (int i = 15; i<18; i++){
                temp[i-15] = bytes[i];
            }
            temp[3] = 0;
            z = atoi(temp);

            //x Angle
            for (int i = 21; i<24; i++){
                temp[i-21] = bytes[i];
            }
            temp[3] = 0;
            angX = atoi(temp);

            //y Angle
            for (int i = 27; i<30; i++){
                temp[i-27] = bytes[i];
            }
            temp[3] = 0;
            angY = atoi(temp);

            //z Angle
            for (int i = 33; i<36; i++){
                temp[i-33] = bytes[i];
            }
            temp[3] = 0;
            angZ = atoi(temp);
            }

            cout << "x: " << x << " y: " << y << " z: " << z << " angX: " << angX << " angY: " << angY << " angZ: " << angZ << " mX: " << mouseX << " mY: " << mouseY << endl;
        }
    }
    */
    ofSeedRandom(38);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofBackground (6,5,43);
    ofBackground(15/2, 16/2, 33/2);
    //ofBackground(0);

    //star
    for (int i = 0 ; i<100; i++){
        float alpha = ofMap(ofRandom(1000), 0, 1000, 0, 200);
        float time = ofMap(ofRandom(1000), 0, 1000, 0.5, 1.5);
        ofSetColor(255, alpha*0.5*(glm::sin(glm::radians(ofGetFrameNum()*time))+1));
        ofDrawCircle(ofRandom(width), ofRandom(height/5*3), ofMap(noise_seed[i], 0, 1000, 0.5, 3));
    }

    // background coastal lines
    ofSetColor(0, 40);
    ofBeginShape();
    for (int x = -400; x <= width+400; x += 100) {
        int y = ofMap(ofNoise((x+400)*0.01), 0, 1, height/5*2.7, height/5*3);
        ofVertex(x, y);
    }
    ofVertex(width+400, height);
    ofVertex(-400, height);
    ofEndShape();


    // flash light
    float opacity = ofMap(mouseY, height-height/5, height/5*2, 50, 0);     
    for (float r = 30; r<=170; r*=1.3){
        //ofSetColor(255, 251, 222, opacity/3-r/30); 
        ofSetColor(255, 251, 222, opacity/4-r/50); 
        ofDrawCircle(mouseX, mouseY, r);        
    }



    // aurora
    if (mouseY < height){
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



    //wave in shapes 
    for (int i = 0 ; i<10; i += 2){

        
        //noise_seed[i] = ofRandom(1000);
        float val = ofMap(noise_seed[i], 0, 1000, 10, 55);
        //ofSetColor(ofMap(noise_seed[i], 0, 1000, 30/5, 80/5), ofMap(noise_seed[i], 0, 1000, 130/5, 80/5), ofMap(noise_seed[i], 0, 1000, 150/5, 200/5), ofMap(noise_seed[i], 0, 1000, 5, 45));
        ofSetColor(20+ofMap(ofNoise(i*0.008), 0.3, 0.8, -2, 2),35+ofMap(ofNoise(i*0.02), 0.8, 0.3, -2, 2),40+ofMap(ofNoise(i*0.01), 0.3, 0.7, 0, 30),30+ofMap(ofNoise((i+2)*0.01), 0.3, 0.8, -10, 15)); 
        // 영상용
        //ofSetColor(ofMap(noise_seed[i], 0, 1000, 30*1.5, 80*1.5), ofMap(noise_seed[i], 0, 1000, 130*1.5, 80*1.5), ofMap(noise_seed[i], 0, 1000, 150*1.5, 200*1.5), ofMap(noise_seed[i], 0, 1000, 5, 45) );

        ofBeginShape();
        for (int x = -400; x <= width+400; x += 100) {
		    auto y = ofMap(ofNoise(noise_seed[i], ((x + ofGetFrameNum()) * 0.005)), 0, 1, height/5*3+i*val-val/3, height/5*3+i*val+val/3);
            ofCurveVertex(x, y+val*glm::cos(glm::radians((float)ofGetFrameNum()*0.3)));
	    }
        ofVertex(width+400, height);
        ofVertex(-400, height);
	    ofEndShape();


        
        //noise_seed[i+1] = ofRandom(1000);
        val = ofMap(noise_seed[i+1], 0, 1000, 10, 55);
        //ofSetColor(ofMap(noise_seed[i+1], 0, 1000, 70, 100), ofMap(noise_seed[i+1], 0, 1000, 200, 130), ofMap(noise_seed[i+1], 0, 1000, 200, 255), ofMap(noise_seed[i+1], 0, 1000, 30, 85) );
        ofSetColor(20+ofMap(ofNoise((i+1)*0.008), 0.3, 0.8, -2, 2),35+ofMap(ofNoise((i+1)*0.02), 0.8, 0.3, -2, 2),40+ofMap(ofNoise((i+1)*0.01), 0.3, 0.7, 0, 30),30+ofMap(ofNoise((i+3)*0.01), 0.3, 0.8, -10, 15));
        ofBeginShape();
        for (int x = -400; x <= width+400; x += 100) {
		    auto y = ofMap(ofNoise(noise_seed[i+1], ((x + ofGetFrameNum()) * 0.01)), 0, 1, height/5*3+(i+1)*val-val/3, height/5*3+(i+1)*val+val/3);
            ofCurveVertex(x, y+val*glm::sin(glm::radians((float)ofGetFrameNum()*0.4)));
	    }
        ofVertex(width+400, height);
        ofVertex(-400, height);
	    ofEndShape();
    }
    


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
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
 }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ 
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
