#include "message.h"

Message::Message(QObject *parent) :
    QObject(parent), sender(QString("unknown"))
{
}
