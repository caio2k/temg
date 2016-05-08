#ifndef STATUSICON_H
#define STATUSICON_H

#include <QDeclarativeItem>

#include "enum.h"

#include <QDebug>

class StatusIcon : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QString icon READ icon NOTIFY changeIcon)

public:
    explicit StatusIcon(QDeclarativeItem *parent = 0);
    inline QString icon() const { return m_icon; }
    Q_INVOKABLE void changeStatusIcon(AppState);

signals:
    void changeIcon();

public slots:

private:
    AppState m_status;
    QString m_icon;

};

#endif // STATUSICON_H
