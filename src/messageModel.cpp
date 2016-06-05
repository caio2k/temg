#include "messageModel.h"

#include <qdebug.h>
#include <typeinfo>

MessageModel::MessageModel(QObject *parent) :
MyListModel(new MessageItem,parent)
{
}

void MessageModel::setMessageItem(QList<MyListItem*>* mi){
    qWarning() << "test" << mi << typeid(mi).name();
    m_list = mi;
    int rows = rowCount() - 1;
    qWarning() << "test2";
//    emit dataChanged();
}
