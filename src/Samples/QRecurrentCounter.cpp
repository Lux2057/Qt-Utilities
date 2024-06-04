#include "QRecurrentCounter.h"

QRecurrentCounter::QRecurrentCounter(QObject* parent) : QObject(parent) {
	_recurrentTR1 = new QLoopTaskRunner([this] {        
        if(_counter2 >= 70){
            _recurrentTR2->requestStop();
        }

		_counter1++;

        emit counter1Changed();

		QThread::msleep(THREAD_DELAY_IN_MS);
    });

    _recurrentTR2 = new QLoopTaskRunner([this] {
        if(_counter1 >= 20){
            _recurrentTR1->requestStop();
        }

        _counter2+=2;

        emit counter2Changed();

        QThread::msleep(THREAD_DELAY_IN_MS);
    });
}

QRecurrentCounter::~QRecurrentCounter() {
	delete _recurrentTR1;
    delete _recurrentTR2;
}

qint32 QRecurrentCounter::counter1() const {
	return _counter1;
}

bool QRecurrentCounter::isRunning1() const {
	return _recurrentTR1->isRunning();
}

void QRecurrentCounter::start1() const {
    _recurrentTR1->awaitStop();
	_recurrentTR1->run();
}

void QRecurrentCounter::stop1() {
    _recurrentTR1->awaitStop();
    emit isRunning1Changed();

	_counter1 = 0;
    emit counter1Changed();
}

qint32 QRecurrentCounter::counter2() const {
    return _counter2;
}

bool QRecurrentCounter::isRunning2() const {
    return _recurrentTR2->isRunning();
}

void QRecurrentCounter::start2() const {
    _recurrentTR2->awaitStop();
    _recurrentTR2->run();
}

void QRecurrentCounter::stop2() {
    _recurrentTR2->awaitStop();
    emit isRunning2Changed();

    _counter2 = 0;
    emit counter2Changed();
}
