#include "ofApp.h"
#include <random>
#include <vector>
	
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	center.set(ofGetWidth() / 2, ofGetHeight() / 2);

	for (int i = 0;i < N;i++)
	{
		ofVec2f pos(ofRandom(discRad, ofGetWidth() - discRad), 
			ofRandom(discRad, ofGetHeight() - discRad));
		ofVec2f vel(ofRandom(-2, 2), ofRandom(-2, 2));
		ofColor col(ofRandom(255), ofRandom(255), ofRandom(255));
		discs.emplace_back(pos, vel, discRad, col);
	}
}
//--------------------------------------------------------------
void ofApp::update(){
	for (auto& disc : discs)
	{
		disc.force(center,strength);
		disc.move();
		disc.check(ofGetWidth(),ofGetHeight());
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (const auto& disc : discs)
	{
		ofSetColor(disc.color);
		ofDrawCircle(disc.Pos, disc.radius);
	}
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
