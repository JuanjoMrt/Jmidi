#pragma once

#include "lib/midifile/include/MidiFile.h"


using namespace std;

class Sheet {
	private:
		smf::MidiFile midifile;
	public:
		Sheet();
		Sheet(int tempo, int track);
};