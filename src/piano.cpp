#include "piano.h"


void piano::white_key_mapped_position() {
	vector<int> piano_keys_white_key = { 9, 81, 87, 69, 82, 84, 89, 85, 73, 79, 80, 91, 93, 92 };
	for (int i = 0; i < piano_keys_white_.size(); i++) {
		white_keys_to_char[piano_keys_white_[i]] = piano_keys_white_key.at(i);
	}
}

void piano::black_key_mapped_position() {
	vector<int> piano_keys_black_key = { 49, 50, 52, 53, 54, 56, 57, 45, 61, 8, 8 };
	for (int i = 0; i < piano_keys_black_.size(); i++) {
		black_keys_to_char[piano_keys_black_[i]] = piano_keys_black_key.at(i);
	}
}

void piano::white_keys() {
	keyNames.load("Quicksand-Regular.otf", 30);
	keyNamesWords.load("Quicksand-Regular.otf", 25);
	int changing_position = 0;
	for (int i = 0; i < 14; i++) {
		ofSetColor(255, 255, 255);
		ofDrawRectangle(white_key_width_position_ + changing_position, white_key_height_position_, 
			white_key_width_, white_key_height_);
		piano::white_typed_key(i, changing_position);
		changing_position += 125;
	}
}

//void piano::draw_full_piano() {
//	keyNamesWords.load("Quicksand-Regular.otf", 25);
//	int changing_position = 0;
//	for (int i = 0; i < 52; i++) {
//		ofSetColor(255, 255, 255);
//		ofDrawRectangle(full_white_width_position_ + changing_position, full_white_height_position_,
//			full_white_width_, full_white_height_);
//		piano::white_typed_key(i, changing_position);
//		changing_position += 125;
//	}
//}

vector<string>& piano::get_piano_keys_white_() {
	return piano_keys_white_;
}

unordered_map<string, int>& piano::get_white_keys_to_char() {
	return white_keys_to_char;
}

vector<string>& piano::get_piano_keys_black_() {
	return piano_keys_black_;
}

unordered_map<string, int>& piano::get_black_keys_to_char() {
	return black_keys_to_char;
}

void piano::white_typed_key(int i, int changing_position) {
	white_keys_to_position[white_keys_to_char.at(piano_keys_white_[i])] = pair<int, int>( //creating hashmap for white keys to position
		white_key_width_position_ + changing_position, white_key_height_position_);
	int font_width = 0;
	ofSetColor(0, 0, 0);
	if (piano_keys_white_[i] == "]") {
		font_width = 10;
	}
	else if (piano_keys_white_[i] == "Tab") {
		font_width = 40;
	}
	else if (piano_keys_white_[i] == "\\") {
		font_width = 15;
	}
	else {
		font_width = 20;
	}
	keyNames.drawString(piano_keys_white_[i],
		white_key_width_position_ + changing_position + (white_key_width_ / 2) - font_width,
		white_key_height_position_ + (7 * white_key_height_ / 8));
}

void piano::black_keys() {
	keyNames.load("Quicksand-Regular.otf", 30);
	keyNamesWords.load("Quicksand-Regular.otf", 25);
	int changing_position = 0;
	bool changing_black_clusters = false;
	int cluster = 0;
	int count = 0;

	for (int i = 0; i < 4; i++) {
		if (changing_black_clusters) {
			cluster = 3;
		}
		else {
			cluster = 2;
		}
		for (int i = 0; i < cluster; i++) {
			ofSetColor(0, 0, 0);
			ofDrawRectangle(black_key_width_position_ + changing_position, black_key_height_position_,
				black_key_width_, black_key_height_);
			black_typed_key(count, changing_position);
			count++;
			changing_position += 125;
		}
		changing_position += 125;
		changing_black_clusters = !changing_black_clusters;
	}
}

void piano::black_typed_key(int i, int changing_position) {
	black_keys_to_position[black_keys_to_char.at(piano_keys_black_[i])] = pair<int, int>( //creating the hashmap of black keys to their position
		black_key_width_position_ + changing_position, black_key_height_position_);
	int font_width = 15;
	ofTrueTypeFont font_holder = keyNames;
	ofSetColor(255, 255, 255);
	if (piano_keys_black_[i] == "Back-") {
		font_width = 48;
		font_holder = keyNamesWords;
		font_holder.drawString(piano_keys_black_[i + 1],
			black_key_width_position_ + changing_position + (black_key_width_ / 2) - font_width,
			black_key_height_position_ + (15 * black_key_height_ / 16));
	}
	else if (piano_keys_black_[i] == "=") {
		font_width = 10;
	}
	font_holder.drawString(piano_keys_black_[i],
		black_key_width_position_ + changing_position + (black_key_width_ / 2) - font_width,
		black_key_height_position_ + (7 * black_key_height_ / 8));
}

