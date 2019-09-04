#include "header/anotaciondialog.h"
#include "ui_anotaciondialog.h"

AnotacionDialog::AnotacionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnotacionDialog)
{
    ui->setupUi(this);
}

AnotacionDialog::~AnotacionDialog()
{
    delete ui;
}

void AnotacionDialog::on_rb_down_clicked()
{
	this->anotacion_top = false;
}

void AnotacionDialog::on_rb_top_clicked()
{
	this->anotacion_top = true;
}

void AnotacionDialog::on_line_comment_textChanged(const QString &arg1)
{
	this->anotacion = arg1;
}

QString AnotacionDialog::getAnotacion() {
	return this->anotacion;
}

bool AnotacionDialog::getPosicion() {
	return this->anotacion_top;
}
