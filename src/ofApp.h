#pragma once
#include "ofMain.h"
#include "piano.h"
#include "startingScreen.h"
#include "button.h"
#include "ofxGui/src/ofxGui.h"
#include "ofxMaxim.h"
#include "ofxMidi.h"

#include <vector>
#include <windows.h>
#include <map> 
#include <sstream>
#include <string>
#include <iostream> 
#include <time.h>
#define SAMPLE_LENGTH 441000  // ten seconds

using std::vector;

class MusicPlay : public ofBaseApp{
	ofxPanel gui;
	ofColor color;
	//ofxIntSlider intSlider;
	//ofxFloatSlider floatSlider;
	ofxToggle toggle;
	//ofxButton button;
	piano Piano;
	startingScreen StartingScreen;
	ofTrueTypeFont title;
	button Button;
	ofxButton playButton;
	ofSoundPlayer startingScreenSound;
	ofParameter<bool> audioOnOff;
	ofSoundStream soundStream;
	//ofx toggle set the dimensions of the window setup 
	//ofapp setup


	// Enum to represent the current state of the game
	enum Recording {
		IN_PROGRESS = 0,
		PAUSED,
		FINISHED
	};
	private:
		//vector<> file_;
		Recording current_state_ = IN_PROGRESS; // The current state of the game, used to determine possible actions
		int width;
		int height;
		int fullscreen_width_ = GetSystemMetrics(SM_CXSCREEN);
		int fullscreen_height_ = GetSystemMetrics(SM_CYSCREEN);
		bool should_update_ = true;
		bool displays_game_ = false;
		bool light_up_keys_ = false;
		bool displays_starting_screen_ = true;
		int current_key_ = 0;
		bool is_white_key_ = false;
		bool is_black_key_ = false;
		bool is_playing_ = false;
		bool is_full_piano_ = false;

		ofSoundStream soundStreamInput;
		ofSoundStream soundStreamOutput;

		float recording[SAMPLE_LENGTH];
		int recordingBufferOffset;
		int playingBufferOffset;

		bool isPlaying;
		bool isRecording;

		int bufferSize;

	public:
		MusicPlay(int window_width, int window_height);

		void setup();
		void update();
		void draw();
		void drawTitle();

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
		
		void record();
		void audioIn(float * input, int bufferSize, int nChannels);
		void audioOut(float * output, int bufferSize, int nChannels);
		void turnAudioOn(bool & isOn);
		void MusicPlay::exitApp();
};
