#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSharedPointer>
#include "QTaskRunner.h"


int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);    

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    const int ret = app.exec();

    return ret;
}
