#ifndef TREMOLO_DIALOG_H
#define TREMOLO_DIALOG_H

#include <QDialog>

namespace Ui {
class TremoloDialog;
}

class TremoloDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TremoloDialog(QWidget *parent = nullptr);
	void setTempo(int tempo);
	int getTremoloTempo();
	int getNNotes();
    ~TremoloDialog();

private:
    Ui::TremoloDialog *ui;
};

#endif // TREMOLO_DIALOG_H
