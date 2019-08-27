#ifndef GRADUAL_TREMOLO_DIALOG_H
#define GRADUAL_TREMOLO_DIALOG_H

#include <QDialog>

namespace Ui {
class GradualTremoloDialog;
}

class GradualTremoloDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradualTremoloDialog(QWidget *parent = nullptr);
    ~GradualTremoloDialog();
	bool isTempo();
	int numNotes();
	int startIntensity();
	int endIntensity();
	int getMinimumPPM();
	int getMaximumPPM();

	void setCurrentTempo(int tempo);

private:
    Ui::GradualTremoloDialog *ui;
};

#endif // GRADUAL_TREMOLO_DIALOG_H