void piano::draw_gradient(int key, bool is_white_key_, bool is_black_key_) {
	float percent = 0;
	if (is_white_key_) {
		for (int i = 0; i < 32; i++) {
			percent += .03125;
			ofSetColor(0, 255, 0, 255 * percent); // green, 25% transparent
			ofDrawRectangle(white_keys_to_position.at(key).first, white_keys_to_position.at(key).second, // draws the rect with alpha
				white_key_width_, white_key_height_ - (white_key_height_ * percent));
		}
	}
	else if (is_black_key_) {
		for (int i = 0; i < 32; i++) {
			percent += .03125;
			ofSetColor(0, 255, 0, 255 * percent); // green, 25% transparent
			ofDrawRectangle(black_keys_to_position.at(key).first, black_keys_to_position.at(key).second, // draws the rect with alpha
				black_key_width_, black_key_height_ - (black_key_height_ * percent));
		}
	}
}

void piano::draw_gradient_white(int key) {
	float percent = 0;

	for (int i = 0; i < 32; i++) {
		percent += .03125;
		ofSetColor(0, 255, 0, 255 * percent); // green, 25% transparent
		ofDrawRectangle(white_keys_to_position.at(key).first, white_keys_to_position.at(key).second,
			white_key_width_, white_key_height_ - (white_key_height_ * percent));
	}
}

void piano::draw_gradient_black(int key) {
	float percent = 0;
	for (int i = 0; i < 32; i++) {
		percent += .03125;
		ofSetColor(0, 255, 0, 255 * percent); // green, 25% transparent
		ofDrawRectangle(black_keys_to_position.at(key).first, black_keys_to_position.at(key).second, // draws the rect with alpha
			black_key_width_, black_key_height_ - (black_key_height_ * percent));
	}
}

void piano::draw_key_letters() {

}
void piano::draw_piano() {
	pianoKeys.load("images/piano_keys.gif");
	ofSetColor(255, 255, 255);
	pianoKeys.resize(piano_width_, piano_height_);
	pianoKeys.draw((GetSystemMetrics(SM_CXSCREEN) / 2) - (piano_width_ / 2), 
		(GetSystemMetrics(SM_CYSCREEN) / 2) - (piano_height_ / 2));
}
void piano::piano_sounds_stop() {
	sound.stop();
}
bool piano::piano_sounds(int key) {
	ofEnableAlphaBlending();    // turn on alpha blending
	if (key == 9) {//horizontal tab
		sound.load("piano_keys/28.mp3");
		sound.play();
	}
	if (key == 49) {//1
		sound.load("piano_keys/29.mp3");
		sound.play();
	}
	if (key == 81) {//Q
		sound.load("piano_keys/30.mp3");
		sound.play();
	}
	if (key == 50) {//2
		sound.load("piano_keys/31.mp3");
		sound.play();
	}
	if (key == 87) {//W
		sound.load("piano_keys/32.mp3");
		sound.play();
	}
	if (key == 69) {//E
		sound.load("piano_keys/33.mp3");
		sound.play();
	}
	if (key == 52) {//4
		sound.load("piano_keys/34.mp3");
		sound.play();
	}
	if (key == 82) {//R
		sound.load("piano_keys/35.mp3");
		sound.play();
	}
	if (key == 53) {//5
		sound.load("piano_keys/36.mp3");
		sound.play();
	}
	if (key == 84) {//T
		sound.load("piano_keys/37.mp3");
		sound.play();
	}
	if (key == 54) {//6
		sound.load("piano_keys/38.mp3");
		sound.play();
	}
	if (key == 89) {//Y
		sound.load("piano_keys/39.mp3");
		sound.play();
	}
	if (key == 85) {//U
		sound.load("piano_keys/40.mp3");
		sound.play();
	}
	if (key == 56) {//8
		sound.load("piano_keys/41.mp3");
		sound.play();
	}
	if (key == 73) {//I
		sound.load("piano_keys/42.mp3");
		sound.play();
	}
	if (key == 57) {//9
		sound.load("piano_keys/43.mp3");
		sound.play();
	}
	if (key == 79) {//O
		sound.load("piano_keys/44.mp3");
		sound.play();
	}
	if (key == 80) {//P
		sound.load("piano_keys/45.mp3");
		sound.play();
	}
	if (key == 45) {//-
		sound.load("piano_keys/46.mp3");
		sound.play();
	}
	if (key == 91) {//[
		sound.load("piano_keys/47.mp3");
		sound.play();
	}
	if (key == 61) {//=
		sound.load("piano_keys/48.mp3");
		sound.play();
	}
	if (key == 93) {//]
		sound.load("piano_keys/49.mp3");
		sound.play();
	}
	if (key == 8) {//backspace
		sound.load("piano_keys/50.mp3");
		sound.play();
	}
	if (key == 92) {//(\)
		sound.load("piano_keys/51.mp3");
		sound.play();
	}
	if (key == 9) {//Enter
		sound.load("piano_keys/52.mp3");
		sound.play();
	}
	return true;
}

bool piano::released_piano_key(int key) {
	int white_key = 0;
	int black_key = 0;
	int upper_key = toupper(key); // Standardize on upper case

	for (int i = 0; i < piano_keys_white_.size(); i++) {
		stringstream string_to_key(piano_keys_white_[i]);
		string_to_key >> white_key;
		if (key == white_key) {
			return false;
		}
	}

	for (int i = 0; i < piano_keys_black_.size(); i++) {
		stringstream string_to_key(piano_keys_black_[i]);
		string_to_key >> black_key;
		if (key == black_key) {
			return false;
		}
	}
	return true;
}