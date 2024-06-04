#ifndef QRECURRENTCOUNTER_H
#define QRECURRENTCOUNTER_H

#include "Utilities/QLoopTaskRunner.h"

#define THREAD_DELAY_IN_MS 10

class QRecurrentCounter : public QObject
{
	Q_OBJECT

    Q_PROPERTY(qint32 counter1 READ counter1 NOTIFY counter1Changed)
    Q_PROPERTY(bool isRunning1 READ isRunning1 NOTIFY isRunning1Changed)

    Q_PROPERTY(qint32 counter2 READ counter2 NOTIFY counter2Changed)
    Q_PROPERTY(bool isRunning2 READ isRunning2 NOTIFY isRunning2Changed)

public:
	explicit QRecurrentCounter(QObject* parent = nullptr);
	~QRecurrentCounter() override;

	QRecurrentCounter(const QRecurrentCounter& other) = delete;
	QRecurrentCounter(QRecurrentCounter&& other) noexcept = delete;
	QRecurrentCounter& operator=(const QRecurrentCounter& other) = delete;
	QRecurrentCounter& operator=(QRecurrentCounter&& other) noexcept = delete;

    qint32 counter1() const;
    bool isRunning1() const;

    qint32 counter2() const;
    bool isRunning2() const;

public slots:
    void start1() const;
    void stop1();

    void start2() const;
    void stop2();

signals:
    void counter1Changed();
    void isRunning1Changed();

    void counter2Changed();
    void isRunning2Changed();

private:
    qint32 _counter1{ 0 };
    QLoopTaskRunner* _recurrentTR1{ nullptr };

    qint32 _counter2{ 0 };
    QLoopTaskRunner* _recurrentTR2{ nullptr };
};

#endif // QRECURRENTCOUNTER_H
