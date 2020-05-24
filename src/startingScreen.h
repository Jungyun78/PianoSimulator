#pragma once

#include "ofMain.h"

class startingScreen {
	//ofRectangle rectangle;
	ofTrueTypeFont title;
	ofImage piano;
public:
	void draw_starting_background();
	void draw_title();
	void resize_starting_screen(int w, int h);
private:
	ofVec2f screen_dims_; // The current screen dimensions (needed to calculate values on resize()
	int fullscreen_width_ = GetSystemMetrics(SM_CXSCREEN);
	int fullscreen_height_ = GetSystemMetrics(SM_CYSCREEN);
	int width = ofGetWindowWidth();
	int height = ofGetWindowHeight();
};