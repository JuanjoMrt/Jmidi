#include "header/select_rest_dialog.h"
#include "ui_select_rest_dialog.h"

SelectRestDialog::SelectRestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRestDialog)
{
    ui->setupUi(this);
}

SelectRestDialog::~SelectRestDialog()
{
    delete ui;
}

bool SelectRestDialog::isQuarterRest() {
	return this->quarter_rest;
}

int SelectRestDialog::getDuration() {
	return this->duration;
}


void SelectRestDialog::on_buttonBox_accepted()
{
	if (this->ui->pb_caesura->isChecked()) {
		this->quarter_rest = false;
		this->duration = -1;
	}
	else {
		this->duration = this->ui->sb_rest_duration->value();
	}
}
