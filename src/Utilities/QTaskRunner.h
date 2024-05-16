#ifndef QTASKRUNNER_H
#define QTASKRUNNER_H

#include <QtConcurrent/QtConcurrent>

class QTaskRunner final : public QObject
{
	Q_OBJECT

public:
	explicit QTaskRunner(QObject* parent = nullptr);
	~QTaskRunner() override;

	QTaskRunner(const QTaskRunner& other) = delete;
	QTaskRunner(QTaskRunner&& other) noexcept = delete;
	QTaskRunner& operator=(const QTaskRunner& other) = delete;
	QTaskRunner& operator=(QTaskRunner&& other) noexcept = delete;

	bool isRunning() const;

	template <typename T>
	void run(T* context, const std::function<void(T*)>& task);
	void run(const std::function<void()>& task);
	void stop();

signals:
	void isRunningChanged();

private:
	bool _isThreadRunning{ false };
	bool _isThreadStopRequested{ false };
};

#endif // QTASKRUNNER_H
