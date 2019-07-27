#include "header/note.h"



Note::Note() {
	
}


Note::~Note() {}

int Note::CalculateDurationTicks(int tpq) {
	int tick_duration;
	//switch (duration_symbol) {
	//STACCATO:
	//	tick_duration = tpq / 2;
	//	break;
	//STACCATISSIMO:
	//	tick_duration = tpq / 4;
	//	break;
	//default:
	//	tick_duration = tpq;
	//	break;
	//}
	if (duration_symbol == STACCATO) {
		tick_duration = tpq / 2;
	}
	else if (duration_symbol == STACCATISSIMO) {
		tick_duration = tpq / 4;
	}
	else {
		tick_duration = tpq;
	}
	return tick_duration;
}

void Note::setNoteGraphicsItem(NotaRectItem* nri) {
	this->rect_item = nri;
	QPair<int,int> pos = nri->getNotaPos();
	int h = nri->getNotaHeight();
	int w = nri->getNotaWidth();
	QPen pen;
	this->note_graphic_symbol_2 = nullptr;
	
	

	if (this->duration_symbol == TENUTO) {
		pen.setWidth(2);
		this->note_graphic_symbol->setLine( pos.first +1 , pos.second - h / 3, pos.first + w -1, pos.second - h / 3);
		
	}
	if (this->duration_symbol == STACCATO) {
		pen.setWidth(3);
		this->note_graphic_symbol->setLine( (pos.first + w/2) -0.5 , pos.second - h / 3, (pos.first + w / 2) + 0.5, pos.second - h / 3);
	}
	if (this->duration_symbol == STACCATISSIMO) {
		pen.setWidth(2);
		this->note_graphic_symbol->setLine(pos.first + 1, pos.second - 8, pos.first + w/2, pos.second - h / 3);
		this->note_graphic_symbol_2 = new QGraphicsLineItem;
		this->note_graphic_symbol_2->setLine(pos.first + w / 2, pos.second - h / 3, pos.first + w -1, pos.second - 8);
		this->note_graphic_symbol_2->setPen(pen);
	}

	this->note_graphic_symbol->setPen(pen);

}
