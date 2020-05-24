#include "startingScreen.h"

//startingScreen() {
//	screen_dims_.set(width, height);
//}
void startingScreen::draw_starting_background() {
	ofSetColor(255, 255, 255);
	//ofDrawRectangle(0, 0, fullscreen_width_, fullscreen_height_);
	piano.load("images/piano_picture.jpeg");
	//https://www.pexels.com/search/piano/
	piano.draw(0, 0, fullscreen_width_, fullscreen_height_);
}

void startingScreen::draw_title() {
	title.load("Quicksand-Regular.otf", 150);
	ofSetColor(0, 0, 0);
	title.drawString("Piano Keyboard", (fullscreen_width_ / 2) - 750, fullscreen_height_ / 3);
}

//void startingScreen::resize_starting_screen(int w, int h) {
//	float new_x = ((0 / screen_dims_.x) * w);
//	float new_y = ((0 / screen_dims_.y) * h);
//	draw_starting_background()
//}