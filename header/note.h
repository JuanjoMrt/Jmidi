#pragma once

enum duration_symbols {
	NORMAL,
	STACCATO,
	STACCATISSIMO,
	TENUTO
};


class Note {
public:
	Note();
	~Note();

	// Return the duration of the note in ticks
	int CalculateDurationTicks(int tpq);

	// This will be private in a future update
	// and getter and setter methods
	// will be used instead of direct access

	// This is the velocity at which the note will be pressed
	int velocity;

	// Type of duration symbol that has this note
	duration_symbols duration_symbol = NORMAL;

private:
	
};

