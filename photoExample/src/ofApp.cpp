#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    photo.init();
    bCamIsBusy = false;
    test.allocate(1024,1024,OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

                if(photo.captureSucceeded()){
                    printf("Trying to load data...\n");
                    pic = photo.capture();
                    test.setFromPixels(pic,photo.getCaptureWidth(),photo.getCaptureHeight(),OF_IMAGE_COLOR,0);
                    printf("Loading finished!\n");
                    test.resize(1024,768);
                }
}

//--------------------------------------------------------------
void ofApp::draw(){
    test.draw(0,0,ofGetHeight(), ofGetHeight());
    ofDrawBitmapString(ofToString(ofGetFrameRate()) + " fps",20,20);
    ofDrawBitmapString("Press space to take a photo...",20,35);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        if(!photo.isBusy()){
            photo.startCapture();
        }
        else {
            printf("Cam is busy.\n");
        }
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
void ofApp::windowResized(int w, int h){

}

void ofApp::exit(){
    photo.exit();
}
