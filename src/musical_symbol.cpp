#include "header/musical_symbol.h"

MusicalSymbol::MusicalSymbol() {}

MusicalSymbol::~MusicalSymbol() {}


qreal MusicalSymbol::getX() {
	return -1;
}

bool MusicalSymbol::isCalderon() {
	return false;
}

int MusicalSymbol::countNotesInside() {
	return 1;
}

bool MusicalSymbol::isInTremolo() {
	return this->is_in_tremolo;
}

void MusicalSymbol::setInTremolo(bool in_tremolo) {
	this->is_in_tremolo = in_tremolo;
}
