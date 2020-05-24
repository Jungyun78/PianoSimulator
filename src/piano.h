#pragma once

#include "ofMain.h"

class piano {
	ofSoundPlayer sound;
	ofImage pianoKeys;
	ofTrueTypeFont keyNames;
	ofTrueTypeFont keyNamesWords;
	//ofSoundStream soundStream;
public:
	bool piano_sounds(int key);
	bool released_piano_key(int key);
	void draw_piano();
	void white_keys();
	void piano::black_keys();
	void piano::draw_key_letters();
	void piano::draw_gradient(int key, bool is_white_key, bool is_black_key_);
	void piano::draw_gradient_white(int key);
	void piano::draw_gradient_black(int key);
	void piano::black_typed_key(int i, int changing_position);
	void piano::white_typed_key(int i, int changing_position);
	void piano::white_key_mapped_position();
	void piano::black_key_mapped_position();
	vector<string>& piano::get_piano_keys_white_();
	unordered_map<string, int>& piano::get_white_keys_to_char();
	vector<string>& piano::get_piano_keys_black_();
	unordered_map<string, int>& piano::get_black_keys_to_char();
	void piano::piano_sounds_stop();
	void draw_full_piano();
private:

	int piano_width_ = 3036;
	int piano_height_ = 548;
	int white_key_width_ = 120;
	int white_key_height_ = 800;
	int black_key_width_ = 100;
	int black_key_height_ = 500;
	double white_key_width_position_ = (GetSystemMetrics(SM_CXSCREEN) / 2) - (((white_key_width_ * 14) + (14 * 5)) / 2);
	double white_key_height_position_ = (GetSystemMetrics(SM_CYSCREEN) / 2) - (white_key_height_ / 2);
	double black_key_width_position_ = white_key_width_position_ + (white_key_width_ / 2) + (20 / 2) + (5 / 2);
	double black_key_height_position_ = white_key_height_position_;
	vector<string> piano_keys_white_ = { "Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\" };
	unordered_map<string, int> white_keys_to_char;
	unordered_map<string, int> black_keys_to_char;
	//vector<char> piano_keys_white_ = {(char) 'HT', 'Q', 'W'};
	unordered_map<int, pair<int, int>> white_keys_to_position;
	unordered_map<int, pair<int, int>> black_keys_to_position;
	vector<string> piano_keys_black_ = { "1", "2", "3", "5", "6", "8", "9","-", "=", "Back-", "space" };
	int full_white_width_ = 60;
	int full_white_height_ = 400;
	int full_black_width_ = 50;
	int full_black_height_ = 250;
	double full_white_width_position_ = ((GetSystemMetrics(SM_CXSCREEN) / 4) - (((white_key_width_ * 14) + (14 * 5)) / 2));
	double full_white_height_position_ = (GetSystemMetrics(SM_CYSCREEN) / 4) - (white_key_height_ / 2);
	double full_black_width_position_ = full_white_width_position_ + (full_white_width_position_ / 2) + (20 / 2) + (5 / 2);
	double full_black_height_position_ = full_white_height_position_;
};
