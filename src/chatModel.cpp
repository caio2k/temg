#include "chatModel.h"

#include "chatItem.h"

#include <QDebug>

ChatModel::ChatModel(QObject *parent) :
    MyListModel(new ChatItem,parent)
{
}

ChatModel::ChatModel(ChatItem* c, QObject *parent) :
    MyListModel(new ChatItem,parent)
{
    appendRow(c);
}

void ChatModel::appendMessage(const TelegramNamespace::Message &m){
    bool groupChatMessage = m.peer.startsWith(QLatin1String("chat"));
    qWarning() << m.peer << m.contact << m.flags << m.id << m.text << m.type << m.timestamp;

    if (groupChatMessage) {
//        static_cast<Chat*>(m_list.at(idx))->appendMessage(m);
    }
    else{
        ChatItem *c = static_cast<ChatItem*>(find(QString(m.peer)));
        if(c){
            qWarning() << "adding m to existing c.id" << m.peer;
            c->appendMessage(m);
        }
        else{
            qWarning() << "adding m to new c because this does not exist c.id " << m.peer;
            ChatItem *newc = new ChatItem(QString(m.peer));
            newc->appendMessage(m);
            appendRow(newc);
        }
    }
}

void ChatModel::appendMessage(int idx, const TelegramNamespace::Message &m){
    static_cast<ChatItem*>(m_list.at(idx))->appendMessage(new MessageItem(m));
}

void ChatModel::appendMessage(const QString& id, const TelegramNamespace::Message &m){
    static_cast<ChatItem*>(find(id))->appendMessage(new MessageItem(m));
}
