#pragma once

#include "ofMain.h"
#include "ofxGui/src/ofxGui.h"

class button {
	ofImage button;
	ofTrueTypeFont playButtonName;
	ofColor color;
public:
	void draw_play_button(ofxButton playButton);
	void play_button();
	int button::get_size_of_button_X();
	int button::get_size_of_button_Y();
	int button::get_position_of_button_X();
	int button::get_position_of_button_Y();
private:
	int fullscreen_width_ = GetSystemMetrics(SM_CXSCREEN);
	int fullscreen_height_ = GetSystemMetrics(SM_CYSCREEN);
	int x;
	int y;
	int size_of_button_X = 400;
	int size_of_button_Y = 100;
	int position_of_button_X = (fullscreen_width_ / 2) - 150;
	int position_of_button_Y = (fullscreen_height_ / 2) - 210;
};