#include "button.h"

void button::draw_play_button(ofxButton playButton) {
	playButtonName.load("Quicksand-Bold.otf", 50);
	ofSetColor(0, 0, 0);
	playButton.setSize(400, 150);
	playButton.setTextColor(color.black);
	playButton.setBackgroundColor(color.lightGreen);
	playButton.setPosition((fullscreen_width_ / 2) - 150, (fullscreen_height_ / 2) - 250);
	playButton.draw();
	playButtonName.drawString("Play", (fullscreen_width_ / 2) - 150 + 125, (fullscreen_height_ / 2) - 350 + 212.5);
}

//void button::play_button() {
//	
//}

int button::get_size_of_button_X() {
	return size_of_button_X;
}

int button::get_size_of_button_Y() {
	return size_of_button_Y;
}

int button::get_position_of_button_X() {
	return position_of_button_X;
}

int button::get_position_of_button_Y() {
	return position_of_button_Y;
}