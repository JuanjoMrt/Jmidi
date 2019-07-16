#ifndef TRACK_TAB_WIDGET_H
#define TRACK_TAB_WIDGET_H

#include <QWidget>
#include "header/hexagram_scene.h"

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
private:
    Ui::track_tab_widget *ui;
	int instrument;

	// Crea una escena para nuestro QGraphicsView
	HexagramScene *scene = new HexagramScene(this);

	// Distancia entre las líneas horizontales y verticales
	int distance_btw_hlines = 30;
	int distance_btw_vlines = 100;
};

#endif // TRACK_TAB_WIDGET_H
