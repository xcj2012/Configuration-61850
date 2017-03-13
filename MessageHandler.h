#pragma once
#include <QAbstractMessageHandler>
class MessageHandler :
	public QAbstractMessageHandler
{
public:
	MessageHandler()
		: QAbstractMessageHandler(0)
	{
	}

	QString statusMessage() const
	{
		return m_description;
	}

	int line() const
	{
		return m_sourceLocation.line();
	}

	int column() const
	{
		return m_sourceLocation.column();
	}

protected:
	virtual void handleMessage(QtMsgType type, const QString &description,
		const QUrl &identifier, const QSourceLocation &sourceLocation)
	{
		Q_UNUSED(type);
		Q_UNUSED(identifier);

		m_messageType = type;
		m_description = description;
		m_sourceLocation = sourceLocation;
	}
private:
	QtMsgType m_messageType;
	QString m_description;
	QSourceLocation m_sourceLocation;
};

