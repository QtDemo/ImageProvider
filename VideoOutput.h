#ifndef VIDEOOUTPUT_H
#define VIDEOOUTPUT_H

#include <QQuickImageProvider>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QQuickItem>

class ColorImageProvider : public QQuickImageProvider
{
public:
    ColorImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override
    {
        int width = 100;
        int height = 50;

        if (size)
            *size = QSize(width, height);
        QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
                       requestedSize.height() > 0 ? requestedSize.height() : height);
        pixmap.fill(QColor(id).rgba());

        return pixmap;
    }
};

class PaintedItem : public QQuickPaintedItem
{
    Q_OBJECT
public:
    PaintedItem(QQuickItem *parent = 0) :
        QQuickPaintedItem(parent)
    {
        setWidth(800);
        setHeight(800);
        setRenderTarget(QQuickPaintedItem::FramebufferObject);

        this->setVisible(true);
    }

    void paint(QPainter *painter)
    {
        painter->setRenderHint(QPainter::Antialiasing);
        painter->drawImage(0, 0, QImage(""));
    }
};

#endif // VIDEOOUTPUT_H
