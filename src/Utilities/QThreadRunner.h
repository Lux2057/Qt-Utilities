#ifndef QTHREADRUNNER_H
#define QTHREADRUNNER_H

#include <QObject>
#include <QThread>

class QThreadRunner final : public QObject
{
    Q_OBJECT

public:
	explicit QThreadRunner(QObject* parent = nullptr);
	~QThreadRunner() override;

	QThreadRunner(const QThreadRunner& other) = delete;
	QThreadRunner(QThreadRunner&& other) noexcept = delete;
	QThreadRunner& operator=(const QThreadRunner& other) = delete;
	QThreadRunner& operator=(QThreadRunner&& other) noexcept = delete;

    bool isRunning() const;

    template <typename T>
    void start(T* context, std::function<void(T*)> task);
    void stop();

signals:
	void isRunningChanged();

private:
	bool _isThreadRunning{ false };
	bool _isThreadStopRequested{ false };    
};

#endif // QTHREADRUNNER_H
