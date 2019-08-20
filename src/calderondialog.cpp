#include "header/calderondialog.h"
#include "ui_calderondialog.h"

CalderonDialog::CalderonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalderonDialog)
{
    ui->setupUi(this);
}

CalderonDialog::~CalderonDialog()
{
    delete ui;
}

void CalderonDialog::setMaximumSlider(int max) {
	this->ui->slider_inicio_calderon->setMaximum(max);
	this->ui->label_inicio_maximum->setText( QString("Inicial\n  %0").arg(QString::number(max)));
}

void CalderonDialog::setMinimumSlider(int min) {
	this->ui->slider_inicio_calderon->setMinimum(min);
	this->ui->label_inicio_minimum->setText(QString("Final\n  %0").arg(QString::number(min)));
	int num_note_rep = this->ui->slider_inicio_calderon->maximum() - min;
	this->ui->label_notes_to_repeat->setText(QString::fromUtf8("Se repetiran las ultimas %0 notas").arg(QString::number(num_note_rep)));
}

int CalderonDialog::getInicio() {
	return this->ui->slider_inicio_calderon->value();
}

int CalderonDialog::getFin() {
	return this->ui->slider_inicio_calderon->maximum();
}

int CalderonDialog::GetNumRepeticiones() {
	int num_rep = 1;
	if (is_repetition) {
		num_rep = this->ui->sb_num_rep->value();
	}
	return num_rep;
}

int CalderonDialog::getCa() {
	return this->ui->sb_ca->value();
}

void CalderonDialog::on_pb_calderon_clicked() {
	this->ui->sb_num_rep->setEnabled(false);
	this->ui->sb_ca->setEnabled(true);
	this->is_repetition = false;
}


void CalderonDialog::on_pb_repetition_clicked()
{
	this->ui->sb_num_rep->setEnabled(true);
	this->ui->sb_ca->setEnabled(false);
	this->is_repetition = true;
}

void CalderonDialog::on_slider_inicio_calderon_sliderMoved(int position)
{
	int notes_repeat = this->ui->slider_inicio_calderon->maximum() - position;

	this->ui->label_notes_to_repeat->setText(QString::fromUtf8("Se repetiran las ultimas %0 notas").arg(QString::number(notes_repeat)));
}
