#include "header/qjmidi.h"
#include "ui_qjmidi.h"

QJmidi::QJmidi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QJmidi)
{
    ui->setupUi(this);
	
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
			this->vector_tab.push_back(newTab);
			QString name = QString::QString("Track %0").arg(QString::number(tab_widget_count));
			this->ui->tabWidget_tracks->addTab(newTab, name);

			// Establecemos el instrumento en la pestaña
			newTab->setInstrument(instrument_string, instrument_key);

			// Añadir la track al Midifile con el instrumento elegido
			
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

void QJmidi::on_pb_nota_clicked()
{
	if (this->ui->tabWidget_tracks->count() <= 1 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		this->trackError(1);
	}
	else {
		//int velocity = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		//							tr("Intensidad:"), 100,0,127,1,&ok);
		SelectNoteDialog note_dialog;
		note_dialog.setModal(true);
		int result = note_dialog.exec();

		if (result == QDialog::Accepted) {
			
			Note note = note_dialog.getNote();
			this->ui->pte_output->appendPlainText(QString::QString("Nota con intensidad %0 y duracion %1.").arg(QString::number(note.velocity), 
																												QString::number(note.CalculateDurationTicks(midifile.getTPQ()))));
			this->addNote(note);
		}
		else {
			QMessageBox message;
			message.setText("Ha ocurrido un problema.");
			message.exec();
		}
	}
}

void QJmidi::on_actionGenerate_Example_triggered()
{
	int track = 0;
	int channel = 9;
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
	//this->midifile.setTPQ(120);
	//this->midifile.addTempo(0, 0, tempo);
	
	//int duracion = 120;
	//int tpq = midifile.getTPQ();
	//midifile.addNoteOn(track, 0 * tpq, channel, instr, 127);
	//midifile.addNoteOff(track, 0 * tpq + duracion, channel, instr,1);

	//midifile.addNoteOn(track, 1 * tpq, channel, instr, 127);
	//midifile.addNoteOff(track, 1 * tpq + 1, channel, instr);

	//midifile.addNoteOn(track, 2 * tpq, channel, instr, 127);
	//midifile.addNoteOff(track, 2 * tpq + duracion, channel, instr);

	//midifile.addNoteOn(track, 3 * tpq, channel, instr, 127);
	//midifile.addNoteOff(track, 3 * tpq + duracion, channel, instr);

	//midifile.addNoteOn(track, 4 * tpq, channel, instr, 127);
	//midifile.addNoteOff(track, 4 * tpq + duracion, channel, instr);

	string filename = "prueba.mid";
	if (filename.empty()) cout << midifile;
	else midifile.write(filename);
	close();
}

void QJmidi::on_pb_rest_clicked() {
	if (this->ui->tabWidget_tracks->count() <= 1 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		this->trackError(1);
	}
	else {
		
		SelectRestDialog rest_dialog;
		rest_dialog.setModal(true);
		int result = rest_dialog.exec();

		if (result == QDialog::Accepted) {
			this->addRest( rest_dialog.isQuarterRest(), rest_dialog.getDuration() );

			// Output the result
			QString rest_type = rest_dialog.isQuarterRest() ? QString("o silencio de negra") : QString("a cesura");
			this->ui->pte_output->appendPlainText( QString("Añadid%0 correctamente.").arg(rest_type) );
		}
		else {
			QMessageBox message;
			message.setText("Ha ocurrido un problema.");
			message.exec();
		}



	}
}

void QJmidi::on_pb_add_track_tab_clicked() {
	this->addTrackTab();
}

void QJmidi::on_pb_generar_midi_clicked() {

	if (this->ui->tabWidget_tracks->count() <= 1 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		this->trackError(1);
	}
	else {
	bool ok;
	QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
		tr("User name:"), QLineEdit::Normal,
		tr("File.mid"), &ok);

	if (ok && !text.isEmpty())
		midifile.write( text.toStdString() );

	this->ui->pte_output->appendPlainText(QString("Creado el archivo %0").arg( text ));
	}
}

