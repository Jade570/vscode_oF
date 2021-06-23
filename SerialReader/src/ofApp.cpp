#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    myArduino.connect("/dev/tty/usb0", 115200);
}

//--------------------------------------------------------------
void ofApp::update(){
    // we want to read 8 bytes
    int bytesRequired = 8;
    unsigned char bytes[bytesRequired];
    int bytesRemaining = bytesRequired;
    // loop until we've read everything
    while ( bytesRemaining > 0 )
    {
    // check for data
    if ( serial.available() > 0 )
    {
        // try to read - note offset into the bytes[] array, this is so
        // that we don't overwrite the bytes we already have
        int bytesArrayOffset = bytesRequired - bytesRemaining;
        int result = serial.readBytes( &bytes[bytesArrayOffset],
        bytesRemaining );

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
        }
    }
    }
}
