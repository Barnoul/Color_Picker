#include "colorselect.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ColorSelect w;
    w.show();

    return a.exec();
}
