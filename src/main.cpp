#include "ofMain.h"
#include "ofApp.h"

//width 1024
//height 768
int width = 1024;
int height = 768;
//OF_WINDOW
//========================================================================
int main( ){
	ofSetupOpenGL(width,height,OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new MusicPlay(width, height));

}
