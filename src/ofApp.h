#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp, public ofxMidiListener {
    
    
	public:
		void setup();
		void update();
		void draw();
    	void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void newMidiMessage(ofxMidiMessage& eventArgs);
    
        stringstream text;
    
        ofxMidiIn midiIn;
        ofxMidiMessage midiMessage;
    
        bool bHide;
        ofxPanel gui;
        ofParameter<int> midiControl;
        ofParameter<int> cSlider1;
        ofParameter<int> cSlider2;
        ofParameter<int> cSlider3;
};
