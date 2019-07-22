#include "header/nota_rect_item.h"

NotaRectItem::NotaRectItem(QGraphicsItem *parent) {
	this->setParentItem(parent);
}

NotaRectItem::NotaRectItem(int x, int y) {
	// Establecemos el tamaño
	this->setRect( QRectF(x, y, nota_width, nota_height) );

	// Rellenamos con color
	this->setBrush(Qt::black);
}

int NotaRectItem::getNotaWidth() {
	return this->nota_width;
}

int NotaRectItem::getNotaHeight() {
	return this->nota_height;
}
