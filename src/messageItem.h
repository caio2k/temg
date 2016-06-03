#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QAbstractListModel>

#include "listmodel.h"

#include "TelegramNamespace.hpp"

class MessageItem : public MyListItem
{
    Q_OBJECT
    Q_PROPERTY(QString peer READ peer WRITE setPeer)
//    Q_PROPERTY(QString sender READ getSender WRITE setSender NOTIFY changeSender)
    Q_PROPERTY(QString contact READ contact WRITE setContact)
    Q_PROPERTY(QString text READ text WRITE setText)
public:
    enum Roles {
        PeerRole,
        ContactRole,
        TextRole
    };

    MessageItem(QObject *parent = 0): MyListItem(parent) {}
    QHash<int, QByteArray> roleNames() const;
    QVariant data(int role) const;
//    explicit Message(QObject *parent = 0, QString messageSender = NULL, QString messageContent = NULL);
    explicit MessageItem(const TelegramNamespace::Message&, QObject *parent = 0);

    //getters and setters
    void setPeer(const QString&);
    void setContact(const QString&);
    void setText(const QString&);
    inline QString id() const { return QString(m_id); }
    inline QString peer() const { return m_peer; }
    inline QString contact() const { return m_contact; }
    inline QString text() const { return m_text; }

private:
    QString m_peer;
    QString m_contact;
    QString m_text;
    quint32 m_id;
    quint32 m_timestamp;
    QString m_fwdContact;
    quint32 m_fwdTimestamp;
    //MessageType type;
    //MessageFlags flags;
signals:
//    void setSender(const QString&);
//    void changeSender(const QString&);

public slots:

};

#endif // MESSAGE_H
