#include "QThreadRunner.h"

QThreadRunner::QThreadRunner(QObject* parent) : QObject{ parent } {}

QThreadRunner::~QThreadRunner() {
	stop();
}

bool QThreadRunner::isRunning() const {
	return _isThreadRunning;
}

template <typename T>
void QThreadRunner::start(T* context, std::function<void(T*)> task) {
	if (_isThreadRunning)
		return;

	_isThreadRunning = true;
	emit isRunningChanged();

	while (!_isThreadStopRequested)
        operation(context);

	_isThreadRunning = false;
	emit isRunningChanged();
}

void QThreadRunner::stop() {
	if (!_isThreadRunning)
		return;

	_isThreadStopRequested = true;

	while (_isThreadRunning)
		QThread::msleep(1);

	_isThreadStopRequested = false;
}
