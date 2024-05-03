#include "qtclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtClass w;
    w.show();
    return a.exec();
}
