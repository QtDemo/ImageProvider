#include "VideoOutput.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickWidget>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    qmlRegisterType<PaintedItem>("CustomModel", 1, 0, "PaintedItem");

    QQuickWidget *m_view = new QQuickWidget();
    m_view->engine()->addImageProvider("colors", new ColorImageProvider());
    m_view->setSource(QUrl("qrc:/main.qml"));
    m_view->show();
    return app.exec();
}
