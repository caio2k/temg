#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

class MyListItem: public QObject {
  Q_OBJECT

public:
  MyListItem(QObject* parent = 0) : QObject(parent) {}
  virtual ~MyListItem() {}
  virtual QString id() const = 0;
  virtual QVariant data(int role) const = 0;
  virtual QHash<int, QByteArray> roleNames() const = 0;

signals:
  void dataChanged();
};

class MyListModel : public QAbstractListModel
{
  Q_OBJECT

public:
  explicit MyListModel(MyListItem* prototype, QObject* parent = 0);
  ~MyListModel();
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  void appendRow(MyListItem* item);
  void appendRows(const QList<MyListItem*> &items);
  void insertRow(int row, MyListItem* item);
  bool removeRow(int row, const QModelIndex &parent = QModelIndex());
  bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
  MyListItem* takeRow(int row);
  MyListItem* find(const QString &id);
  QModelIndex indexFromItem( const MyListItem* item) const;
  void clear();
  QHash<int, QByteArray> roleNames() const;

private slots:
  void handleItemChange();

private:
  MyListItem* m_prototype;
  QList<MyListItem*> m_list;
};


#endif // LISTMODEL_H
