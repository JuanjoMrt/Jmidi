#ifndef ALTURADIALOG_H
#define ALTURADIALOG_H

#include <QDialog>

namespace Ui {
class AlturaDialog;
}

class AlturaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlturaDialog(QWidget *parent = nullptr);
    ~AlturaDialog();

	int getMaximum();
	int getMinimum();

private slots:


    void on_sb_minimum_valueChanged(int arg1);

    void on_sb_maximum_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::AlturaDialog *ui;
	int minimum;
	int maximum;
};

#endif // ALTURADIALOG_H
