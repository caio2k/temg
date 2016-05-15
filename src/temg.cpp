#include "temg.h"

#ifdef HARMATTAN_BOOSTER
#include <MDeclarativeCache>
#endif

TEMG::TEMG(QWidget *parent) :
    QmlApplicationViewer(parent),
    m_feedModel(new Feed(parent)),
    m_statusIcon(new StatusIcon())
{
    init();
}

TEMG::TEMG(QDeclarativeView *view, QWidget *parent)
    : QmlApplicationViewer(view,parent),
    m_feedModel(new Feed(parent)),
    m_statusIcon(new StatusIcon())
{
    init();
}

void TEMG::init(){
    //telegram-qt: setting initial values
    m_core=new CTelegramCore(this);
    CAppInformation appInfo;
    ///todo: get an app hash and id
    appInfo.setAppId(20904);
    appInfo.setAppHash(QLatin1String("50af64db4d215d1527881e45b39b7e21"));
    appInfo.setAppVersion(QLatin1String("0.1"));
    appInfo.setDeviceInfo(QLatin1String("pc"));
    appInfo.setOsInfo(QLatin1String("GNU/Linux"));
    appInfo.setLanguageCode(QLatin1String("en"));

    //telegram-qt: implementing signal
    ////connection status
    connect(m_core, SIGNAL(connectionStateChanged(TelegramNamespace::ConnectionState)), SLOT(whenConnectionStateChanged(TelegramNamespace::ConnectionState)));
    connect(m_core, SIGNAL(authSignErrorReceived(TelegramNamespace::AuthSignError,QString)), SLOT(whenAuthSignErrorReceived(TelegramNamespace::AuthSignError,QString)));
    connect(m_core, SIGNAL(loggedOut()), SIGNAL(whenLoggedOut()));
    connect(m_core, SIGNAL(phoneStatusReceived(const QString, bool, bool)), SIGNAL(whenPhoneStatusReceived(const QString, bool, bool)));

    ////register
    connect(m_core, SIGNAL(phoneCodeRequested()), SIGNAL(whenPhoneCodeRequested()));

    ////message
    connect(m_core, SIGNAL(messageReceived(TelegramNamespace::Message)), SLOT(whenMessageReceived(TelegramNamespace::Message)));

//m_core->connectionSecretInfo().toHex()

    m_core->setAppInformation(&appInfo);
    m_core->setAutoReconnection(true);
    setAppState(AppStateNone);


    TelegramNamespace::MessageFlags flags = TelegramNamespace::MessageFlagNone;
    m_core->setMessageReceivingFilter(flags);
//    m_core->setAcceptableMessageTypes(TelegramNamespace::MessageTypeText|TelegramNamespace::MessageTypePhoto|TelegramNamespace::MessageTypeGeo);
    m_core->setAcceptableMessageTypes(TelegramNamespace::MessageTypeText);


    settingsLoad();

    if (m_secretInfo.isEmpty()){
        m_core->initConnection(m_servers);
    }
    else{
        m_core->restoreConnection(m_secretInfo);
    }

    setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
}

void TEMG::loadQML(){

    rootContext()->setContextProperty("chatsModel", m_feedModel);
    rootContext()->setContextProperty("statusIcon", m_statusIcon);
    setMainQmlFile(QLatin1String("qml/temg.qml"));
    Chat *testchat = new Chat("newname");
    qWarning() << testchat->name();
    testchat->changeName("oi");
    qWarning() << testchat->name();
    m_feedModel->appendRow(testchat);

    //qml signals
    QObject::connect(this->rootObject(), SIGNAL(registerGetCode(QString)), SLOT(whenRegisterGetCode(QString)));
    QObject::connect(this->rootObject(), SIGNAL(registerSign(QString,QString,QString,QString)), SLOT(whenRegisterSign(QString,QString,QString,QString)));

    //QGraphicsObject * qgo = rootObject();
    //QObject* si = rootObject();
    /*
    StatusIcon* si = rootObject()->findChild<StatusIcon*>();
    qWarning() << si;
    if(si){
        connectStatusIcon(si);
        qWarning() << "conectou";
    }
    else
        qWarning() << "non conectou";
*/
}

void TEMG::createMockChats(){
    Chat* chat1 = new Chat("1111");
    m_feedModel->appendRow(chat1);
    TelegramNamespace::Message msg1 = TelegramNamespace::Message();
    TelegramNamespace::Message msg2 = TelegramNamespace::Message();
    TelegramNamespace::Message msg3 = TelegramNamespace::Message();
    TelegramNamespace::Message msg4 = TelegramNamespace::Message();
    chat1->appendMessage(msg1);
    chat1->appendMessage(msg2);
    chat1->appendMessage(msg1);
    msg1.text="oi1";
    msg1.peer="1111";
    msg2.text="oi2";
    msg2.peer="1111";
    msg3.text="oi3";
    msg3.peer="3333";
    msg4.text="oi4";
    msg4.peer="3333";
    m_feedModel->appendRow(new Chat("3333", m_feedModel));
    msg3.peer="3333";
    m_feedModel->appendMessage(msg3);
    m_feedModel->appendMessage("3333",msg4);
//    m_feedModel->appendMessage("4444",msg4);
}

//QT
TEMG* TEMG::create()
{
//#ifdef HARMATTAN_BOOSTER
//    return new TEMG(MDeclarativeCache::qDeclarativeView(), 0);
//#else
    return new TEMG();
//#endif
}

//temg signal handling