void QJmidi::on_pb_calderon_clicked() {
	
	if (this->ui->tabWidget_tracks->count() <= 1 || this->n_notas_tremolo > 0 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		if(this->n_notas_tremolo > 0)
			this->trackError(2);
		else 
			this->trackError(1);
	}
	else {
		int index = this->ui->tabWidget_tracks->currentIndex();
		track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));
		
		if (current_tab->scoreSize() < 1) {
			QMessageBox message;
			message.setText("No hay notas en la partitura.");
			message.exec();
		}
		else {

			CalderonDialog calderon_dialog;
			calderon_dialog.setModal(true);
			calderon_dialog.setMaximumSlider(current_tab->scoreSize());
			calderon_dialog.setMinimumSlider( current_tab->getLastCalderon());
			int result = calderon_dialog.exec();

			if (result == QDialog::Accepted) {

				int inicio = calderon_dialog.getInicio();
				int fin = calderon_dialog.getFin();
				int num_rep = calderon_dialog.GetNumRepeticiones();
				bool is_repetition = calderon_dialog.is_repetition;
				Calderon calderon(inicio, fin, num_rep, is_repetition);
				//if(is_repetition){
				//	Calderon ca(inicio,fin,calderon_dialog.getCa(),is_repetition);
				//	calderon = ca;
				//}
				
				this->addCalderon(calderon);

			}
		}
	}

}

void QJmidi::on_pb_tremolo_clicked() {
	if (this->ui->tabWidget_tracks->count() <= 1 || this->n_notas_tremolo != 0 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		if (this->n_notas_tremolo != 0) {
			this->trackError(2);
		}
		else {
			this->trackError(1);
		}
	}
	else {
		TremoloDialog tremolo_dialog;
		tremolo_dialog.setModal(true);
		tremolo_dialog.setTempo(this->tempo);
		int result = tremolo_dialog.exec();

		if (result == QDialog::Accepted) {
			this->tempo_tremolo = tremolo_dialog.getTremoloTempo();
			this->n_notas_tremolo = tremolo_dialog.getNNotes();

			int index = this->ui->tabWidget_tracks->currentIndex();
			this->midifile.addTempo(index -1 , this->getLastTick(index - 1), tremolo_dialog.getTremoloTempo());
		}
	}
}

void QJmidi::on_pb_gradual_tremolo_clicked() {
	if (this->ui->tabWidget_tracks->count() <= 1 || this->n_notas_tremolo != 0 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		if (this->n_notas_tremolo != 0) {
			this->trackError(2);
		}
		else {
			this->trackError(1);
		}
	}
	else {
		GradualTremoloDialog gradual_tremolo_dialog;
		gradual_tremolo_dialog.setCurrentTempo(this->tempo);
		gradual_tremolo_dialog.setModal(true);
		int result = gradual_tremolo_dialog.exec();
		int start_inten = gradual_tremolo_dialog.startIntensity();
		int end_inten = gradual_tremolo_dialog.endIntensity();
		int min_ppm = gradual_tremolo_dialog.getMinimumPPM();
		int max_ppm = gradual_tremolo_dialog.getMaximumPPM();
		int index = this->ui->tabWidget_tracks->currentIndex();


		if (result == QDialog::Accepted) {

			if( gradual_tremolo_dialog.isTempo() ){
				int num_notes = gradual_tremolo_dialog.numNotes();
				this->n_notas_tremolo = num_notes;
				for (int i = 1; i <= num_notes; i++) {
					this->midifile.addTempo(index - 1, this->getLastTick(index - 1),
						min_ppm + ((max_ppm - min_ppm) / num_notes)*i);

					Note note;
					note.duration_symbol = NORMAL;
					if (start_inten < end_inten)
						note.velocity = start_inten + ((end_inten - start_inten) / num_notes)*i;
					else
						note.velocity = start_inten - ((start_inten - end_inten) / num_notes)*i;

					this->addNote(note);

				}
			}
			else {
				int num_notes = gradual_tremolo_dialog.numNotes();
				this->n_notas_tremolo = num_notes;
				for (int i = 1; i <= num_notes; i++) {
					Note note;
					note.duration_symbol = NORMAL;
					if (start_inten < end_inten){
						this->midifile.addTempo(index - 1, this->getLastTick(index - 1),
							min_ppm + ((max_ppm - min_ppm) / num_notes)*i);
						note.velocity = start_inten + ((end_inten - start_inten) / num_notes)*i;
					}
					else{
						this->midifile.addTempo(index - 1, this->getLastTick(index - 1),
							max_ppm - ((max_ppm - min_ppm) / num_notes)*i);
						note.velocity = start_inten - ((start_inten - end_inten) / num_notes)*i;
					}
						

					this->addNote(note);
				}
			}

		}
	}
}

