#ifndef SELECT_NOTE_DIALOG_H
#define SELECT_NOTE_DIALOG_H

#include <QDialog>

namespace Ui {
class SelectNoteDialog;
}

class SelectNoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectNoteDialog(QWidget *parent = nullptr);
    ~SelectNoteDialog();

private:
    Ui::SelectNoteDialog *ui;
};

#endif // SELECT_NOTE_DIALOG_H
