#pragma once

#include <QGraphicsLineItem>
#include <Qpair>
#include <QMessageBox>
#include "header/nota_rect_item.h"
#include "header/musical_symbol.h"


enum duration_symbols {
	NORMAL,
	STACCATO,
	STACCATISSIMO,
	TENUTO
};


class Note : public MusicalSymbol{
public:
	Note();
	Note(const Note& note);
	~Note();

	// Return the duration of the note in ticks
	int CalculateDurationTicks(int tpq);

	void setNoteGraphicsItem(NotaRectItem* nri);

	qreal getX() override;

	// This will be private in a future update
	// and getter and setter methods
	// will be used instead of direct access

	// This is the velocity at which the note will be pressed
	int velocity;

	// Type of duration symbol that has this note
	duration_symbols duration_symbol = NORMAL;

	// Visual representation of this note
	NotaRectItem *rect_item;
	QGraphicsLineItem* note_graphic_symbol = new QGraphicsLineItem;
	QGraphicsLineItem* note_graphic_symbol_2;


private:
	
};

