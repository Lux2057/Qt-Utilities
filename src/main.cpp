#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Samples/QRecurrentCounter.h"

int main(int argc, char* argv[]) {
	QGuiApplication app(argc, argv);

	qmlRegisterType<QRecurrentCounter>("CppControls", 1, 0, "RecurrentCounter");

	QQmlApplicationEngine engine;

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	const int ret = app.exec();

	return ret;
}
