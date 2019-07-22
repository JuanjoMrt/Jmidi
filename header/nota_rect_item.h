#ifndef NOTA_RECT_ITEM_H
#define NOTA_RECT_ITEM_H

#include <QObject>
#include <QPainter>
#include <QGraphicsRectItem >
#include <QRectF>


class NotaRectItem : public QGraphicsRectItem {
public:
	NotaRectItem(QGraphicsItem *parent = 0);
	NotaRectItem(int x, int y);

	int getNotaWidth();
	int getNotaHeight();
private:
	int nota_width = 10;
	int nota_height = 10;
};

#endif // NOTA_RECT_ITEM_H