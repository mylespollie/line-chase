#pragma once

#include "ofMain.h"
#include <math.h> 

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

		int line_length_x = 2;
		int line_length_y = 2;
		int line_length_z = 2;
		
		int total_length = 1;
		float line_width = 1;

		ofPolyline lines;
		ofEasyCam cam;

		int fov_change = 1;

		int r_color = 0;
		int g_color = 0;
};
