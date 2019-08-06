#pragma once

class MusicalSymbol {
public:
	MusicalSymbol();
	virtual ~MusicalSymbol();

	// Returns the x of the graphic item
	// this will be override by subtypes
	int getX();

	bool isCalderon();

private:
	
};