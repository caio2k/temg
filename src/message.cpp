#include "message.h"

Message::Message(QObject *parent, QString send, QString msg) :
    QObject(parent)
{
    messageSender = send;
    messageContent = msg;
}

//getters and setters
QString Message::getSender(){
    return messageSender;
}

void Message::setSender(const QString& s){
    messageSender = s;
}

//void Message::changeSender(const QString& s){
//    messageSender = s;
//}

QString Message::getContent(){
    return messageContent;
}

void Message::setContent(const QString& m){
    messageContent = m;
}

