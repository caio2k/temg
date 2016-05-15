#include "message.h"

Message::Message(const TelegramNamespace::Message& m, QObject *parent) :
    MyListItem(parent), m_peer(m.peer), m_contact(m.contact), m_text(m.text), m_id(m.id), m_timestamp(m.timestamp), m_fwdContact(m.fwdContact), m_fwdTimestamp(m.fwdTimestamp)
{
}

//overwriting functions from ListItem
QHash<int, QByteArray> Message::roleNames() const
{
  QHash<int, QByteArray> names;
  names[PeerRole] = "peer";
  names[ContactRole] = "contact";
  names[TextRole] = "text";
  return names;
}

QVariant Message::data(int role) const
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
void Message::setPeer(const QString& p){
    m_peer = p;
}

void Message::setContact(const QString& c){
    m_contact = c;
}

void Message::setText(const QString& t){
    m_text = t;
}

