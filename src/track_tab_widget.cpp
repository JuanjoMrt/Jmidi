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
	//this->tab_score.emplace_back(&note);
	this->tab_score.emplace_back( new Note(note) );

	//QMessageBox msgBox;
	//msgBox.setText(QString( "Pos x= %0" ).arg( QString::number( rect_item->getNotaPos().first ) ));
	//msgBox.exec();
	
}

void track_tab_widget::setNextRest( bool is_quarter_note, int duration ) {
	QImage image;

	if (is_quarter_note) {
		// Load the image and scale it
		image = QImage(":/icons/icons/quarter-note-rest-512px-cut.png");
		image = image.scaledToWidth(this->distance_btw_vlines / 4);
	}
	else {
		image = QImage(":/icons/icons/caesura-512px.png");
		image = image.scaledToWidth(this->distance_btw_vlines / 2);
	}
	

	if (image.isNull()) {

		QMessageBox msgBox;
		msgBox.setText("Fallo al cargar la imagen");
		msgBox.exec();

	}
	else {
		Rest rest;
		QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));

		// Colocamos la imagen en el centro del hexagrama
		item->setX(this->x_next_note);
		item->setY((5 * this->distance_btw_hlines) / 2 - (item->boundingRect().height()) / 2);
		this->scene->addItem(item);

		if (duration > 1) {
			QGraphicsTextItem* circa = new QGraphicsTextItem(QString("ca.%0").arg(QString::number(duration)));
			circa->setPos(this->x_next_note, -20);
			this->scene->addItem(circa);
			rest.circa = circa;
		}

		// Actualizamos la posicion del siguiente simbolo
		x_next_note += item->boundingRect().width() + 5;

		rest.is_quarter_note = is_quarter_note;
		rest.rest_image = item;
		rest.duration = duration;
		//this->tab_score.emplace_back(&rest);
		this->tab_score.emplace_back(new Rest(rest) );
	}
}

void track_tab_widget::setNextCalderon(Calderon& calderon) {

	bool a = calderon.isRepetition();
	qreal pos_x_begin = this->tab_score[calderon.begin_index]->getX() ;
	/*qreal pos_x_begin = ms.getX();*/
	qreal pos_x_end = this->x_next_note;

	QPen pen;
	pen.setWidth(3);
	pen.setCapStyle(Qt::RoundCap);
	this->scene->addLine(pos_x_begin,-10,pos_x_end,-10,pen);
	QImage image;
	if (!calderon.isRepetition()) {
		image = QImage(":/icons/icons/fermata-512px.png");
		if (image.isNull()) {

			QMessageBox msgBox;
			msgBox.setText("Fallo al cargar la imagen");
			msgBox.exec();

		}
		else {
			image = image.scaledToWidth(this->distance_btw_vlines / 4);
			QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
			// Set the image in the middle
			item->setX(pos_x_begin + ((pos_x_end - pos_x_begin) / 2 - item->boundingRect().width() / 2));
			item->setY(-35);
			this->scene->addItem(item);
			calderon.calderon_image = item;
		}
	}
	else {
		image = QImage(":/icons/icons/repeat-sign-start-512px.png");
		QImage image2 = QImage(":/icons/icons/repeat-sign-end-512px.png");;
		if (image.isNull() || image2.isNull()) {

			QMessageBox msgBox;
			msgBox.setText("Fallo al cargar la imagen");
			msgBox.exec();

		}
		else {
			image = image.scaledToWidth(this->distance_btw_vlines / 4);
			image2 = image2.scaledToWidth(this->distance_btw_vlines / 4);

			QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
			QGraphicsPixmapItem *item2 = new QGraphicsPixmapItem(QPixmap::fromImage(image2));
			// Set at the start of the repetition
			item->setX(pos_x_begin);
			item->setY(-35);
			//Set at the end
			item2->setX(pos_x_end - item2->boundingRect().width());
			item2->setY(-35);

			this->scene->addItem(item);
			this->scene->addItem(item2);
			calderon.calderon_image = item;


		}

	}

	

	this->tab_score.emplace_back(new Calderon(calderon));
}

int track_tab_widget::getLastCalderon() {
	bool found = false;
	int index = 0;
	for (int i = tab_score.size() - 1; i >= 0 && !found; i--) {
		if (tab_score[i]->isCalderon()) {
			index = i + 1;
			found = true;
		}
	}
	return index;
}

int track_tab_widget::getNumberNotes(int index) {
	int number_repeated_notes = 0;

	// Comprobar comparación
	for (int i = 0; i <= index; i++) {
		number_repeated_notes += tab_score[i]->countNotesInside();		
	}
	return number_repeated_notes;
}

int track_tab_widget::scoreSize() {
	return this->tab_score.size();
}
