#include "header/gradual_tremolo_dialog.h"
#include "ui_gradual_tremolo_dialog.h"

GradualTremoloDialog::GradualTremoloDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradualTremoloDialog)
{
    ui->setupUi(this);
}

GradualTremoloDialog::~GradualTremoloDialog()
{
    delete ui;
}

bool GradualTremoloDialog::isTempo() {
	return this->ui->pb_time_tremolo->isChecked();
}

int GradualTremoloDialog::numNotes() {
	return this->ui->sb_num_notes->value();
}

int GradualTremoloDialog::startIntensity() {
	return this->ui->sb_inten_start->value();
}

int GradualTremoloDialog::endIntensity() {
	return this->ui->sb_inten_end->value();
}

int GradualTremoloDialog::getMinimumPPM() {
	return this->ui->sb_ppm_min->value();
}

int GradualTremoloDialog::getMaximumPPM() {
	return this->ui->sb_ppm_max->value();
}

void GradualTremoloDialog::setCurrentTempo(int tempo) {
	this->ui->sb_ppm_min->setValue(tempo);
	this->ui->sb_ppm_min->setMinimum(tempo);

	this->ui->sb_ppm_max->setValue(tempo*2);
	this->ui->sb_ppm_max->setMinimum(tempo);
}
