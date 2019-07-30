#ifndef SELECT_REST_DIALOG_H
#define SELECT_REST_DIALOG_H

#include <QDialog>

namespace Ui {
class SelectRestDialog;
}

class SelectRestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectRestDialog(QWidget *parent = nullptr);
    ~SelectRestDialog();
	bool isQuarterRest();
	int getDuration();

private slots:

    void on_buttonBox_accepted();


private:
    Ui::SelectRestDialog *ui;
	bool quarter_rest = true;
	int duration;
};

#endif // SELECT_REST_DIALOG_H
