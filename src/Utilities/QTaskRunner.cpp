#include "QTaskRunner.h"

QTaskRunner::QTaskRunner(QObject* parent) : QObject{ parent } {}

QTaskRunner::~QTaskRunner() {
	stop();
}

bool QTaskRunner::isRunning() const {
	return _isThreadRunning;
}

template <typename T>
void QTaskRunner::run(T* context, const std::function<void(T*)>& task) {
	if (_isThreadRunning)
		return;

	QtConcurrent::run([this, task, context] {
		_isThreadRunning = true;
		emit isRunningChanged();

		while (!_isThreadStopRequested)
			task(context);

		_isThreadRunning = false;
		emit isRunningChanged();
	});
}

void QTaskRunner::run(const std::function<void()>& task) {
	if (_isThreadRunning)
		return;

	QtConcurrent::run([this, task] {
		_isThreadRunning = true;
		emit isRunningChanged();

		while (!_isThreadStopRequested)
			task();

		_isThreadRunning = false;
		emit isRunningChanged();
	});
}

void QTaskRunner::stop() {
	if (!_isThreadRunning)
		return;

	_isThreadStopRequested = true;

	while (_isThreadRunning)
		QThread::msleep(1);

	_isThreadStopRequested = false;
}
