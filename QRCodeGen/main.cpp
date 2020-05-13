#include <QCoreApplication>

#include "qrcodegen.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QRCodeGen::save("123","123.bmp");

    return a.exec();
}
