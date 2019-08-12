#pragma once

#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include "header/musical_symbol.h"

class Rest : public MusicalSymbol {
public:
	Rest();
	~Rest();
	
	QGraphicsPixmapItem *rest_image;
	qreal getX() override;


	bool is_quarter_note;
	int duration;
	QGraphicsTextItem *circa;
	
private:
	

};