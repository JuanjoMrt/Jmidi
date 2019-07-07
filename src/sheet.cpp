#include "header/sheet.h"

Sheet::Sheet() {};

Sheet::Sheet(int tempo, int track) {
	this->midifile.setTPQ(120);
	this->midifile.addTempo(track, 0, tempo);
};