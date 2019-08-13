#pragma once

#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include "header/musical_symbol.h"

class Calderon : public MusicalSymbol {
public:
	Calderon();
	Calderon(const Calderon& calderon);
	
	// Create a calderon providing the index at the beggining
	// the end index and the number of repetitions
	Calderon( int begin, int end, int num_rep );
	~Calderon();

	bool isCalderon() override;
	int countNotesInside() override;

	// This values will be moved to private
	QGraphicsPixmapItem *calderon_image;
	int begin_index;
	int end_index;
	int num_rep;
	bool is_calderon = true;
private:


};