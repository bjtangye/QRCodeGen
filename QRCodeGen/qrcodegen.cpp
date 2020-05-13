#include "qrcodegen.h"

#include <QPainter>

#include "qrencode.h"

const int nMargin = 30;
const int nBlockSize = 8;

CQRCodeGen::CQRCodeGen()
{

}

QImage CQRCodeGen::make(const QString &strData)
{
    QImage genImg;
    QRcode* pQR = QRcode_encodeString(strData.toUtf8(), 1, QR_ECLEVEL_L, QR_MODE_8, 0);
    if(nullptr != pQR)
    {
        int nSize = nMargin*2 + pQR->width*nBlockSize;
        genImg = QImage(nSize, nSize, QImage::Format_RGB32);
        QPainter painter(&genImg);

        painter.setBrush(QColor("white"));
        painter.setPen(Qt::NoPen);
        painter.drawRect(0, 0, nSize, nSize);

        painter.setBrush(QColor("black"));
        for(int y=0; y<pQR->width; y++ )
        {
            for(int x=0; x<pQR->width; x++)
            {
                if (pQR->data[y*pQR->width+x]&1)
                {
                    QRectF block(x*nBlockSize+nMargin, y*nBlockSize+nMargin, nBlockSize, nBlockSize);
                    painter.drawRects(&block, 1);
                }
            }
        }

        QRcode_free(pQR);
    }

    return genImg;
}

bool CQRCodeGen::save(const QString &strData, const QString &strFile)
{
    QImage img = make(strData);

    return img.save(strFile);
}

