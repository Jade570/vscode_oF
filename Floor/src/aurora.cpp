#include "aurora.h"

void aurora::Create(int px, int py, int x, int y, int framenum){
	Reset();
	IsShowing = true;
	pX = px;
	pY = py;
	xPos = x;
	yPos = y;
	frameNum = framenum;
}

void aurora::Reset(){
	IsShowing = false;
	opacity = 0;
	pX = -1;
	pY = -1;
	xPos = -1; 
	yPos = -1;
}

void aurora::Show(int r, int g, int b, int a, float noise, int height){	
	int minus=(ofGetFrameNum()-frameNum);
	opacity = a - minus;
	opacity -= ofMap(yPos, 0, height/10*9, 0, opacity);
	Noise = noise;
	
	if (IsShowing == true){
		if (opacity > 0){
			//background white
				ofSetColor(255,255,255,opacity/15);
				ofBeginShape();
				ofVertex(pX, pY+55);
				ofVertex(xPos, yPos+55);
				ofVertex(xPos, yPos-210);
				ofVertex(pX, pY-210);
				ofEndShape();

			// main green
			for (int i = 0 ; i <25; i++){
				ofSetColor(r,255,ofClamp(b-i*10, 0, 255),opacity/10);
				ofBeginShape();
				ofVertex(pX, pY+25 - i);
				ofVertex(xPos, yPos+25 - i);
				ofVertex(xPos, yPos-100 + ofClamp(i*4* Noise, 0, 100) );
				ofVertex(pX, pY-100 + ofClamp(i*4* Noise, 0, 100));
				ofEndShape();
			}
		}
		else{
			Reset();
		}
	}
}
