#ifndef CHAT_H
#define CHAT_H

#include <QObject>

class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = 0);

    // getters and setters
    QString getName();
    void setName(const QString &n);

private:
    QString chatName;

signals:

public slots:

};

#endif // CHAT_H
