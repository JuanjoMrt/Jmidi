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

			track_tab_widget *newTab = new track_tab_widget();
			QString name = QString::QString("Track %0").arg(QString::number(tab_widget_count));
			this->ui->tabWidget_tracks->addTab(newTab, name);

			
		
			newTab->setInstrument(instrument_string, instrument_key);

			this->ui->pte_output->appendPlainText( QString::QString("Creada tab para %0:%1.").arg(QString::number(instrument_key),instrument_string) );
			// Añadir la track al Midifile con el instrumento elegido

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
	bool ok;
	int velocity = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
								tr("Intensidad:"), 100,0,127,1,&ok);
	if (!ok) {
		QMessageBox message;
		message.setText("Ha ocurrido un problema.");
		message.exec();
	}

	this->ui->pte_output->appendPlainText(QString::QString("Se ha seleccionado altura %0.").arg(QString::number(velocity)));

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

