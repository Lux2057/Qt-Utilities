#ifndef QLOOPTASKRUNNER_H
#define QLOOPTASKRUNNER_H

#include <QtConcurrent/QtConcurrent>

#define THREAD_IS_ALREADY_RUNNING "Thread is already running!"

class QLoopTaskRunner final : public QObject
{
	Q_OBJECT

public:
    explicit QLoopTaskRunner(std::function<void()> task, QObject* parent = nullptr);
    ~QLoopTaskRunner() override;

    QLoopTaskRunner(QObject* parent = nullptr) = delete;
    QLoopTaskRunner(const QLoopTaskRunner& other) = delete;
    QLoopTaskRunner(QLoopTaskRunner&& other) noexcept = delete;
    QLoopTaskRunner& operator=(const QLoopTaskRunner& other) = delete;
    QLoopTaskRunner& operator=(QLoopTaskRunner&& other) noexcept = delete;

	bool isRunning() const;

	void run();
    void awaitStop();
    void requestStop();

signals:
	void isRunningChanged();

private:
	bool _isRunning{ false };
	bool _isStopRequested{ false };
	const std::function<void()> _task;
};

#endif // QLOOPTASKRUNNER_H
