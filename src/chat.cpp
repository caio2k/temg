#include "chat.h"
#include <QDebug>

QString messageDeliveryStatusStr(TelegramNamespace::MessageDeliveryStatus status)
{
    switch (status) {
    case TelegramNamespace::MessageDeliveryStatusUnknown:
        return QLatin1String("Unknown");
    case TelegramNamespace::MessageDeliveryStatusSent:
        return QLatin1String("Sent");
    case TelegramNamespace::MessageDeliveryStatusRead:
        return QLatin1String("Read");
    case TelegramNamespace::MessageDeliveryStatusDeleted:
        return QLatin1String("Deleted");
    default:
        return QString();
    }
}

Chat::Chat(const QString& name, QObject* parent) :
    MyListItem(parent), m_name(name)
{
}

QVariant Chat::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case Peer:
        return tr("Peer");
    case Contact:
        return tr("Phone");
    case Direction:
        return tr("Direction");
    case Timestamp:
        return tr("Timestamp");
        break;
    case MessageId:
        return tr("Message Id");
    case MessageContent:
        return tr("Message text");
    case Status:
        return tr("Status");
    case ForwardFromContact:
        return tr("Forward from");
    case ForwardTimestamp:
        return tr("Forward timestamp");
    default:
        break;
    }

    return QVariant();
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

void Chat::appendMessage(const TelegramNamespace::Message& m){
    //check if id already exists. if this is the case, just update
    m_messages.append(new Message(m));
    //if timestamp doesn't exists, update it with QDateTime::currentMSecsSinceEpoch() / 1000;
}

void Chat::appendMessage(Message* msg){
    m_messages.append(msg);
}

QString Chat::lastMessage() const{
    if(m_messages.isEmpty())
        return "empty";
    return m_messages.last()->text();
}

//getters and setters
QDeclarativeListProperty<Message> Chat::messages()  {
    return QDeclarativeListProperty<Message>(this, m_messages);
}

void Chat::changeName(const QString& n){
    m_name = n;
    emit dataChanged();
}

//setMessageMediaData
//setMessageDeliveryStatus


