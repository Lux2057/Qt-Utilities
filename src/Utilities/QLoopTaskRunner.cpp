#include "QLoopTaskRunner.h"

QLoopTaskRunner::QLoopTaskRunner(std::function<void()> task, QObject* parent) : QObject(parent), _task(std::move(task)) {}

QLoopTaskRunner::~QLoopTaskRunner() {
	stop();
}

bool QLoopTaskRunner::isRunning() const {
	return _isRunning;
}

void QLoopTaskRunner::run() {
	if (_isRunning)
		throw std::exception(THREAD_IS_ALREADY_RUNNING);

	QtConcurrent::run([this] {
		_isRunning = true;
		emit isRunningChanged();

		while (!_isStopRequested)
			_task();

		_isRunning = false;
		emit isRunningChanged();
	});
}

void QLoopTaskRunner::stop() {
	if (!_isRunning)
		return;

	_isStopRequested = true;

	while (_isRunning)
		QThread::msleep(1);

	_isStopRequested = false;
}