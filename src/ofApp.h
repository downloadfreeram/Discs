#pragma once

#include "ofMain.h"
#include <vector>

class Disc {
public:
	ofVec2f Pos;
	ofVec2f Vel;
	ofColor color;
	float radius;
	float mass;
	Disc(ofVec2f pos, ofVec2f vel, float rad, float mass, ofColor col) :Pos(pos), Vel(vel), radius(rad), color(col), mass(mass) {};

	void move(ofVec2f center, float dt, float attractionStrength)
	{
		ofVec2f direction = center - Pos;
		float r = direction.length();
		if (r > 10.0f)
		{
			direction.normalize();
			float F = attractionStrength / (r * r);
			ofVec2f force = F * direction;

			ofVec2f acceleration = force / mass;
			Vel += acceleration * dt;


		}

		Pos += Vel * dt;

		if (Pos.x < radius) {
			Pos.x = radius;
			Vel.x *= -1;
		}
		if (Pos.x > ofGetWidth() - radius) {
			Pos.x = ofGetWidth() - radius;
			Vel.x *= -1;
		}
		if (Pos.y < radius) {
			Pos.y = radius;
			Vel.y *= -1;
		}
		if (Pos.y > ofGetHeight() - radius) {
			Pos.y = ofGetHeight() - radius;
			Vel.y *= -1;
		}
	}
};
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
private:
	std::vector <Disc> discs;
	int N = 1000;
	ofVec2f center;

};
