#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sender READ getSender WRITE setSender)
//    Q_PROPERTY(QString sender READ getSender WRITE setSender NOTIFY changeSender)
    Q_PROPERTY(QString content READ getContent WRITE setContent)
public:
    explicit Message(QObject *parent = 0, QString messageSender = NULL, QString messageContent = NULL);
    QString getSender();
    void setSender(const QString&);
    QString getContent();
    void setContent(const QString&);

private:
    QString messageSender;
    QString messageContent;

signals:
//    void setSender(const QString&);
//    void changeSender(const QString&);

public slots:

};

#endif // MESSAGE_H
