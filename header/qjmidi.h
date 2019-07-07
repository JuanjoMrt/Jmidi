#ifndef QJMIDI_H
#define QJMIDI_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <iostream>
#include <QInputDialog>
#include <QMessageBox>

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

private slots:
    void on_pb_generar_midi_clicked();

    void on_pb_nota_clicked();

    void on_actionGenerate_Example_triggered();

    void on_pb_rest_clicked();

private:
    Ui::QJmidi *ui;
	smf::MidiFile midifile;
};

#endif // QJMIDI_H
