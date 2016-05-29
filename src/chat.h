#ifndef CHAT_H
#define CHAT_H

#include <QObject>
//#include <QList>
#include <QDeclarativeListProperty>
#include "message.h"
#include "listmodel.h"
#include "qdeclarativecontext.h"
#include "CTelegramCore.hpp"

class Chat : public MyListItem
{
    Q_OBJECT
    //Q_PROPERTY(QString name READ name WRITE changeName)
    //Q_PROPERTY(QString lastMessage READ lastMessage)
    //Q_PROPERTY(QDeclarativeListProperty<Message> messages READ messages) //it doesnt works!
    //Q_PROPERTY(QString message READ message)
    //Q_PROPERTY(QString countMessages READ countMessages)

    //Q_PROPERTY(QDeclarativeListProperty<Chat> messages READ messages )
//    Q_PROPERTY(QString *chatMessages READ getMessages WRITE setMessages)

public:
    enum Roles {
        NameRole,
        LastRole,
        MessagesRole,
        PeerRole,
        TextRole,
        CountRole
    };
    enum Columns {
        Peer,
        Contact,
        Direction,
        Timestamp,
        MessageId,
        MessageContent,
        Status,
        ForwardFromContact,
        ForwardTimestamp,
        ColumnsCount
    };

    //overwritten methods
    Chat(QObject* parent = 0) : MyListItem(parent) {}
    explicit Chat(const QString&, QObject* parent = 0);
    //abstract methods implementation
    QHash<int, QByteArray> roleNames() const;
    QVariant data(int role) const;
    inline QString id() const { return m_name; }

    QString lastMessage() const;
    Q_INVOKABLE void appendMessage(const TelegramNamespace::Message&);
    Q_INVOKABLE void appendMessage(Message*);
    Q_INVOKABLE void changeName(const QString&);
    // getters and setters
    inline QString name() const { return m_name; }
    Q_INVOKABLE QDeclarativeListProperty<Message> messages() const;

    // inspired by telegram-qt
    QVariant headerData(int, Qt::Orientation, int role) const;

    //QDeclarativeListProperty complications
    static void appendMessagesList(QDeclarativeListProperty<Message> *l, Message *m) {
        //Chat c = qobject_cast<Chat>(l->object);
        //if(m)
        //    message->append(m);
        Chat* c = static_cast<Chat*>(l->object);
        m->setParent(c);
        return c->m_messages.append(m);
    }
    int countMessagesList(QDeclarativeListProperty<Message> *l)
    {
       Chat* c = static_cast<Chat*>(l->object);
       return c->m_messages.count();
    }
    static Message* atMessagesList(QDeclarativeListProperty<Message> *property, int index) {
       Chat* c = qobject_cast<Chat*>(property->object);
       return c->m_messages.at(index);
    }
    static void clearMessagesList(QDeclarativeListProperty<Message> *property) {
       Message* m = qobject_cast<Message*>(property->object);
    }
private:
    QString m_name;
    QList<Message*> m_messages;

signals:

public slots:

};

#endif // CHAT_H
