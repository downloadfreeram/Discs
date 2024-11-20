#include "ofApp.h"
#include <random>
#include <vector>
	
float vis = 0.0001;
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
		discs.emplace_back(pos, vel, discRad, mass, col,vis);


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
	center.set(x, y);
	std::cout << "Point changed to X: " << x << " and Y: " << y << std::endl;
	float distanceFromCenter = ofVec2f(x, y).distance(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2));

	// change viscosity depending on distance from center
	if (distanceFromCenter <= 50) {
		vis = 0.0001; 
	}
	else if(distanceFromCenter <= 150 && distanceFromCenter > 50) {
		vis = 0.001;
	}
	else {
		vis = 0.01;
	}
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
