#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //initialize

    numOfXTiles = 20;
    numOfYTiles = 20;
    objSizeH = 5;
    spacingY = ofGetHeight()/numOfYTiles;
    objSizeW = 30;
    spacingX = ofGetWidth()/numOfXTiles;


    ofSetBackgroundColor(0);
    ofSetColor(200);
//    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetCircleResolution(50);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // center the shapes
    ofTranslate(spacingX/2,spacingY/2);
    for(int x = 0; x < numOfXTiles; x++)
    {
        for(int y = 0; y < numOfYTiles; y++)
        {
            float locX = x*spacingX;
            float locY = y*spacingY;
            float angle = atan2(mouseY - locY,mouseX - locX);
            float shapeDist = ofDist(mouseX,mouseY,locX,locY);
            float objSize = ofMap(shapeDist,0,ofGetWidth(),10,0.5, true);

            float colorFactor = ofMap(shapeDist,0,ofGetWidth(),0,1, true);
            ofColor blue(0,0,255);
            ofColor yellow(255,255,0);
            ofColor objColor = blue.getLerped(yellow, colorFactor);




            ofPushMatrix();
            ofTranslate(locX,locY);
            // rotate in the (opposite + 180) direction from the mouse
            ofRotate(ofRadToDeg(angle) + 180);
            // translate 100 from the direction of the mouse
            ofTranslate(100,0);
            //ofDrawRectangle(0,0,objSizeW,objSizeH);
            // set color on a range of yellow and blue dependent on distance from mouse
            ofSetColor(objColor);
            ofDrawCircle(0,0,objSize);
            ofPopMatrix();
        }
    }

    // print mouse coordinates to window
//    ofDrawBitmapString(ofToString(mouseX) + " : " + ofToString(mouseY),mouseX,mouseY);
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
