#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofBackground(255, 255, 255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // print input ports to console
    midiIn.listPorts(); // via instance
    //ofxMidiIn::listPorts(); // via static as well
    // open port by number (you may need to change this)
    midiIn.openPort(1);
    //midiIn.openPort("IAC Pure Data In");	// by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
    
    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, true, true);
    
    // add ofApp as a listener
    midiIn.addListener(this);
    
    //midiIn.getPort();
    
    // print received messages to the console
    midiIn.setVerbose(true);
    
    gui.setup();
    gui.add(midiControl.set("Control", 10, 10, 17));
    
    // alternitevily we can deplicate sliders by creating a Class
    // using parameterGroup and looping through an array
    gui.add(cSlider1.set("Slider 1", 0, 0, 254));
    gui.add(cSlider2.set("Slider 2", 0, 0, 254));
    gui.add(cSlider3.set("Slider 3", 0, 0, 254));
    
    bHide = false;

}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(0);
    
    
    // draw the last recieved message contents to the screen
    text << "Received: " << ofxMidiMessage::getStatusString(midiMessage.status);
    ofDrawBitmapString(text.str(), 220, 20);
    text.str(""); // clear
    
    text << "channel: " << midiMessage.channel;
    ofDrawBitmapString(text.str(), 220, 34);
    text.str(""); // clear
    
    text << "pitch: " << midiMessage.pitch;
    ofDrawBitmapString(text.str(), 220, 48);
    text.str(""); // clear
    ofDrawRectangle(220, 58, ofMap(midiMessage.pitch, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "velocity: " << midiMessage.velocity;
    ofDrawBitmapString(text.str(), 220, 96);
    text.str(""); // clear
    ofDrawRectangle(220, 105, ofMap(midiMessage.velocity, 0, 127, 0, ofGetWidth()-40), 20);
    
    text << "control: " << midiMessage.control;
    ofDrawBitmapString(text.str(), 220, 144);
    text.str(""); // clear

    text << "delta: " << midiMessage.deltatime;
    ofDrawBitmapString(text.str(), 220, 192);
    text.str(""); // clear
    
    if(!bHide){
    gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    // clean up
    midiIn.closePort();
    midiIn.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {
    
    // make a copy of the latest message
    midiMessage = msg;
    
    midiControl = midiMessage.control;
    
    //Faders on microKontrol are control numbers 10-17
    if(midiMessage.status == MIDI_CONTROL_CHANGE) {
        midiMessage.value = midiMessage.value*2;
        
        switch(midiControl) {
            case 12:
                cSlider1 = midiMessage.value;
                break;
            case 13:
                cSlider2 = midiMessage.value;
                break;
            case 14:
                cSlider3 = midiMessage.value;
                break;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    switch(key) {
        case 'l':
            midiIn.listPorts();
            break;
        case 'h':
            bHide = !bHide;
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
