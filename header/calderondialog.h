#ifndef CALDERONDIALOG_H
#define CALDERONDIALOG_H

#include <QDialog>

namespace Ui {
class CalderonDialog;
}

class CalderonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalderonDialog(QWidget *parent = nullptr);
    ~CalderonDialog();
	void setMaximumSlider(int max);
	void setMinimumSlider(int min);
	int getInicio();
	int getFin();
	int GetNumRepeticiones();

private slots:
    void on_slider_inicio_calderon_valueChanged(int value);

    void on_slider_fin_calderon_valueChanged(int value);

private:
    Ui::CalderonDialog *ui;
};

#endif // CALDERONDIALOG_H
