#include "header/select_note_dialog.h"
#include "ui_select_note_dialog.h"

SelectNoteDialog::SelectNoteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectNoteDialog)
{
    ui->setupUi(this);
}

SelectNoteDialog::~SelectNoteDialog()
{
    delete ui;
}


void SelectNoteDialog::on_buttonBox_accepted()
{
	this->note.velocity = this->ui->sb_velocity->value();
	close();
}

void SelectNoteDialog::on_pb_normal_clicked()
{
    this->note.duration_symbol = NORMAL;
}

void SelectNoteDialog::on_pb_staccato_clicked()
{
	this->note.duration_symbol = STACCATO;
}

void SelectNoteDialog::on_pc_staccatissimo_clicked()
{
	this->note.duration_symbol = STACCATISSIMO;
}

void SelectNoteDialog::on_pc_tenuto_clicked()
{
    this->note.duration_symbol = TENUTO;
}

Note SelectNoteDialog::getNote() {
	return this->note;
}
