#include "qjmidi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QJmidi w;
    w.show();

    return a.exec();
}
