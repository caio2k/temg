#include "chat.h"

Chat::Chat(QObject *parent) :
    QObject(parent)
{
}

QString Chat::getName(){
    return chatName;
}

void Chat::setName(const QString &n){
    chatName = n;
}
