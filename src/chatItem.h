#ifndef CHAT_H
#define CHAT_H

#include <QObject>
//#include <QList>
#include <QDeclarativeListProperty>
#include "messageItem.h"
#include "listModel.h"
#include "qdeclarativecontext.h"
#include "CTelegramCore.hpp"

class ChatItem : public MyListItem
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
    ChatItem(QObject* parent = 0) : MyListItem(parent) {}
    explicit ChatItem(const QString&, QObject* parent = 0);
    //abstract methods implementation
    QHash<int, QByteArray> roleNames() const;
    QVariant data(int role) const;
    inline QString id() const { return m_name; }

    QString lastMessage() const;
    Q_INVOKABLE void appendMessage(const TelegramNamespace::Message&);
    Q_INVOKABLE void appendMessage(MessageItem*);
    Q_INVOKABLE void changeName(const QString&);
    inline QList<MyListItem*>* getQList() const { return m_messages;}
    // getters and setters
    inline QString name() const { return m_name; }

    // inspired by telegram-qt
    QVariant headerData(int, Qt::Orientation, int role) const;

    //QDeclarativeListProperty complications
    static void appendMessagesList(QDeclarativeListProperty<MessageItem> *l, MessageItem *m) {
        //Chat c = qobject_cast<Chat>(l->object);
        //if(m)
        //    message->append(m);
        ChatItem* c = static_cast<ChatItem*>(l->object);
        m->setParent(c);
        return c->m_messages->append(m);
    }

private:
    QString m_name;
    QList<MyListItem*>* m_messages;

signals:

public slots:

};

#endif // CHAT_H