//telegram-qt signal
void TEMG::whenConnectionStateChanged(TelegramNamespace::ConnectionState state)
{
    switch (state) {
    case TelegramNamespace::ConnectionStateConnected:
        setAppState(AppStateConnected);
        break;
    case TelegramNamespace::ConnectionStateAuthRequired:
        setAppState(AppStateCodeRequired);
//        ui->phoneNumber->setFocus();
        break;
    case TelegramNamespace::ConnectionStateAuthenticated:
        setAppState(AppStateSignedIn);

//        if (ui->workLikeClient->isChecked()) {
            m_core->setOnlineStatus(true);
//        }
        break;
    case TelegramNamespace::ConnectionStateReady:
        setAppState(AppStateReady);
        m_secretInfo = m_core->connectionSecretInfo();
        settingsSave();

//        ui->phoneNumber->setText(m_core->selfPhone());
//        ui->firstName->setText(m_core->contactFirstName(m_core->selfPhone()));
//        ui->lastName->setText(m_core->contactLastName(m_core->selfPhone()));
        break;
    case TelegramNamespace::ConnectionStateDisconnected:
        setAppState(AppStateDisconnected);
        break;
    default:
        break;
    }
}

void TEMG::whenLoggedOut(bool result)
{
    qDebug() << Q_FUNC_INFO << result;
    setAppState(AppStateLoggedOut);
}

void TEMG::whenPhoneStatusReceived(const QString &phone, bool registered, bool invited)
{
    ///todo: add valid check here
    if (phone == phone) {
        QString registeredText = registered ? tr("Registered") : tr("Not registered");
        QString invitedText = invited ? tr("invited") : tr("not invited");
        qWarning() << registeredText << invitedText;
        m_registered = registered;
    } else {
        qDebug() << "Warning: Received status for different phone number" << phone << registered << invited;
    }
}

void TEMG::whenPhoneCodeRequested()
{
    setAppState(AppStateCodeSent);
}

void TEMG::whenAuthSignErrorReceived(TelegramNamespace::AuthSignError errorCode, const QString &errorMessage){
    switch (errorCode) {
    case TelegramNamespace::AuthSignErrorPhoneNumberIsInvalid:
        if (m_appState == AppStateCodeRequested) {
            qWarning() << "phone number is invalid";
            setAppState(AppStateNone);
        }
        break;
    case TelegramNamespace::AuthSignErrorPhoneCodeIsExpired:
        qWarning() << "phone code is expired";
        break;
    case TelegramNamespace::AuthSignErrorPhoneCodeIsInvalid:
        qWarning() << "phone code is invalid";
        break;
    case TelegramNamespace::AuthSignErrorPhoneNumberIsOccupied:
        qWarning() << "phone number already registered";
        m_registered = true;
        m_core->signIn(m_phoneNumber, m_code);
        break;
    default:
        qDebug() << "Unknown auth sign error:" << errorMessage;
        return;
    }
}

void TEMG::whenMessageReceived(const TelegramNamespace::Message &message){


    TelegramNamespace::Message processedMessage = message;

    switch (processedMessage.type) {
    case TelegramNamespace::MessageTypePhoto:
    case TelegramNamespace::MessageTypeVideo:
        //m_core->requestMessageMediaData(processedMessage.id);
        break;
    case TelegramNamespace::MessageTypeGeo: {
        TelegramNamespace::MessageMediaInfo info;
        //m_core->getMessageMediaInfo(&info, processedMessage.id);
        processedMessage.text = QString("%1%2, %3%4").arg(info.latitude()).arg(QChar(0x00b0)).arg(info.longitude()).arg(QChar(0x00b0));
    }
        break;
    default:
        break;
    }

    m_feedModel->appendMessage(processedMessage);
//    m_core->setMessageRead(processedMessage.contact, processedMessage.id);
}

//settings
void TEMG::settingsLoad(){
    qWarning() << "loading from" << m_settingsFile;
    QDir dir(QDir::homePath());
    dir.mkpath(m_settingsPath);
    QSettings settings(m_settingsFile, QSettings::NativeFormat);
    m_phoneNumber = settings.value("phoneNumber", "").toString();
    m_secretInfo = QByteArray::fromHex(settings.value("secretInfo", "").toByteArray());
    m_servers.append(TelegramNamespace::DcOption(settings.value("server1","149.154.167.40").toString(), 443));
}
void TEMG::settingsSave(){
    qWarning() << "saving to" << m_settingsFile;
    QDir dir(QDir::homePath());
    dir.mkpath(m_settingsPath);
    QSettings settings(m_settingsFile, QSettings::NativeFormat);
    settings.setValue("phoneNumber", m_phoneNumber);
    settings.setValue("secretInfo", m_secretInfo.toHex());
    settings.setValue("server1", m_servers.at(0).address);
}

//telegram-qt x qml
void TEMG::whenRegisterGetCode(const QString& number){
    qWarning() << "getting code" << number;

    m_phoneNumber = number;
    settingsSave();
    m_core->requestPhoneStatus(m_phoneNumber);
    m_core->requestPhoneCode(m_phoneNumber);

    m_appState = AppStateCodeRequested;
}
void TEMG::whenRegisterSign(const QString& number, const QString& code, const QString& name, const QString& surname){
    m_phoneNumber = number;
    m_code = code;
    if(m_registered){
        qWarning() << "signing IN " << number << "with" << code;
        m_core->signIn(m_phoneNumber, m_code);
    }
    else{
        qWarning() << "signing UP " << number;
        m_core->signUp(m_phoneNumber, m_code, name, surname);
    }
}


//telegram-qt handlers
void TEMG::setAppState(AppState newState){
    qWarning() << "changing state " << m_appState << " to " << newState;
    m_appState = newState;
    m_statusIcon->changeStatusIcon(newState);
}
