#ifndef TRACK_TAB_WIDGET_H
#define TRACK_TAB_WIDGET_H

#include <QWidget>
#include "header/hexagram_scene.h"
#include "header/nota_rect_item.h"

namespace Ui {
class track_tab_widget;
}

class track_tab_widget : public QWidget
{
    Q_OBJECT

public:
    explicit track_tab_widget(QWidget *parent = nullptr);
    ~track_tab_widget();
	void setInstrument(QString instrument, int key);
	int getInstrument();

	//	Añade una nota a la representación visual, 
	//	es decir, a la escena que representa la partitura
	void setNextGraphicsNote(int altura);

	//	Sets the velocity symbol
	//	This method is also used to update it
	//
	//	Establece la clave de intensidad.
	//	Este método tambien se usa para actualizar
	//	dicha clave
	void SetClaveIntensidad(int min, int max);

private:
    Ui::track_tab_widget *ui;
	int instrument;

	// Crea una escena para nuestro QGraphicsView
	HexagramScene *scene = new HexagramScene(this);

	// Distancia entre las líneas horizontales y verticales
	int distance_btw_hlines = 30;
	int distance_btw_vlines = 100;
	int x_next_note = 0;

	// Altura máxima y mínima de la clave
	QGraphicsTextItem *minimum = new QGraphicsTextItem();
	QGraphicsTextItem *maximum = new QGraphicsTextItem();
};

#endif // TRACK_TAB_WIDGET_H
