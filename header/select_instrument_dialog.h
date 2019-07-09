#ifndef SELECT_INSTRUMENT_DIALOG_H
#define SELECT_INSTRUMENT_DIALOG_H

#include <QDialog>
#include <QPair>
#include <QString>
#include <QStringList>

namespace Ui {
class SelectInstrumentDialog;
}

class SelectInstrumentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectInstrumentDialog(QWidget *parent = nullptr);
    ~SelectInstrumentDialog();
	 

	 int getSelectedInstrument();
	 QString getInstrumentString();

private slots:
     void on_comboBox_currentIndexChanged(int index);

private:
    Ui::SelectInstrumentDialog *ui;

	int selected_instrument;

	QStringList instruments = { "Acoustic Bass Drum", 
								"Bass Drum 1", 
								"Side Stick",
								"Acoustic Snare",
								"Hand Clap",
								"Electric Snare",
								"Low Floor Tom",
								"Closed Hi Hat",
								"High Floor Tom",
								"Pedal Hi-Hat",
								"Low Tom",
								"Open Hi-Hat",
								"Low-Mid Tom"};

};

#endif // SELECT_INSTRUMENT_DIALOG_H
