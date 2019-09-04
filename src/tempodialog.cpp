#include "header/tempodialog.h"
#include "ui_tempodialog.h"

TempoDialog::TempoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TempoDialog)
{
    ui->setupUi(this);
}

TempoDialog::~TempoDialog()
{
    delete ui;
}

int TempoDialog::getTempo() {
	return this->tempo;
}

void TempoDialog::setTempo(int old_tempo) {
	this->ui->sb_tempo->setValue(old_tempo);
}

void TempoDialog::on_sb_tempo_valueChanged(int arg1)
{
	this->tempo = arg1;
}
