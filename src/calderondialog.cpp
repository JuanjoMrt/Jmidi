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
	this->ui->slider_fin_calderon->setMaximum(max);
	this->ui->slider_inicio_calderon->setMaximum(max);
	this->ui->label_fin_maximum->setText( QString::number(max));
	this->ui->label_inicio_maximum->setText(QString::number(max));
}

int CalderonDialog::getInicio() {
	return this->ui->sb_inicio_calderon->value();
}

int CalderonDialog::getFin() {
	return this->ui->sb_fin_calderon->value();
}

int CalderonDialog::GetNumRepeticiones() {
	return this->ui->sb_num_rep->value();
}

void CalderonDialog::on_slider_inicio_calderon_valueChanged(int value)
{
	if( this->ui->slider_fin_calderon->value() < value )
		this->ui->slider_fin_calderon->setValue(value);
}

void CalderonDialog::on_slider_fin_calderon_valueChanged(int value)
{
	int min = this->ui->slider_inicio_calderon->value();
	if(value < min)
		this->ui->slider_fin_calderon->setValue(min);
}
