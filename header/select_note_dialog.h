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
	~SelectNoteDialog();


private slots:
    void on_buttonBox_accepted();
	void on_pb_normal_clicked();
	void on_pb_staccato_clicked();
	void on_pc_staccatissimo_clicked();
    void on_pc_tenuto_clicked();
public:
	Note getNote();
private:
    Ui::SelectNoteDialog *ui;
	Note note;
	double tpq;
};

#endif // SELECT_NOTE_DIALOG_H
