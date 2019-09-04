#ifndef TEMPODIALOG_H
#define TEMPODIALOG_H

#include <QDialog>

namespace Ui {
class TempoDialog;
}

class TempoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TempoDialog(QWidget *parent = nullptr);
    ~TempoDialog();

	int getTempo();
	void setTempo(int old_tempo);

private slots:
    void on_sb_tempo_valueChanged(int arg1);

private:
    Ui::TempoDialog *ui;
	int tempo = 1;
};

#endif // TEMPODIALOG_H
