#ifndef TEMG_H
#define TEMG_H

//QT
#include "qmlapplicationviewer.h"
#include <QFile>
#include <QIODevice>

//telegram-qt
#include "telegram-qt/CTelegramCore.hpp"
#include "telegram-qt/CAppInformation.hpp"
#include "telegram-qt/TelegramNamespace.hpp"

#include <QDebug>

class TEMG : public QmlApplicationViewer
{
    Q_OBJECT

public:
    TEMG(QWidget *parent = 0);

    //overwriting create from QmlApplicationViewer
    static TEMG* create();
    void initialize();

    enum AppState {
        AppStateNone,
        AppStateConnected,
        AppStateCodeRequired,
        AppStateCodeRequested,
        AppStateCodeSent,
        AppStateSignedIn,
        AppStateReady,
        AppStateLoggedOut,
        AppStateDisconnected
    };

protected slots:
    void whenConnectionStateChanged(TelegramNamespace::ConnectionState);
    void whenLoggedOut(bool result);
    void whenPhoneStatusReceived(const QString &phone, bool registered, bool invited);
    void whenPhoneCodeRequested();
    void whenAuthSignErrorReceived(TelegramNamespace::AuthSignError,const QString&);

private:
    void setAppState(TEMG::AppState);

    quint32 m_activeChatId;
    bool m_chatCreationMode;

    CTelegramCore *m_core;

    bool m_registered;

    AppState m_appState;


};


#endif // TEMG_H
