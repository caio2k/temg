#include "chat.h"
#include <QDeclarativeListProperty>
#include <QDebug>
Chat::Chat(QObject *parent, QString n) :
    QObject(parent)
{
    chatName = n;
}

QString Chat::getName(){
    return chatName;
}

void Chat::setName(const QString& n){
    chatName = n;
}

QDeclarativeListProperty<Message> Chat::getMessages(){
     return QDeclarativeListProperty<Message>(this, chatMessages);
}

//QList<Message> Chat::getMessages(){
//    return &chatMessages;
//}

//void Chat::setMessages(QList<Message> messages){
//    chatMessages = QList<Message>(messages);
//}

void Chat::appendMessage(Message& msg){
    Message msgToAdd(msg.sender(),msg.destiny(),msg.content());
    qWarning() << "Appending message" << msgToAdd.content();
    chatMessages.append(&msgToAdd);
}

