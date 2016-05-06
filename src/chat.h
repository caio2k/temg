#ifndef CHAT_H
#define CHAT_H

#include <QObject>
//#include <QList>
#include <QDeclarativeListProperty>
#include "message.h"

class Chat : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDeclarativeListProperty<Message> messages READ getMessages)
//    Q_PROPERTY(QString *chatMessages READ getMessages WRITE setMessages)

public:
    explicit Chat(QObject *parent = 0, QString chatName = QString("Unamed"));

    // getters and setters
    QString getName();
    Q_INVOKABLE void setName(const QString&);
    QDeclarativeListProperty<Message> getMessages();
    //QList<Message> Chat::getMessages();
    //void setMessages(QList<Message> messages);
    //Q_INVOKABLE void appendMessage(Message &msg);
    Q_INVOKABLE void appendMessage(Message&);

    QString chatName;
    QList<Message *> chatMessages;
private:

signals:

public slots:

};

#endif // CHAT_H
