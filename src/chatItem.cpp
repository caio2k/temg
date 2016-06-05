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

ChatItem::ChatItem(const QString& name, QObject* parent) :
    MyListItem(parent), m_name(name)
{
    m_messages = new QList<MyListItem*>();
}

QVariant ChatItem::headerData(int section, Qt::Orientation orientation, int role) const
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
QHash<int, QByteArray> ChatItem::roleNames() const
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
QVariant ChatItem::data(int role) const
{
  QList<QVariant> qvl;
  qvl.clear();
  switch(role) {
  case NameRole:
    return name();
  case MessagesRole:
      return QVariant(&m_messages); //it doesnt work
  case TextRole:
      for(int i=0;m_messages->size()>i;i++){
          qWarning() << qobject_cast<MessageItem*>(m_messages->at(i))->text();
          qvl.append(qobject_cast<MessageItem*>(m_messages->at(i))->text());
      }
      return qvl; //it doesnt work
  case PeerRole:
      for(int i=0;m_messages->size()>i;i++){
          qWarning() << qobject_cast<MessageItem*>(m_messages->at(i))->peer();
          qvl.append(qobject_cast<MessageItem*>(m_messages->at(i))->peer());
      }
      return qvl; //it doesnt work
  case CountRole:
      return QVariant(m_messages->count()); //it doesnt work
  case LastRole:
    return lastMessage();
  default:
    return QVariant();
  }
}

void ChatItem::appendMessage(const TelegramNamespace::Message& m){
    //check if id already exists. if this is the case, just update
    m_messages->append(new MessageItem(m));
    emit dataChanged();
    //if timestamp doesn't exists, update it with QDateTime::currentMSecsSinceEpoch() / 1000;
}

void ChatItem::appendMessage(MessageItem* msg){
    m_messages->append(msg);
    emit dataChanged();
}

QString ChatItem::lastMessage() const{
    if(m_messages->isEmpty())
        return "empty";
    return qobject_cast<MessageItem*>(m_messages->last())->text();
}

void ChatItem::changeName(const QString& n){
    m_name = n;
    emit dataChanged();
}

//setMessageMediaData
//setMessageDeliveryStatus


