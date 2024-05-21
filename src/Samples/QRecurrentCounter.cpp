#include "QRecurrentCounter.h"

QRecurrentCounter::QRecurrentCounter(QObject* parent) : QObject(parent) {
	_recurrentTaskRunner = new QLoopTaskRunner([this] {
		_counter++;

		emit counterChanged();

		QThread::msleep(THREAD_DELAY_IN_MS);
	}, this);

	connect(_recurrentTaskRunner, &QLoopTaskRunner::isRunningChanged, this, &QRecurrentCounter::_emitIsRunningChanged);
}

QRecurrentCounter::~QRecurrentCounter() {
	delete _recurrentTaskRunner;
}

qint32 QRecurrentCounter::counter() const {
	return _counter;
}

bool QRecurrentCounter::isRunning() const {
	return _recurrentTaskRunner->isRunning();
}

void QRecurrentCounter::start() const {
	_recurrentTaskRunner->stop();
	_recurrentTaskRunner->run();
}

void QRecurrentCounter::stop() {
	_recurrentTaskRunner->stop();

	_counter = 0;

	emit counterChanged();
}

void QRecurrentCounter::_emitIsRunningChanged() {
	emit isRunningChanged();
}
