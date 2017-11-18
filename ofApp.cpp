#include "ofApp.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    //background white, default color black
    ofSetBackgroundColor(255);
    ofSetColor(0);

    // initialize matrix
    spacing = 10;
    startPos = spacing/2;

    /*
        camera initialization process
        list possible cameras (optional)
        select camera
        set camera framerate
        set camera resolution to window size
    */
    vidGrabber.listDevices();
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(ofGetWidth(), ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    pixels = vidGrabber.getPixels();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    //move entire matrix away from the window edge
    ofTranslate(startPos,startPos);
    //iterate over matrix rows by columns
    for(int i = 0; i < ofGetWidth(); i += spacing){
        for(int j = 0; j < ofGetHeight(); j += spacing){
            //SHAPE
            //location
            int locX = i;
            int locY = j;
            //color
            ofColor c = pixels.getColor(i,j);
            //radius
            //inverse relationship between brightness and size
            //dependent on white background
            int brightness = c.getBrightness();
            int maxSize = 10;
            float radius = ofMap(brightness,0,255,maxSize,0);

            ofSetColor(c);
            ofPushMatrix();
            ofTranslate(i,j);
            ofDrawCircle(0,0,radius);
            ofPopMatrix();
        }
    }
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
