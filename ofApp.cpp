/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp(){
	printf("ofApp::ctr\n");
	fflush(stdout);
}

/******************************
******************************/
ofApp::~ofApp(){
	printf("ofApp::dtr\n");
	fflush(stdout);
}

/******************************
******************************/
void ofApp::exit(){
	printf("\nofApp::exit\n");
	fflush(stdout);
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("main");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(WINDOW_W, WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	ofSetCircleResolution(200);
	
	/********************
	********************/
	for(int i = 0; i < NUM_FBO; i++){
		fbo[i].allocate(FBO_W, FBO_H, GL_RGBA);
	}
	
	/********************
	********************/
	player.load("mov/LIVEAID.mp4");
	player.setLoopState(OF_LOOP_NORMAL);
	player.setSpeed(1);
	// player.setVolume(1.0);
	player.setVolume(0.0);
	player.setPaused(false);
	player.play();
	player.setPosition(0); // *.movは、"OF_LOOP_NONE"の時、明示的にsetPosition(0) しないと、戻らないようだ. : seekをplay の後に移動(2020.10.08)
}

/******************************
******************************/
void ofApp::update(){
	/********************
	********************/
	player.update();
	if(player.isFrameNew()){
		fbo[0].begin();
			ofClear(0);
			ofSetColor(255);
			
			player.draw(0, 0, fbo[0].getWidth(), fbo[0].getHeight());
		fbo[0].end();
	}
	
	/********************
	********************/
	int now = ofGetElapsedTimeMillis();
	const int T = 10000;
	const float Amp = 100;
	
	fbo[1].begin();
		ofClear(0, 0, 0, 0);
		ofSetColor(255, 0, 0, 255);
		
		float radius = Amp * ( sin(2 * 3.14 * now / T) + 1 );
		ofDrawCircle(fbo[1].getWidth()/2, fbo[1].getHeight()/2, radius);
	fbo[1].end();
	
	/********************
	********************/
	printf("main::update : %5.1f\r", ofGetElapsedTimef());
	fflush(stdout);
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	
	/********************
	********************/
	fbo[0].draw(0, 0, fbo[0].getWidth(), fbo[1].getHeight());
	fbo[1].draw(fbo[0].getWidth(), 0, fbo[1].getWidth(), fbo[1].getHeight());
}

/******************************
******************************/
void ofApp::keyPressed(int key){

}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
