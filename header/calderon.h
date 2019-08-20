#pragma once

#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include "header/musical_symbol.h"

class Calderon : public MusicalSymbol {
public:
	Calderon();
	
	// Create a calderon providing the index at the beggining
	// the end index and the number of repetitions
	Calderon( int begin, int end, int num_rep );
	Calderon(int begin, int end, int ca, bool is_repetition);
	~Calderon();

	bool isCalderon() override;
	int countNotesInside() override;

	const bool isRepetition();
	// This values will be moved to private
	QGraphicsPixmapItem *calderon_image;
	//QGraphicsPixmapItem *repetition_image_2;
	int begin_index;
	int end_index;
	int num_rep;
	int ca;
	bool is_calderon = true;
	bool is_repetition;
private:


};