#include "ofMain.h"
#include "ofApp.h"
#include "Second.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;

    settings.setSize(600, 600);
	settings.setPosition(glm::vec2(300,0));
	settings.resizable = true;
	// settings.shareContextWith = secondWindow;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	
    settings.setSize(300, 300);
	settings.setPosition(glm::vec2(0,0));
	settings.resizable = true;
	settings.shareContextWith = mainWindow; // texure(Graphic memory)領域は、mainWindowと共有する : この設定がないと、fboなど、texture関連memoryの やり取りができない。
	shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
	
	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<Second> secondApp(new Second);
	secondApp->main_obj = mainApp;

	ofRunApp(mainWindow, mainApp);
	ofRunApp(secondWindow, secondApp);
	ofRunMainLoop();
}
