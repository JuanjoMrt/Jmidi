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
