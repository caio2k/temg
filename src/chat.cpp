#include "chat.h"

Chat::Chat(QObject *parent, QString chatName) :
    QObject(parent), chatName(QString("unamed"))
{
}

QString Chat::getName(){
    return chatName;
}

void Chat::setName(const QString &n){
    chatName = n;
}

QList<Message> *Chat::getMessages(){
    return chatMessages;
}

//void Chat::setMessages(Message messages){
//    *chatMessages = messages;
//}
