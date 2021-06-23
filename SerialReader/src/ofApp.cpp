#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    myArduino.connect("/dev/tty/usb0", 115200);
}

//--------------------------------------------------------------
void ofApp::draw(){
    // we want to read 8 bytes
    int bytesRequired = 8;
    unsigned char bytes[bytesRequired];
    int bytesRemaining = bytesRequired;
    cout << "nothing is read";
    printf("hello");
    // loop until we've read everything
    while ( bytesRemaining > 0 )
    {
    // check for data
        if ( mySerial.available() > 0 ) {
            // try to read - note offset into the bytes[] array, this is so
            // that we don't overwrite the bytes we already have
            int bytesArrayOffset = bytesRequired - bytesRemaining;
            int result = mySerial.readBytes(&bytes[bytesArrayOffset], bytesRemaining);

            // check for error code
            if ( result == OF_SERIAL_ERROR) { // something bad happened
                ofLog( OF_LOG_ERROR, "unrecoverable error reading from serial" );
                break;
            }
            else if ( result == OF_SERIAL_NO_DATA ) { // nothing was read, try again
                cout << "nothing is read";
            }
            else {
                // we read some data!
                bytesRemaining -= result;
                cout << result;
            }
        }
    }
}
