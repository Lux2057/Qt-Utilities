#ifndef QRECURRENTCOUNTER_H
#define QRECURRENTCOUNTER_H

#include "Utilities/QLoopTaskRunner.h"

#define THREAD_DELAY_IN_MS 10

class QRecurrentCounter : public QObject
{
	Q_OBJECT

	Q_PROPERTY(qint32 counter READ counter NOTIFY counterChanged)

	Q_PROPERTY(bool isRunning READ isRunning NOTIFY isRunningChanged)

public:
	explicit QRecurrentCounter(QObject* parent = nullptr);
	~QRecurrentCounter() override;

	QRecurrentCounter(const QRecurrentCounter& other) = delete;
	QRecurrentCounter(QRecurrentCounter&& other) noexcept = delete;
	QRecurrentCounter& operator=(const QRecurrentCounter& other) = delete;
	QRecurrentCounter& operator=(QRecurrentCounter&& other) noexcept = delete;

	qint32 counter() const;	

	bool isRunning() const;

public slots:
	void start() const;
	void stop();

signals:
	void counterChanged();
	void isRunningChanged();

private:
	qint32 _counter{ 0 };

	QLoopTaskRunner* _recurrentTaskRunner{ nullptr };

	std::function<void(QRecurrentCounter*)> _increment;

private slots:
	void _emitIsRunningChanged();
};

#endif // QRECURRENTCOUNTER_H