void QJmidi::on_actionA_adir_anotaci_n_triggered() {
	if (this->ui->tabWidget_tracks->count() <= 1 || this->n_notas_tremolo != 0 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		if (this->n_notas_tremolo != 0) {
			this->trackError(2);
		}
		else {
			this->trackError(1);
		}
	}
	else {
		AnotacionDialog anotacion_dialog;
		anotacion_dialog.setModal(true);
		int result = anotacion_dialog.exec();

		if (result == QDialog::Accepted) {
			int index = this->ui->tabWidget_tracks->currentIndex();
			track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));
			current_tab->setAnotacion(anotacion_dialog.getAnotacion(), anotacion_dialog.getPosicion());
		}
	}
}

void QJmidi::on_actionCambiar_clave_triggered() {
	if (this->ui->tabWidget_tracks->count() <= 1 || this->n_notas_tremolo != 0 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		if (this->n_notas_tremolo != 0) {
			this->trackError(2);
		}
		else {
			this->trackError(1);
		}
	}
	else {
		AlturaDialog altura_dialog;
		altura_dialog.setModal(true);
		int result = altura_dialog.exec();

		// Comprobamos que no haya sido cancelado
		if (result == QDialog::Accepted) {
			int index = this->ui->tabWidget_tracks->currentIndex();
			track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));
			current_tab->SetClaveIntensidad(altura_dialog.getMinimum(), altura_dialog.getMaximum());
		}
	}

}

void QJmidi::on_actionCambiar_Tempo_triggered() {
	if (this->ui->tabWidget_tracks->count() <= 1 || this->n_notas_tremolo != 0 || this->ui->tabWidget_tracks->currentIndex() == 0) {
		if (this->n_notas_tremolo != 0) {
			this->trackError(2);
		}
		else {
			this->trackError(1);
		}
	}
	else {
		int index = this->ui->tabWidget_tracks->currentIndex();
		track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));

		TempoDialog tempo_dialog;
		tempo_dialog.setModal(true);
		tempo_dialog.setTempo(this->tempo);
		int result = tempo_dialog.exec();

		if (result == QDialog::Accepted) {

			this->midifile.addTempo(index - 1, this->getLastTick(index - 1), tempo_dialog.getTempo());
			current_tab->setAnotacion(QString("Ca. %0").arg(QString::number(tempo_dialog.getTempo()) ), true);
			this->tempo = tempo_dialog.getTempo();
			/*this->setTempo(tempo_dialog.getTempo());*/
		}
	}

}



void QJmidi::addNote(Note note) {
	int index = this->ui->tabWidget_tracks->currentIndex();

	//midifile.addNoteOn(0, 0 * 120, 9, 35, 127);
	//midifile.addNoteOff(0, 0 * 120 + 30, 9, 35,1);

	//int indexx = this->midifile.getEventCount(0);

	int last_tick = this->getLastTick(index - 1);
	track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));
	int instrument = current_tab->getInstrument();

	midifile.addNoteOn(index - 1, last_tick, this->channel, instrument, note.velocity );
	midifile.addNoteOff(index - 1, last_tick + note.CalculateDurationTicks( midifile.getTPQ() ), this->channel, instrument, note.velocity);

	this->ui->pte_output->appendPlainText(QString("Añadida nota en el tick: %0").arg(QString::number(last_tick)));
	// Get a track_tab_widget pointer to the object inside the tab
	//track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));

	if (n_notas_tremolo > 0) {
		note.setInTremolo(true);
	}

	current_tab->setNextNote(note);
	

	this->checkUpdateTremolo();

	
}

