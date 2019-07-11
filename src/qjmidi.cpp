#include "header/qjmidi.h"
#include "ui_qjmidi.h"

QJmidi::QJmidi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QJmidi)
{
    ui->setupUi(this);

	// leemos el archivo de instrumentos
	//this->loadInstruments();

}

QJmidi::~QJmidi()
{
    delete ui;
}

void QJmidi::addTrackTab() {
	int tab_widget_count = this->ui->tabWidget_tracks->count();
	if (tab_widget_count <= 9) {
		
		SelectInstrumentDialog select_instrument;
		select_instrument.setModal(true);
		int result = select_instrument.exec();
		QString instrument_string = select_instrument.getInstrumentString();
		int instrument_key = select_instrument.getSelectedInstrument();

		if (result == QDialog::Accepted) {
			// Creamos y añadimos la pestaña nueva
			track_tab_widget *newTab = new track_tab_widget();
			QString name = QString::QString("Track %0").arg(QString::number(tab_widget_count));
			this->ui->tabWidget_tracks->addTab(newTab, name);

			// Establecemos el instrumento en la pestaña
			newTab->setInstrument(instrument_string, instrument_key);

			// Añadir la track al Midifile con el instrumento elegido
			int tempo = 60.0;
			if (tab_widget_count <= 1 ){
				this->midifile.addTempo(tab_widget_count - 1, 0, tempo);
				//this->ui->pte_output->appendPlainText("tab 0");
			}
			else {
				int result = this->midifile.addTrack();
				//this->ui->pte_output->appendPlainText(QString::QString("tab %0").arg(QString::number(result)));
				this->midifile.addTempo(tab_widget_count - 1, 0, tempo);
			}

			
			// Mostramos lo hecho en la consola
			this->ui->pte_output->appendPlainText(QString::QString("Creada tab %0 para \"%1:%2\". Con tempo %3.").arg(	QString::number(tab_widget_count - 1), 
																														QString::number(instrument_key), instrument_string, 
																														QString::number(tempo)));

		}
	}
	else{
		QMessageBox message;
		message.setText(QString::fromUtf8("El número máximo de tracks es de 9")
		);
		message.exec();
	}

}

QString QJmidi::readFile(QString filename) {
	QFile mFile(filename);

	if (!mFile.open(QFile::ReadOnly | QFile::Text)) {
		//qDebug() << "could not open file for read";
		//return;
		QMessageBox message;
		QString error = QString("Ha ocurrido un problema leyendo el archivo: \n%0").arg(filename);
		message.setText(error);
		message.exec();
	}

	QTextStream in(&mFile);
	QString mText = in.readAll();


	mFile.close();
	return mText;
}

void QJmidi::on_pb_generar_midi_clicked()
{
}

void QJmidi::on_pb_nota_clicked()
{
	//int velocity = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
	//							tr("Intensidad:"), 100,0,127,1,&ok);
	SelectNoteDialog note_dialog;
	note_dialog.setModal(true);
	int result = note_dialog.exec();

	if (result == QDialog::Accepted) {


		this->ui->pte_output->appendPlainText(QString::QString("Se ha seleccionado altura %0.").arg(QString::number(velocity)));
	}
	else {
		QMessageBox message;
		message.setText("Ha ocurrido un problema.");
		message.exec();
	}

	

}

void QJmidi::on_actionGenerate_Example_triggered()
{
	int track = 0;
	int channel = 0;
	int instr = 43;
	int a = 2;
	int b = 3;
	// Dur = Seconds per cycle
	double dur = 2.0;
	double tempo = 60.0;

	this->midifile.setTPQ(2);
	this->midifile.addTempo(0, 0, tempo);

	int tpq = midifile.getTPQ();
	for (int i = 0; i < 50; i++) {
		midifile.addNoteOn(track, i*2.0, 9, instr, 127);
		midifile.addNoteOff(track, (i + 1)*2.0, 9, instr);
	}
	string filename = "prueba.mid";
	if (filename.empty()) cout << midifile;
	else midifile.write(filename);
}

void QJmidi::on_pb_rest_clicked() {
}

void QJmidi::on_pb_add_track_tab_clicked() {
	this->addTrackTab();
}

//void QJmidi::loadInstruments() {
//	QString file = this->readFile(":/resources/instruments.txt");
//	QStringList file_list = file.split(',');
//	for (int i = 0; i < file_list.size(); i+=2) {
//		QPair<int, QString> aux( file_list[i].toInt(), file_list[i+1] );
//		this->instruments.push_back(aux);
//	}
//
//}

