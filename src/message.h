#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QAbstractListModel>
#include "listmodel.h"

class Message : public ListItem
{
    Q_OBJECT
    Q_PROPERTY(QString sender READ sender WRITE setSender)
//    Q_PROPERTY(QString sender READ getSender WRITE setSender NOTIFY changeSender)
    Q_PROPERTY(QString destiny READ destiny WRITE setDestiny)
    Q_PROPERTY(QString content READ content WRITE setContent)
public:
    enum Roles {
        SenderRole,
        DestinyRole,
        ContentRole
    };

    Message(QObject *parent = 0): ListItem(parent) {}
    QHash<int, QByteArray> roleNames() const;
    QVariant data(int role) const;
//    explicit Message(QObject *parent = 0, QString messageSender = NULL, QString messageContent = NULL);
    explicit Message(const QString&, const QString&, const QString&, QObject *parent = 0);
    void setSender(const QString&);
    void setDestiny(const QString&);
    void setContent(const QString&);
    inline QString id() const { return m_sender; }
    inline QString sender() const { return m_sender; }
    inline QString destiny() const { return m_destiny; }
    inline QString content() const { return m_content; }

private:
    QString m_sender;
    QString m_destiny;
    QString m_content;

signals:
//    void setSender(const QString&);
//    void changeSender(const QString&);

public slots:

};

#endif // MESSAGE_H
