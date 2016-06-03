#include "chatItem.h"
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
  names[LastRole] = "lastMessage";
  names[MessagesRole] = "messages";
  names[PeerRole] = "peer";
  names[TextRole] = "text";
  names[CountRole] = "count";
  return names;
}
QVariant Chat::data(int role) const
{
  QList<QVariant> qvl;
  qvl.clear();
  switch(role) {
  case NameRole:
    return name();
  case MessagesRole:
      return QVariant(&m_messages); //it doesnt work
  case TextRole:
      for(int i=0;m_messages.size()>i;i++){
          qWarning() << m_messages.at(i)->text();
          qvl.append(m_messages.at(i)->text());
      }
      return qvl; //it doesnt work
  case PeerRole:
      for(int i=0;m_messages.size()>i;i++){
          qWarning() << m_messages.at(i)->peer();
          qvl.append(m_messages.at(i)->peer());
      }
      return qvl; //it doesnt work
  case CountRole:
      return QVariant(m_messages.count()); //it doesnt work
  case LastRole:
    return lastMessage();
  default:
    return QVariant();
  }
}

void Chat::appendMessage(const TelegramNamespace::Message& m){
    //check if id already exists. if this is the case, just update
    m_messages.append(new MessageItem(m));
    emit dataChanged();
    //if timestamp doesn't exists, update it with QDateTime::currentMSecsSinceEpoch() / 1000;
}

void Chat::appendMessage(MessageItem* msg){
    m_messages.append(msg);
    emit dataChanged();
}

QString Chat::lastMessage() const{
    if(m_messages.isEmpty())
        return "empty";
    return m_messages.last()->text();
}

//getters and setters
QDeclarativeListProperty<MessageItem> Chat::messages() const {
    //return QDeclarativeListProperty<Message>(0, m_messages);
    //const QDeclarativeListProperty<Message> c(this, 0, &Chat::appendMessagesList, 0, &Chat::atMessagesList, &Chat::clearMessagesList);
    //const QDeclarativeListProperty<Message> c(const_cast<Chat*>(this), 0, 0,0,0,0);
    //return c;
    return QDeclarativeListProperty<MessageItem>(const_cast<Chat*>(this), 0, &Chat::appendMessagesList, 0, &Chat::atMessagesList, &Chat::clearMessagesList);
    //return *c;
}

void Chat::changeName(const QString& n){
    m_name = n;
    emit dataChanged();
}

//setMessageMediaData
//setMessageDeliveryStatus


