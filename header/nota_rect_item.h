#ifndef NOTA_RECT_ITEM_H
#define NOTA_RECT_ITEM_H

#include <QObject>
#include <QPainter>
#include <QGraphicsRectItem >
#include <QRectF>
#include <QPair>


class NotaRectItem : public QGraphicsRectItem {
public:
	NotaRectItem(QGraphicsItem *parent = 0);
	NotaRectItem(qreal x, qreal y);



	int getNotaWidth();
	int getNotaHeight();
	QPair<qreal,qreal> getNotaPos();

private:
	int nota_width = 10;
	int nota_height = 10;

	// Position
	qreal x,y;
};

#endif // NOTA_RECT_ITEM_H