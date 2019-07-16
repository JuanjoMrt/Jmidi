#include "header/note.h"



Note::Note() {}


Note::~Note() {}

int Note::CalculateDurationTicks(int tpq) {
	int tick_duration;
	switch (duration_symbol) {
	STACCATO:
		tick_duration = tpq / 2;
		break;
	STACCATISSIMO:
		tick_duration = tpq / 4;
		break;
	default:
		tick_duration = tpq;
		break;
	}
	return tick_duration;
}