void QJmidi::addRest(bool is_quarter_note, int duration) {
	int index = this->ui->tabWidget_tracks->currentIndex();
	int last_tick = this->getLastTick(index - 1);

	// Add the rest to the midifile
	midifile.addNoteOn(index - 1, last_tick, this->channel, 0, 0);
	int duration_ticks = 1 * midifile.getTPQ();
	if (duration > 1)
		duration_ticks = midifile.getTPQ() * duration;
	midifile.addNoteOff(index - 1, last_tick + duration_ticks, this->channel, 0);

	// Store the rest in the current tab
	track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));
	current_tab->setNextRest(is_quarter_note, duration);

	this->checkUpdateTremolo();

}

void QJmidi::addCalderon(Calderon calderon) {
	int index = this->ui->tabWidget_tracks->currentIndex();
	track_tab_widget* current_tab = qobject_cast<track_tab_widget*>(this->ui->tabWidget_tracks->widget(index));

	// Count the number of noteOn events
	int n_note_on = 0;
	// This will be the initial tick inside our calderon
	int relative_zero_tick = -1;
	// Get the number of events in total
	int event_count = midifile.getEventCount(index - 1);

	this->ui->pte_output->appendPlainText(QString("Número de events: %0").arg(QString::number(midifile.getEventCount(0))));
	
	int index_begin = current_tab->getNumberNotes(calderon.begin_index) - 1 ;

	//Add the notes inside the calderon zone in the midifile
	int last_tick = this->getLastTick(index - 1);
	int i = 0;
	for(int j = 0; j < calderon.num_rep; j++ ){
		if (j != 0) {
			relative_zero_tick = last_tick;
			last_tick = this->getLastTick(index - 1);
			event_count = midifile.getEventCount(index - 1);
		}


		for (; i < event_count; i++) {
			smf::MidiEvent event = midifile.getEvent(index - 1, i);
			int tick = event.tick;

			if (event.isNoteOn() || event.isNoteOff() ) {
				if (index_begin <= n_note_on) {
					if(relative_zero_tick != -1) {
						event.tick = last_tick +(event.tick - relative_zero_tick);
						midifile.addEvent(event);
					}

					// The first event will be a noteOn event
					if (relative_zero_tick == -1 && event.isNoteOn()) {
						relative_zero_tick = event.tick;
						event.tick = last_tick;
						midifile.addEvent(event);

					}

				
				}
				if(event.isNoteOn())
					n_note_on++;
			}
		}
	}
	current_tab->setNextCalderon(calderon);
	this->ui->pte_output->appendPlainText( QString("Número de events: %0").arg(QString::number( midifile.getEventCount(0) )));

}

void QJmidi::trackError(int error_num) {
	QMessageBox message;

	switch (error_num) {
		case 1: message.setText("Tienes que crear al menos una track para poder hacer esto y tenerla abierta."); break;
		case 2:	message.setText("No puedes hacer esto mientras estás en modo Trémolo"); break;
		default:  message.setText("Se ha producido un error"); break;
	}
	message.exec();
}

int QJmidi::getLastTick(int track) {
	int index = this->midifile.getEventCount(track);
	int last_tick = 0;
	if (index != 0) {
		last_tick = this->midifile.getEvent(track, index-1).tick;
	}
	return last_tick;
}

void QJmidi::checkUpdateTremolo() {
	if (this->n_notas_tremolo > 0) {
		n_notas_tremolo--;
		if (n_notas_tremolo == 0) {
			int index = this->ui->tabWidget_tracks->currentIndex();
			this->midifile.addTempo(index - 1, this->getLastTick(index - 1), this->tempo);
		}
	}

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
