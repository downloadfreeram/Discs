#pragma once

#include "ofMain.h"
#include <vector>

class Disc {
public:
	ofVec2f Pos;
	ofVec2f Vel;
	ofColor color;
	float radius;
	Disc(ofVec2f pos, ofVec2f vel, float rad, ofColor col) :Pos(pos), Vel(vel), radius(rad), color(col) {};

	void move()
	{
		Pos += Vel;
	}

	void check(int height, int width)
	{
		if (Pos.x - radius < 0 || Pos.x - radius > width)
		{
			Vel.x *= -1;
		}
		if (Pos.y - radius < 0 || Pos.y - radius > height)
		{
			Vel.y *= -1;
		}
	}
	void force(ofVec2f center, float strength)
	{
		ofVec2f direction = center - Pos;
		float distance = direction.length() + 1e-5; // adding small value to avoid dividing by zero
		direction.normalize();

		float forceMagnitude = strength / (distance * distance);
		ofVec2f force = direction * forceMagnitude;

		Vel += force;
	}
};
class ofApp : public ofBaseApp{

	public:
		int xPos = 0;
		int xVel = 2;
		int yPos = 0;
		int yVel = 2;

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
	float discRad = 5.0;
	float strength = 500.0;
	ofVec2f center;
};
