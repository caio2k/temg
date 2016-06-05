#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H
#include "listModel.h"

#include "messageItem.h"

class MessageModel : public MyListModel
{
    Q_OBJECT

public:
    explicit MessageModel(QObject* parent = 0);
    void setMessageItem(QList<MyListItem*>* mi);

private:

signals:
  void dataChanged();

public slots:
};
#endif // MESSAGEMODEL_H
