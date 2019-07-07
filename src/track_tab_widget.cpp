#include "header/track_tab_widget.h"
#include "ui_track_tab_widget.h"

track_tab_widget::track_tab_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::track_tab_widget)
{
    ui->setupUi(this);
}

track_tab_widget::~track_tab_widget()
{
    delete ui;
}
