#pragma once
#include <QtGlobal>

class MusicalSymbol {
public:
	MusicalSymbol();
	virtual ~MusicalSymbol();

	// Returns the x of the graphic item
	// this will be override by subtypes
	virtual qreal getX();


	virtual bool isCalderon();
	virtual int countNotesInside();
	bool isInTremolo();
	void setInTremolo(bool in_tremolo);

private:
	//qreal x,y;
	bool is_in_tremolo = false;
};