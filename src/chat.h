#ifndef CHAT_H
#define CHAT_H

#include <QObject>
//#include <QList>
#include <QDeclarativeListProperty>
#include "message.h"
#include "listmodel.h"

class Chat : public ListItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QDeclarativeListProperty<Message> messages READ messages)
//    Q_PROPERTY(QString *chatMessages READ getMessages WRITE setMessages)

public:
    enum Roles {
        NameRole,
        LastRole
    };

    //overwritten methods
    Chat(QObject *parent = 0): ListItem(parent) {}
    explicit Chat(const QString&,QObject *parent = 0);
    //abstract methods implementation
    QHash<int, QByteArray> roleNames() const;
    QVariant data(int role) const;
    inline QString id() const { return m_name; }

    Q_INVOKABLE QString lastMessage() const;
    Q_INVOKABLE void appendMessage(Message&);

    // getters and setters
    inline QString name() const { return m_name; }
    Q_INVOKABLE void setName(const QString&);
    QDeclarativeListProperty<Message> messages();

private:
    QString m_name;
    QList<Message *> m_messages;

signals:

public slots:

};

#endif // CHAT_H
