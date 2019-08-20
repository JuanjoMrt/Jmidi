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
	int getCa();
	bool is_repetition = false;

private slots:

    void on_pb_calderon_clicked();

    void on_pb_repetition_clicked();

    void on_slider_inicio_calderon_sliderMoved(int position);

private:
    Ui::CalderonDialog *ui;
};

#endif // CALDERONDIALOG_H
