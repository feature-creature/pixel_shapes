#include "ofApp.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    //background black, color white
    ofSetBackgroundColor(255);
    ofSetColor(0);

    // initialize grid
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
    //move grid off of the window edge
    ofTranslate(startPos,startPos);
    //iterate over matrix rows by columns
    for(int i = 0; i < ofGetWidth(); i += spacing){
        for(int j = 0; j < ofGetHeight(); j += spacing){
            int locX = i;
            int locY = j;
            ofPushMatrix();
            ofTranslate(i,j);
            ofDrawCircle(0,0,3);
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
