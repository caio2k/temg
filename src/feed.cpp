#include "feed.h"

#include "chat.h"

#include <QDebug>

Feed::Feed(QObject *parent) :
    MyListModel(new Chat,parent)
{
}

Feed::Feed(Chat* c, QObject *parent) :
    MyListModel(new Chat,parent)
{
    appendRow(c);
}

void Feed::appendMessage(const TelegramNamespace::Message &m){
    bool groupChatMessage = m.peer.startsWith(QLatin1String("chat"));
    qWarning() << m.peer << m.contact << m.flags << m.id << m.text << m.type << m.timestamp;

    if (groupChatMessage) {
//        static_cast<Chat*>(m_list.at(idx))->appendMessage(m);
    }
    else{
        Chat *c = static_cast<Chat*>(find(QString(m.peer)));
        if(c){
            qWarning() << "adding m to existing c.id" << m.peer;
            c->appendMessage(m);
        }
        else{
            qWarning() << "adding m to new c because this does not exist c.id " << m.peer;
            Chat *newc = new Chat(QString(m.peer));
            newc->appendMessage(m);
            appendRow(newc);
        }
    }
}

void Feed::appendMessage(int idx, const TelegramNamespace::Message &m){
    static_cast<Chat*>(m_list.at(idx))->appendMessage(new Message(m));
}

void Feed::appendMessage(const QString& id, const TelegramNamespace::Message &m){
    static_cast<Chat*>(find(id))->appendMessage(new Message(m));
}
