#include "ofApp.h"
#include <random>
#include <vector>
	
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	center.set(ofGetWidth() / 2, ofGetHeight() / 2);

	for (int i = 0;i < N;i++)
	{
		float discRad = ofRandom(1, 3);
		float mass = ofRandom(1, 5);
		ofVec2f pos(ofRandom(discRad, ofGetWidth() - discRad), 
			ofRandom(discRad, ofGetHeight() - discRad));
		ofVec2f vel(ofRandom(-5, 5), ofRandom(-5, 5));
		ofColor col(ofRandom(255), ofRandom(255), ofRandom(255));
		discs.emplace_back(pos, vel, discRad, mass, col);


	}
}
//--------------------------------------------------------------
void ofApp::update(){
	float dt = 1.0 / 60.0;
	for (auto& disc : discs)
	{
		disc.move(center,dt,20000.0);
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
