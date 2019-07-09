#include "header/select_instrument_dialog.h"
#include "ui_select_instrument_dialog.h"

SelectInstrumentDialog::SelectInstrumentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectInstrumentDialog)
{
    ui->setupUi(this);
	this->ui->comboBox->insertItems(0,this->instruments);
}

SelectInstrumentDialog::~SelectInstrumentDialog()
{
    delete ui;
}

int SelectInstrumentDialog::getSelectedInstrument() {
	return this->selected_instrument;
}

QString SelectInstrumentDialog::getInstrumentString() {
	return this->instruments[this->selected_instrument -35];
}

void SelectInstrumentDialog::on_comboBox_currentIndexChanged(int index)
{
	// The list of instruments start at the MIDI instrument number 35
	this->selected_instrument = index +35;
}
