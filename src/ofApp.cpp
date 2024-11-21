#include "ofApp.h"
#include <random>
#include <vector>

float vis = 0.0001;
//--------------------------------------------------------------
void ofApp::setup(){
	std::cout << "Number of discs:" << N << std::endl;
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
void ofApp::update() {
	float dt = 1.0 / 60.0;

	std::vector<ofVec2f> allAttractionPoints = attractionPoints;
	allAttractionPoints.push_back(center);

	for (auto& disc : discs) {
		disc.move(allAttractionPoints, dt, 20000.0,vis);
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
	if (key == 'z' || key == 'Z') {
		if (!attractionPoints.empty()) {
			attractionPoints.pop_back();
			std::cout << "Removed last attraction point." << std::endl;
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
	if (button == OF_MOUSE_BUTTON_RIGHT) {
		attractionPoints.emplace_back(x, y);
		std::cout << "Added attraction point at X: " << x << " Y: " << y << std::endl; 
		float distanceFromCenter = ofVec2f(x, y).distance(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2));

		// change viscosity depending on distance from center
		if (distanceFromCenter <= 50) {
			vis = 0.0001;
			std::cout << "Viscosity for those coordinates is: " << vis << std::endl;
		}
		else if (distanceFromCenter <= 150 && distanceFromCenter > 50) {
			vis = 0.001;
			std::cout << "Viscosity for those coordinates is: " << vis << std::endl;
		}
		else {
			vis = 0.01;
			std::cout << "Viscosity for those coordinates is: " << vis << std::endl;
		}
	}
	else if (button == OF_MOUSE_BUTTON_LEFT) {
		center.set(x, y);
		std::cout << "Main point changed to X: " << x << " Y: " << y << std::endl;
		float distanceFromCenter = ofVec2f(x, y).distance(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2));

		// change viscosity depending on distance from center
		if (distanceFromCenter <= 50) {
			vis = 0.0001;
			std::cout << "Viscosity for those coordinates is: " << vis << std::endl;
		}
		else if (distanceFromCenter <= 150 && distanceFromCenter > 50) {
			vis = 0.001;
			std::cout << "Viscosity for those coordinates is: " << vis << std::endl;
		}
		else {
			vis = 0.01;
			std::cout << "Viscosity for those coordinates is: " << vis << std::endl;
		}
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
