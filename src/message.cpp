#include "message.h"

Message::Message(const QString& sender, const QString& destiny, const QString& content, QObject *parent) :
    ListItem(parent), m_sender(sender), m_destiny(destiny), m_content(content)
{
}

//overwriting functions from ListItem
QHash<int, QByteArray> Message::roleNames() const
{
  QHash<int, QByteArray> names;
  names[SenderRole] = "sender";
  names[DestinyRole] = "destiny";
  names[ContentRole] = "content";
  return names;
}

QVariant Message::data(int role) const
{
  switch(role) {
  case SenderRole:
    return sender();
  case DestinyRole:
    return destiny();
  case ContentRole:
    return content();
  default:
    return QVariant();
  }
}

//setters
void Message::setSender(const QString& s){
    m_sender = s;
}

void Message::setDestiny(const QString& s){
    m_destiny = s;
}

void Message::setContent(const QString& m){
    m_content = m;
}

