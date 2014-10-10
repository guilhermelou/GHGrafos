#include "opmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpMain opmain;

    opmain.startProgram();
    return a.exec();
}
