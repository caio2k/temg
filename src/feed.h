#ifndef FEED_H
#define FEED_H
#include "listmodel.h"

#include <QObject>
#include "chat.h"

class Feed : public MyListModel
{
    Q_OBJECT

public:
    explicit Feed(QObject* parent = 0);
    Feed(Chat* c, QObject* parent = 0);

    void appendMessage(const TelegramNamespace::Message&);
    void appendMessage(int idx, const TelegramNamespace::Message &);
    void appendMessage(const QString&, const TelegramNamespace::Message &);

private:

signals:

public slots:
};

#endif // FEED_H
