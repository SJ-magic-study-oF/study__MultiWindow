/************************************************************
************************************************************/
#include "Second.h"

/************************************************************
************************************************************/

/******************************
******************************/
Second::Second(){
	printf("Second::ctr\n");
	fflush(stdout);
}

/******************************
******************************/
Second::~Second(){
	printf("Second::dtr\n");
	fflush(stdout);
}

/******************************
******************************/
void Second::exit(){
	printf("\nSecond::exit\n");
	fflush(stdout);	
}

/******************************
******************************/
void Second::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("second");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(WINDOW_W, WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	ofSetCircleResolution(6);
}

/******************************
******************************/
void Second::update(){

}

/******************************
******************************/
void Second::draw(){
	ofBackground(0);
	ofSetColor(255);
	
	if( (0 <= id) && (id < 2) ){
		// main_obj->fbo[id].getTexture().draw(0, 0, ofGetWidth(), ofGetHeight());
		main_obj->fbo[id].draw(0, 0, ofGetWidth(), ofGetHeight());
	}else{
	
		ofSetColor(main_obj->col);
		
		int now = ofGetElapsedTimeMillis();
		const int T = 10000;
		const float Amp = 100;
		
		float radius = Amp * ( sin(2 * 3.14 * now / T) + 1 );
		ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
	}
}

/******************************
******************************/
void Second::keyPressed(int key){
	switch(key){
		case '0':
		case '1':
		case '2':
			id = key - '0';
			break;
			
		case 'f':
			ofSetFullscreen(true);
			break;
			
		case 'w':
			ofSetFullscreen(false);
			ofSetWindowShape(WINDOW_W, WINDOW_H);
			break;
	}
}

/******************************
******************************/
void Second::keyReleased(int key){

}

/******************************
******************************/
void Second::mouseMoved(int x, int y ){

}

/******************************
******************************/
void Second::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void Second::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void Second::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void Second::mouseEntered(int x, int y){

}

/******************************
******************************/
void Second::mouseExited(int x, int y){

}

/******************************
******************************/
void Second::windowResized(int w, int h){

}

/******************************
******************************/
void Second::gotMessage(ofMessage msg){

}

/******************************
******************************/
void Second::dragEvent(ofDragInfo dragInfo){ 

}
