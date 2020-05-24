#include "ofApp.h"
//--------------------------------------------------------------

MusicPlay::MusicPlay(int window_width, int window_height){
	width = window_width;
	height = window_height;
}

void MusicPlay::setup(){
	//record();
	playButton.setup("", 400, 150);
	startingScreenSound.load("keys-of-moon-warm-memories.mp3");
	if (startingScreenSound.isLoaded()) {
		startingScreenSound.play();
	}
	Piano.white_key_mapped_position();
	Piano.black_key_mapped_position();
	title.load("Quicksand-Regular.otf", 100);
	//gui.setup();
	//gui.add(playButton.setup("Play"));
	//gui.add(playButton)

	//gui.setSize(500, 200);
	//gui.setSize(float w, float h);
	//gui.setWidthElements(500);
	//gui.setDefaultWidth(500);
	//gui.setDefaultHeight(200);
	//button.set
	//gui.add(intSlider.setup("int slider", 0, 0, 100));
	//gui.add(toggle.setup("toggle", false));
}

void MusicPlay::record() {
	ofSetVerticalSync(true);
	isPlaying = false;
	isRecording = false;
	soundStreamInput.printDeviceList();

	bufferSize = 256;

	soundStreamInput.setup(this, 0, 1, 44100, bufferSize, 4);
	soundStreamOutput.setup(this, 2, 0, 44100, bufferSize, 4);

	//if you want to set a different device id 
//	soundStreamInput.setDeviceID(2); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.	
//	soundStreamOutput.setDeviceID(2); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.

	playingBufferOffset = 0;
	recordingBufferOffset = 0;
	soundStreamOutput.stop();
	soundStreamInput.stop();
}

void MusicPlay::audioIn(float * input, int bufferSize, int nChannels) {
	if (isRecording) {
		for (int i = 0; i < bufferSize; i++) {
			recording[i + recordingBufferOffset * bufferSize] = input[i];
		}
		recordingBufferOffset++;
	}
}

void MusicPlay::audioOut(float * output, int bufferSize, int nChannels) {
	if (isPlaying) {
		for (int i = 0; i < bufferSize; i++) {
			output[i * 2 + 0] = recording[i + playingBufferOffset * bufferSize];
			output[i * 2 + 1] = recording[i + playingBufferOffset * bufferSize];
		}
		playingBufferOffset++;
	}

}

void MusicPlay::exitApp() {

	soundStream.close();

}

//--------------------------------------------------------------
void MusicPlay::update(){
	if (playingBufferOffset * bufferSize >= SAMPLE_LENGTH - bufferSize) {
		isPlaying = false;
		soundStreamOutput.stop();
	}
	if (recordingBufferOffset * bufferSize >= SAMPLE_LENGTH - bufferSize) {
		isRecording = false;
		soundStreamInput.stop();
	}
	should_update_ = true;

}

//--------------------------------------------------------------
void MusicPlay::draw(){
	ofClear(0,0,0);
	if (displays_game_) {
		startingScreenSound.stop();
		displays_starting_screen_ = false;
		ofSetColor(60, 60, 60);
		ofDrawRectangle(0, 0, fullscreen_width_, fullscreen_height_);
		Piano.white_keys();
		Piano.black_keys();
		drawTitle();
	}

	if (light_up_keys_) {
		is_white_key_ = false;
		is_black_key_ = false;
		displays_starting_screen_ = false;
		Piano.white_keys();
		for (int i = 0; i < Piano.get_piano_keys_white_().size(); i++) {
			if (Piano.get_white_keys_to_char().at(Piano.get_piano_keys_white_()[i]) == current_key_) {
				is_white_key_ = true;
			}
		}
		for (int i = 0; i < Piano.get_piano_keys_black_().size(); i++) {
			if (Piano.get_black_keys_to_char().at(Piano.get_piano_keys_black_()[i]) == current_key_) {
				is_black_key_ = true;
			}
		}
		if (is_white_key_) {
			Piano.draw_gradient_white(current_key_);
		}
		Piano.black_keys();
		if (is_black_key_) {
			Piano.draw_gradient_black(current_key_);
		}
	}

	if (displays_starting_screen_) {
		//Starting screen
		StartingScreen.draw_starting_background();
		StartingScreen.draw_title();
		Button.draw_play_button(playButton);
	}
	//gui.draw();
	ofSetColor(225);

	if (isPlaying) {
		ofDrawBitmapString("PLAYING", 31, 92);
	}
	if (isRecording) {
		ofDrawBitmapString("RECORDING", 31, 130);
	}

	string reportString = "recordBuffer: " + ofToString(recordingBufferOffset) + "\nplayBuffer: " + ofToString(playingBufferOffset);
	ofDrawBitmapString(reportString, 32, 200);
}

void MusicPlay::drawTitle() {
	ofSetColor(0, 0, 0);
	title.drawString("Piano Keyboard", (GetSystemMetrics(SM_CXSCREEN) / 2) - 500, 300);
}
//--------------------------------------------------------------
void MusicPlay::keyPressed(int key) {
	if (key == 'z') {//recording
		if (isRecording) {
			isRecording = false;
			soundStreamInput.stop();
		}
		else {
			isRecording = true;
			soundStreamInput.start();
			recordingBufferOffset = 0;
		}
	}
	if (key == 'x') { //playing
		if (isPlaying) {
			isPlaying = false;
			soundStreamOutput.stop();
		}
		else {
			isPlaying = true;
			soundStreamOutput.start();
			playingBufferOffset = 0;
		}
	}
	if (key == 32) {//switching piano
		if (is_full_piano_) {
			
		}
	}
	int upper_key = toupper(key); // Standardize on upper case
	current_key_ = upper_key;
	is_playing_ = Piano.piano_sounds(upper_key);
	light_up_keys_ = true;
}

//--------------------------------------------------------------
void MusicPlay::keyReleased(int key) {
	//Piano.released_piano_key(key);
	light_up_keys_ = false;
	//Piano.piano_sounds_stop();
	//is_playing_ = false;
}

//--------------------------------------------------------------
void MusicPlay::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void MusicPlay::mouseDragged(int x, int y, int button){

}


//--------------------------------------------------------------
void MusicPlay::mousePressed(int x, int y, int button) {
	if (button == 0) {
		if (x > Button.get_position_of_button_X() && x < Button.get_position_of_button_X() + Button.get_size_of_button_X()
			&& y > Button.get_position_of_button_Y() && y < Button.get_position_of_button_Y() + Button.get_size_of_button_Y()) {
			cout << "wow"; // this does work
			displays_game_ = true;
		}
	}
}

//--------------------------------------------------------------
void MusicPlay::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void MusicPlay::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void MusicPlay::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void MusicPlay::windowResized(int w, int h){

}

//--------------------------------------------------------------
void MusicPlay::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void MusicPlay::dragEvent(ofDragInfo dragInfo){ 

}
