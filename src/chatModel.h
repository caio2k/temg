#ifndef CHATMODEL_H
#define CHATMODEL_H
#include "listModel.h"

#include <QObject>
#include "chatItem.h"

class ChatModel : public MyListModel
{
    Q_OBJECT

public:
    explicit ChatModel(QObject* parent = 0);
    ChatModel(ChatItem* c, QObject* parent = 0);

    void appendMessage(const TelegramNamespace::Message&);
    void appendMessage(int idx, const TelegramNamespace::Message &);
    void appendMessage(const QString&, const TelegramNamespace::Message &);

private:

signals:

public slots:
};

#endif // CHATMODEL_H
