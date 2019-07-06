#ifndef QJMIDI_H
#define QJMIDI_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <iostream>

#include "lib/midifile/include/MidiFile.h"
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

	void pruebaMidifile();

private slots:
    void on_pb_generar_midi_clicked();

    void on_pb_nota_clicked();

private:
    Ui::QJmidi *ui;
	smf::MidiFile midifile;
};

#endif // QJMIDI_H
