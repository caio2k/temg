#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H
#include "listmodel.h"

#include "messageItem.h"

class MessageModel : public MyListModel
{
    Q_OBJECT

public:
    explicit MessageModel(QObject* parent = 0);

private:

signals:

public slots:
};
#endif // MESSAGEMODEL_H
