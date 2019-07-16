#include "header/track_tab_widget.h"
#include "ui_track_tab_widget.h"

track_tab_widget::track_tab_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::track_tab_widget)
{
    ui->setupUi(this);

	// Se establece la escena para la vista
	this->ui->gv_sheet->setScene(this->scene);

	// Establecemos el tamaño inicial de la partitura
	int hexagram_lenth = 10000;

	// Creamos el hexagrama
	// con una longitud de "hexagram_lenth",
	// una separación entre líneas horizontales de "distance_btw_hlines"
	// y una separación entre líneas verticales de "distance_btw_vlines"
	QPen pen = QPen(QColor(10, 10, 10));
	QPen pen2 = QPen(QColor(121, 121, 121));
	for (int i = 0; i < 6; i++) {
		this->scene->addLine(0, distance_btw_hlines * i, hexagram_lenth, distance_btw_hlines * i, pen);

		if (i < 5) {
			this->scene->addLine(0, (distance_btw_hlines * i) + distance_btw_hlines / 2, hexagram_lenth, (distance_btw_hlines * i) + distance_btw_hlines / 2, pen2);
		}
	}
	pen = QPen(QColor(142, 142, 142));
	for (int i = 0; i < hexagram_lenth; i += distance_btw_vlines) {
		this->scene->addLine(i, 0, i, distance_btw_hlines * 5, pen);
	}
}

track_tab_widget::~track_tab_widget()
{
    delete ui;
}

void track_tab_widget::setInstrument(QString instrument, int key) {
	this->instrument = key;
	this->ui->tb_instrument->insertPlainText(instrument);
}

int track_tab_widget::getInstrument() {
	return this->instrument;
}
