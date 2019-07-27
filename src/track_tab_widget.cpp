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

	// Establecemos la clave de intensidad
	SetClaveIntensidad(0, 127);




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

NotaRectItem* track_tab_widget::setNextGraphicsNote(int altura) {
	NotaRectItem *nota = new NotaRectItem();
	int y_max = 5 * this->distance_btw_hlines - nota->getNotaHeight();
	int pos_y = (altura * y_max) / 127;
	delete nota;
	nota = new NotaRectItem(this->x_next_note, y_max - pos_y);

	this->scene->addItem(nota);
	this->x_next_note += nota->getNotaWidth() + 5;

	return nota;
}

void track_tab_widget::SetClaveIntensidad(int min, int max) {
	QPen pen;
	pen.setWidth(5);
	pen.setCapStyle(Qt::RoundCap);
	this->scene->addLine(0, 0, 25, 5 * this->distance_btw_hlines, pen);
	this->scene->addLine(50, 0, 25, 5 * this->distance_btw_hlines, pen);

	delete this->minimum;
	this->minimum = new QGraphicsTextItem(QString::number(min));
	minimum->setPos(10, 5 * this->distance_btw_hlines + 10);
	this->scene->addItem(minimum);

	delete this->maximum;
	this->maximum = new QGraphicsTextItem(QString::number(max));
	maximum->setPos(10, -20);
	this->scene->addItem(maximum);

	if (this->x_next_note == 0) {
		this->x_next_note += 70;
	}
	
}

void track_tab_widget::setNextNote(Note note) {

	auto rect_item = this->setNextGraphicsNote(note.velocity);

	// Add the graphics of note to the scene
	note.setNoteGraphicsItem(rect_item);
	this->scene->addItem( note.note_graphic_symbol );
	
	if (note.note_graphic_symbol_2 != nullptr) {
		this->scene->addItem(note.note_graphic_symbol_2);
	}

	// Add the note to vector of notes
	this->tab_score.push_back(note);
	
}
