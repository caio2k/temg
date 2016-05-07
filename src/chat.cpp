#include "chat.h"
#include <QDebug>

Chat::Chat(const QString& name, QObject* parent) :
    MyListItem(parent), m_name(name)
{
}

//overwriting functions from ListItem
QHash<int, QByteArray> Chat::roleNames() const
{
  QHash<int, QByteArray> names;
  names[NameRole] = "name";
//  names[MessagesRole] = "messages";
  names[LastRole] = "lastMessage";
  return names;
}

QVariant Chat::data(int role) const
{
  switch(role) {
  case NameRole:
    return name();
  case LastRole:
    return lastMessage();
  default:
    return QVariant();
  }
}

void Chat::appendMessage(Message& msg){
    Message msgToAdd(msg.sender(),msg.destiny(),msg.content());
    qWarning() << "Appending message" << msgToAdd.content();
    m_messages.append(&msgToAdd);
    emit dataChanged();
}

QString Chat::lastMessage() const{
    if(m_messages.size()>0)
        return m_messages.last()->content();
    return "empty";
}

//getters and setters
QDeclarativeListProperty<Message> Chat::messages()  {
    return QDeclarativeListProperty<Message>(this, m_messages);
}

void Chat::changeName(const QString& n){
    m_name = n;
    emit dataChanged();
}

//QList<Message> Chat::getMessages(){
//    return &chatMessages;
//}

//void Chat::setMessages(QList<Message> messages){
//    chatMessages = QList<Message>(messages);
//}


