#ifndef TRACK_TAB_WIDGET_H
#define TRACK_TAB_WIDGET_H

#include <QWidget>

namespace Ui {
class track_tab_widget;
}

class track_tab_widget : public QWidget
{
    Q_OBJECT

public:
    explicit track_tab_widget(QWidget *parent = nullptr);
    ~track_tab_widget();
	void setInstrument(QString instrument, int key);
	int getInstrument();
private:
    Ui::track_tab_widget *ui;
	int instrument;
};

#endif // TRACK_TAB_WIDGET_H
