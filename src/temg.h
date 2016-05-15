#ifndef TEMG_H
#define TEMG_H

//QT
#include "qmlapplicationviewer.h"
#include <QFile>
#include <QIODevice>
#include <QDeclarativeContext>
#include <QDeclarativeView>
#include <QGraphicsObject>

//telegram-qt
#include "telegram-qt/CTelegramCore.hpp"
#include "telegram-qt/CAppInformation.hpp"
#include "telegram-qt/TelegramNamespace.hpp"

//temg
#include "feed.h"
#include "statusicon.h"
//#include "register.h"
#include "enum.h"

#include <QDebug>

class TEMG : public QmlApplicationViewer
{
    Q_OBJECT

public:
    TEMG(QWidget *parent = 0);

    //overwriting create from QmlApplicationViewer
    static TEMG* create();



    void loadQML();
    void createMockChats();

protected slots:
    void whenConnectionStateChanged(TelegramNamespace::ConnectionState);
    void whenLoggedOut(bool result);
    void whenPhoneStatusReceived(const QString& phone, bool registered, bool invited);
    void whenAuthSignErrorReceived(TelegramNamespace::AuthSignError,const QString&);
    void whenPhoneCodeRequested();
    void whenMessageReceived(const TelegramNamespace::Message &message);
    void whenRegisterGetCode(const QString& number);
    void whenRegisterSign(const QString& number, const QString& code, const QString& name, const QString& surname);

signals:

private:
    void setAppState(AppState);

    quint32 m_activeChatId;
    bool m_chatCreationMode;

    CTelegramCore *m_core;

    bool m_registered;

    AppState m_appState;



    //temg
    Feed* m_feedModel;
    StatusIcon* m_statusIcon;
    //Register* m_register;
};


#endif // TEMG_H
