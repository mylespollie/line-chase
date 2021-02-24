#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(190, 183, 237);
	lines.addVertex(0, 0, 0);
	ofSetFrameRate(60);

	ofSetupOpenGL(ofGetWindowWidth(), ofGetWindowHeight(), OF_WINDOW);

	cam.enableInertia();
	cam.setFov(90);
	ofSetVerticalSync(true);
	ofEnableDepthTest();
	ofSetLineWidth(2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	cam.rollDeg(1);
	//cam.setFov(cam.getFov() + fov_change);

	if (lines.size() >= 10000) {
		lines.clear();
		lines.addVertex(0, 0, line_length_z);
	}

	if (cam.getFov() >= 140 || cam.getFov() <= 90) {
		fov_change = -fov_change;
	}
	//ofDrawGrid(250, ofGetWidth(), false, true, true, true);

	if (total_length >= 10000) {
		line_length_x = -line_length_x;
		line_length_y = -line_length_y;
		//line_length_z = -line_length_z;
	}

	lines.curveTo(line_length_x, line_length_y, line_length_z);
	line_length_x += ofRandom(-10, 10);
	line_length_y += ofRandom(-10, 10);
	line_length_z = line_length_z-2;

	total_length++;
	

	ofSetLineWidth(sin(line_width)* 100);
	line_width += 0.05;

	//lines.simplify();
	int last_node = lines.size() - 1;

	cam.setTarget(ofVec3f(lines[last_node].x / 20, lines[last_node].y / 20, lines[last_node].z));
	cam.setPosition(0, 0, lines[last_node].z + 100);
	lines.getSmoothed(2*(ofGetMouseX()+ofGetWindowWidth()/2)/ofGetWindowWidth()/2, 0);

	if (sin(line_width) >= 0.98) {
		ofSetBackgroundColor(255, 255, 255);
		ofSetColor(0, 0, 0);
		lines.addVertex(ofRandom(-250, 250), ofRandom(-250, 250), line_length_z);
		lines.addVertex(ofRandom(-250, 250), ofRandom(-250, 250), ofRandom(line_length_z - 20, line_length_z + 20));
	}
	else {
		ofSetBackgroundColor(0, 0, 0);
		ofSetColor(r_color, g_color, 255);
	}

	if (r_color == 200) {
		r_color = 0;
		g_color = 0;
	}
	r_color++;
	g_color++;
	lines.draw();
	

	cam.end();
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
	ofSetBackgroundColor(255, 255, 255);
	ofSetColor(0, 0, 0);
	lines.addVertex(ofRandom(-250, 250), ofRandom(-250, 250), line_length_z);
	lines.addVertex(ofRandom(-250, 250), ofRandom(-250, 250), ofRandom(line_length_z - 20, line_length_z + 20));
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(r_color, g_color, 255);
	draw();
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
