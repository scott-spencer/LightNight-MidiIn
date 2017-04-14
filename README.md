# LightNight-MidiIn
Repository for OpenFrameworks code LN2017. The OfxMidi addon with a small amount of ofxGui integration

To use with visual studio Dan
- generate a new project called LightNight-Midi and add ofxMidi and ofxGui addons
- swap Src and Bin folders

This example draws message values from fader control numbers 12, 13 and 14 in ofxPanel. Look at newMidiMessage in ofApp.cpp

midiIn gives port infomation, name, number, etc
newMidiMessage is the message written to the the listener
CC messages are:
midiMessage.status - MIDI_CONTROL_CHANGE or 176
midiMessage.control - control channels. 0-7 dials, 10-17 faders
midiMessage.value - value 0-127
