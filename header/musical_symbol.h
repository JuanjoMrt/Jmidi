#pragma once
#include <QtGlobal>

class MusicalSymbol {
public:
	MusicalSymbol();
	virtual ~MusicalSymbol();

	// Returns the x of the graphic item
	// this will be override by subtypes
	virtual qreal getX();


	bool isCalderon();

private:
	//qreal x,y;
};