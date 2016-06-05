#ifndef TEMG_H
#define TEMG_H

//QT
#include "qmlapplicationviewer.h"
#include <QFile>
#include <QIODevice>
#include <QDeclarativeContext>
#include <QDeclarativeView>
#include <QGraphicsObject>
#include <QSettings>
#include <QDir>

//telegram-qt
#include "telegram-qt/CTelegramCore.hpp"
#include "telegram-qt/CAppInformation.hpp"
#include "telegram-qt/TelegramNamespace.hpp"

//temg
#include "chatModel.h"
#include "messageModel.h"
#include "statusicon.h"
//#include "register.h"
#include "enum.h"

#include <QDebug>

class TEMG : public QmlApplicationViewer
{
    Q_OBJECT

public:
    TEMG(QWidget *parent = 0);
    TEMG(QDeclarativeView *view, QWidget *parent);

    //overwriting create from QmlApplicationViewer
    static TEMG* create();

    void init();
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
    void whenMessageModelUpdate(const int index);

signals:

private:
    void setAppState(AppState);

    //settings
    void settingsSave();
    void settingsLoad();
    QString m_settingsPath;
    QString m_settingsFile;
    QVector<TelegramNamespace::DcOption> m_servers;

    quint32 m_activeChatId;
    bool m_chatCreationMode;

    CTelegramCore *m_core;

    bool m_registered;

    AppState m_appState;



    //temg
    ChatModel* m_chatModel;
    MessageModel *m_messageModel;
    StatusIcon* m_statusIcon;
    //Register* m_register;
    QString m_phoneNumber;
    QString m_code;
    QByteArray m_secretInfo;


};


#endif // TEMG_H
