#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    serial.listDevices();
    serial.setup("/dev/ttyUSB0", 9600);
}

//--------------------------------------------------------------
void ofApp::update(){

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

            cout << bytes << endl;
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
        }
    }
}
