#include "ofApp.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    //background white, default color black
    ofSetBackgroundColor(255);
    ofSetColor(0);

    //initialize matrix
    spacing = 10;
    startPos = spacing/2;

    /*
        initialize camera
        list possible cameras (optional)
        select camera
        set camera framerate
        set camera resolution to window size
    */
    vidGrabber.listDevices();
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(ofGetWidth(), ofGetHeight());

    //initialize mode
    mode = 1;

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
    //64*48 circles (3074 total)
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
            int maxSize = spacing;

            ofSetColor(c);
            ofPushMatrix();
            ofTranslate(i,j);

            if(mode == 1){
                float radius = ofMap(brightness,0,255,maxSize,0);
                ofDrawCircle(0,0,radius);
            }

            if(mode == 2){
                maxSize = ofMap(mouseX,0,ofGetWidth(),0,spacing*4);
                float length = ofMap(brightness,0,255,maxSize,3);
                ofSetLineWidth(ofMap(brightness,0,255,3,1));
                ofRotate(ofMap(brightness,0,255,0,180));
                ofDrawLine(0,0,0,length);
            }

            ofPopMatrix();
        }
    }
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // save a png screenshot for documentation in bin/data
    // use date and framerate for unique naming
    if(key == 's'){
        ofSaveScreen(ofGetTimestampString() + "-" + ofToString(ofGetFrameNum()) + ".png");
    }
    if(key == '1'){
        mode = 1;
    }
    if(key == '2'){
        mode = 2;
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
