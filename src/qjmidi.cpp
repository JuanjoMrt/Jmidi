#include "header/qjmidi.h"
#include "ui_qjmidi.h"

QJmidi::QJmidi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QJmidi)
{
    ui->setupUi(this);
}

QJmidi::~QJmidi()
{
    delete ui;
}
