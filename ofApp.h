/************************************************************
■ネイティブ対応したマルチウィンドウの実験
	https://leico.github.io/TechnicalNote/OpenFrameworks/multiwindow

■マルチウィンドウ間で映像を共有する
	https://qiita.com/y_UM4/items/aa13f2ad4dc2a9896f79
	
		contents
			settings.shareContextWith = mainWindow; 
			の一文を書くことで、
			texure(Graphic memory)領域を、mainWindowと共有することが できる。
			この設定がないと、fboなど、texture関連memoryの やり取りができない。

■tips
		settings.resizable = false;
	とすると、最大化ボタンが無効状態となる。
	But : 
		ofSetFullscreen(true);
	の後、
		ofSetFullscreen(false);
		ofSetWindowShape(WINDOW_W, WINDOW_H);
	とすると、最大化ボタンが有効になった。
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	enum{
		WINDOW_W = 1280,
		WINDOW_H = 360,
		
		FBO_W = 640,
		FBO_H = 360,
	};
	enum{
		NUM_FBO = 2,
	};
	
	ofVideoPlayer player;
	
public:
	ofColor col = ofColor(0, 0, 255, 255);
    ofFbo fbo[NUM_FBO];
	
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
		
};
