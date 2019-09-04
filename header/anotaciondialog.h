#ifndef ANOTACIONDIALOG_H
#define ANOTACIONDIALOG_H

#include <QDialog>

namespace Ui {
class AnotacionDialog;
}

class AnotacionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnotacionDialog(QWidget *parent = nullptr);
    ~AnotacionDialog();

	//Return the comment
	QString getAnotacion();

	// True: if the position is on top
	// False: If it is below the hexagram
	bool getPosicion();

private slots:
    void on_rb_down_clicked();

    void on_rb_top_clicked();

    void on_line_comment_textChanged(const QString &arg1);


private:
    Ui::AnotacionDialog *ui;
	bool anotacion_top = true;
	QString anotacion;
};

#endif // ANOTACIONDIALOG_H
