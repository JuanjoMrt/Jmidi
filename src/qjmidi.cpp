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

void QJmidi::pruebaMidifile() {
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

void QJmidi::on_pb_generar_midi_clicked()
{
	this->pruebaMidifile();
}

void QJmidi::on_pb_nota_clicked()
{
	
}