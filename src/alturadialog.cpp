#include "header/alturadialog.h"
#include "ui_alturadialog.h"

AlturaDialog::AlturaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlturaDialog)
{
    ui->setupUi(this);
}

AlturaDialog::~AlturaDialog()
{
    delete ui;
}

int AlturaDialog::getMaximum() {
	return this->maximum;
}

int AlturaDialog::getMinimum() {
	return this->minimum;
}



void AlturaDialog::on_sb_minimum_valueChanged(int arg1)
{
    this->ui->sb_maximum->setMinimum(arg1);
}

void AlturaDialog::on_sb_maximum_valueChanged(int arg1)
{
    this->ui->sb_minimum->setMaximum(arg1);
}

void AlturaDialog::on_buttonBox_accepted()
{
    this->minimum = this->ui->sb_minimum->value();
    this->maximum = this->ui->sb_maximum->value();
    close();
}
