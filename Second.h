/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofApp.h"

/************************************************************
************************************************************/
class Second : public ofBaseApp{
private:
	enum{
		WINDOW_W = 640,
		WINDOW_H = 360,
	};
	int id = -1;
	
public:
	Second();
	~Second();
	void exit();
	
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
	
	shared_ptr<ofApp> main_obj;
};
