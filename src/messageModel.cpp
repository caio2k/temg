#include "messageModel.h"

MessageModel::MessageModel(QObject *parent) :
MyListModel(new MessageItem,parent)
{
}
