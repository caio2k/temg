#ifndef CHAT_H
#define CHAT_H

#include <QObject>
//#include <QList>
#include <QDeclarativeListProperty>
#include "message.h"

class Chat : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString chatName READ getName WRITE setName)
    Q_PROPERTY(QDeclarativeListProperty<Message> messages READ messages)
//    Q_PROPERTY(QString *chatMessages READ getMessages WRITE setMessages)
public:
    explicit Chat(QObject *parent = 0, QString chatName = QString("Unamed"));

    // getters and setters
    QString getName();
    void setName(const QString &n);
    QDeclarativeListProperty<Message> messages();
    //void setMessages(QList<Message> messages);
    //Q_INVOKABLE void appendMessage(const Message msg);
private:
    QString chatName;
    QList<Message *> chatMessages;

signals:

public slots:

};

#endif // CHAT_H
