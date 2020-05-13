#ifndef QRCODEGEN_H
#define QRCODEGEN_H

#include <QString>
#include <QImage>

class QRCodeGen
{
public:
    QRCodeGen();

    static QImage make(const QString&strData);

    static bool save(const QString&strData, const QString &strFile);
};

#endif // QRCODEGEN_H
