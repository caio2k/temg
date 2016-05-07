#include "feed.h"

#include "chat.h"

#include <QDebug>

Feed::Feed(QObject *parent) :
    MyListModel(new Chat,parent)
{
}

Feed::Feed(Chat* c, QObject *parent) :
    MyListModel(new Chat,parent)
{
    appendRow(c);
}


void Feed::appendMessage(int idx, Message* m){
    static_cast<Chat*>(m_list.at(idx))->appendMessage(m);
}

void Feed::appendMessage(const QString& id, Message* m){
    static_cast<Chat*>(find(id))->appendMessage(m);
}

