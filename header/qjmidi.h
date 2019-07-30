#ifndef QJMIDI_H
#define QJMIDI_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <iostream>
#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QResource>
#include <QIODevice>
#include <QString>
#include <Qpair>
#include <QTextBrowser>
#include <QDir>


#include "lib/midifile/include/MidiFile.h"
#include "header/sheet.h"
#include "header/track_tab_widget.h"
#include "header/select_instrument_dialog.h"
#include "header/select_note_dialog.h"
#include "header/note.h"
#include "header/select_rest_dialog.h"
#include "header/musical_symbol.h"
#include "header/calderondialog.h"

using namespace std;


namespace Ui {
class QJmidi;
}

class QJmidi : public QMainWindow
{
    Q_OBJECT

public:
    explicit QJmidi(QWidget *parent = nullptr);
    ~QJmidi();

	void addTrackTab();
	QString readFile(QString filename);

private slots:
    void on_pb_nota_clicked();

    void on_actionGenerate_Example_triggered();

    void on_pb_rest_clicked();

    void on_pb_add_track_tab_clicked();

    void on_pb_generar_midi_clicked();

    void on_pb_calderon_clicked();

private:
    Ui::QJmidi *ui;
	smf::MidiFile midifile;
	int tempo = 60.0;
	int channel = 9;
	vector< track_tab_widget *> vector_tab;
	// Objeto tipo Sheet es realmente necesario?
	//Sheet partitura;
	//vector< QPair<int,QString> > instruments;

	// Adds a note to midifile and to the sheet
	void addNote(Note note);
	// Adds a rest to midifile and to the sheet
	void addRest(bool is_quarter_note, int duration);

	void trackNotCreatedError();
	int getLastTick(int track);



	//void loadInstruments();
};

#endif // QJMIDI_H
