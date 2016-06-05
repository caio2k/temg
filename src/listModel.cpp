/*
 * Author: Christophe Dumez <dchris@gmail.com>
 * License: Public domain (No attribution required)
 * Website: http://cdumez.blogspot.com/
 * Version: 1.0
 */

#include "listModel.h"

MyListModel::MyListModel(MyListItem* prototype, QObject *parent) :
    QAbstractListModel(parent), m_prototype(prototype)
{
  setRoleNames(m_prototype->roleNames());
  m_list = new QList<MyListItem*>();
}

int MyListModel::rowCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);
  return m_list->size();
}

QVariant MyListModel::data(const QModelIndex &index, int role) const
{
  if(!index.isValid() || index.row() < 0 || index.row() >= rowCount())
    return QVariant();
  return m_list->at(index.row())->data(role);
}

MyListModel::~MyListModel() {
  delete m_prototype;
  clear();
}

void MyListModel::appendRow(MyListItem *item)
{
  appendRows(QList<MyListItem*>() << item);
}

void MyListModel::appendRows(const QList<MyListItem *> &items)
{
  beginInsertRows(QModelIndex(), rowCount(), rowCount()+items.size()-1);
  foreach(MyListItem *item, items) {
    connect(item, SIGNAL(dataChanged()), SLOT(handleItemChange()));
    m_list->append(item);
  }
  endInsertRows();
}

void MyListModel::insertRow(int row, MyListItem *item)
{
  beginInsertRows(QModelIndex(), row, row);
  connect(item, SIGNAL(dataChanged()), SLOT(handleItemChange()));
  m_list->insert(row, item);
  endInsertRows();
}

void MyListModel::handleItemChange()
{
  MyListItem* item = static_cast<MyListItem*>(sender());
  QModelIndex index = indexFromItem(item);
  if(index.isValid())
    emit dataChanged(index, index);
}

MyListItem * MyListModel::find(const QString &id)
{
  foreach(MyListItem* item, *m_list) {
    if(item->id() == id) return item;
  }
  return 0;
}

QModelIndex MyListModel::indexFromItem(const MyListItem *item) const
{
  Q_ASSERT(item);
  for(int row=0; row<m_list->size(); ++row) {
    if(m_list->at(row) == item) return index(row);
  }
  return QModelIndex();
}

void MyListModel::clear()
{
  beginResetModel();
  qDeleteAll(*m_list);
  m_list->clear();
  endResetModel();
}

bool MyListModel::removeRow(int row, const QModelIndex &parent)
{
  Q_UNUSED(parent);
  if(row < 0 || row >= m_list->size()) return false;
  beginRemoveRows(QModelIndex(), row, row);
  delete m_list->takeAt(row);
  endRemoveRows();
  return true;
}

bool MyListModel::removeRows(int row, int count, const QModelIndex &parent)
{
  Q_UNUSED(parent);
  if(row < 0 || (row+count) >= m_list->size()) return false;
  beginRemoveRows(QModelIndex(), row, row+count-1);
  for(int i=0; i<count; ++i) {
    delete m_list->takeAt(row);
  }
  endRemoveRows();
  return true;
}

MyListItem * MyListModel::takeRow(int row)
{
  beginRemoveRows(QModelIndex(), row, row);
  MyListItem* item = m_list->takeAt(row);
  endRemoveRows();
  return item;
}

QHash<int, QByteArray> MyListModel::roleNames() const
{
    return m_prototype->roleNames();
}

MyListItem* MyListModel::get(int index) const {
    qWarning() << index << "at" <<  m_list->at(index);
    return m_list->at(index);
}
