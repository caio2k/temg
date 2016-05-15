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
    qWarning() << m.contact << m.flags << m.id << m.text << m.type << m.timestamp;
    if (groupChatMessage) {
//        static_cast<Chat*>(m_list.at(idx))->appendMessage(m);
    }
    else{
        Chat *c = static_cast<Chat*>(find(QString(m.id)));
        if(c){
            qWarning() << "adding m to existing c.id" << m.id;
            c->appendMessage(m);
        }
        else{
            qWarning() << "adding m to new c because this does not exist c.id " << m.id;
            Chat *newc = new Chat(QString(m.id));
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
