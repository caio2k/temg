#include "chat.h"
#include <QDeclarativeListProperty>

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

//QDeclarativeListProperty<Message> *Chat::getMessages(){
//    return &chatMessages;
//}

QDeclarativeListProperty<Message> Chat::messages(){
     return QDeclarativeListProperty<Message>(this, chatMessages);
}

//void Chat::setMessages(QList<Message> messages){
//    chatMessages = QList<Message>(messages);
//}

//void Chat::appendMessage(const Message msg){
//    chatMessages.append(msg);
//}
