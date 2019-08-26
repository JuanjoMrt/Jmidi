#include "header/tremolo_dialog.h"
#include "ui_tremolo_dialog.h"

TremoloDialog::TremoloDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TremoloDialog)
{
    ui->setupUi(this);
}

void TremoloDialog::setTempo(int tempo) {
	this->ui->sb_tempo_tremolo->setValue(tempo);
}

int TremoloDialog::getTremoloTempo() {
	return this->ui->sb_tempo_tremolo->value();
}

int TremoloDialog::getNNotes() {
	return this->ui->sb_n_notes->value();
}

TremoloDialog::~TremoloDialog()
{
    delete ui;
}
