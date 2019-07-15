#ifndef SELECT_NOTE_DIALOG_H
#define SELECT_NOTE_DIALOG_H

#include <QDialog>
#include "header/note.h"
namespace Ui {
class SelectNoteDialog;
}

class SelectNoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectNoteDialog(QWidget *parent = nullptr);
	explicit SelectNoteDialog(QWidget *parent = nullptr, double tempo = 60.0);
	~SelectNoteDialog();

	// Set the tempo, this will be useful to calculate
	// the duration of the note
	void setTempo(double tempo = 60.0);

private slots:
    void on_buttonBox_accepted();
	void SelectNoteDialog::on_pb_normal_clicked();
	void SelectNoteDialog::on_pb_staccato_clicked();
	void SelectNoteDialog::on_pc_staccatissimo_clicked();

    void on_pc_tenuto_clicked();

private:
    Ui::SelectNoteDialog *ui;
	Note note;
	double tempo;
};

#endif // SELECT_NOTE_DIALOG_H
