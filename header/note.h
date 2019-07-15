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

	// This will be private and getter and setter methods
	// will be used instead of direct access

	// This is the time that the note will be played
	double duration = 0;

	// This is the velocity at which the note will be pressed
	int velocity;

	// Type of duration symbol that has this note
	duration_symbols duration_symbol = NORMAL;

private:
	
};

