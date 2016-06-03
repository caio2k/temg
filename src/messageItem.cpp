#include "messageItem.h"

MessageItem::MessageItem(const TelegramNamespace::Message& m, QObject *parent) :
    MyListItem(parent), m_peer(m.peer), m_contact(m.contact), m_text(m.text), m_id(m.id), m_timestamp(m.timestamp), m_fwdContact(m.fwdContact), m_fwdTimestamp(m.fwdTimestamp)
{
    qWarning() << "creating msg" << m_peer << "with content" << m_text;
}

//overwriting functions from ListItem
QHash<int, QByteArray> MessageItem::roleNames() const
{
  QHash<int, QByteArray> names;
  names[PeerRole] = "peer";
  names[ContactRole] = "contact";
  names[TextRole] = "text";
  return names;
}

QVariant MessageItem::data(int role) const
{
  switch(role) {
  case PeerRole:
    return peer();
  case ContactRole:
    return contact();
  case TextRole:
    return text();
  default:
    return QVariant();
  }
}

//setters
void MessageItem::setPeer(const QString& p){
    m_peer = p;
}

void MessageItem::setContact(const QString& c){
    m_contact = c;
}

void MessageItem::setText(const QString& t){
    m_text = t;
}

