#ifndef QJMIDI_H
#define QJMIDI_H

#include <QMainWindow>

namespace Ui {
class QJmidi;
}

class QJmidi : public QMainWindow
{
    Q_OBJECT

public:
    explicit QJmidi(QWidget *parent = nullptr);
    ~QJmidi();

private:
    Ui::QJmidi *ui;
};

#endif // QJMIDI_H
