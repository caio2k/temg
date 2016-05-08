#include "temg.h"
#include "statusicon.h"
TEMG::TEMG(QWidget *parent) :
    QmlApplicationViewer(parent),
    m_feedModel(new Feed(parent)),
    m_statusIcon(new StatusIcon())
{
    //telegram-qt: setting initial values
    m_core=new CTelegramCore(this);
    CAppInformation appInfo;
    ///todo: get an app hash and id
    appInfo.setAppId(14617);
    appInfo.setAppHash(QLatin1String("e17ac360fd072f83d5d08db45ce9a121"));
    appInfo.setAppVersion(QLatin1String("0.1"));
    appInfo.setDeviceInfo(QLatin1String("pc"));
    appInfo.setOsInfo(QLatin1String("GNU/Linux"));
    appInfo.setLanguageCode(QLatin1String("en"));

    //telegram-qt: implementing signal
    connect(m_core, SIGNAL(connectionStateChanged(TelegramNamespace::ConnectionState)),
            SLOT(whenConnectionStateChanged(TelegramNamespace::ConnectionState)));
    connect(m_core, SIGNAL(authSignErrorReceived(TelegramNamespace::AuthSignError,QString)),
            SLOT(whenAuthSignErrorReceived(TelegramNamespace::AuthSignError,QString)));

    m_core->setAppInformation(&appInfo);
    m_core->setAutoReconnection(true);
    setAppState(AppStateNone);

    //load secret file if it exists
    QFile file("/home/caio/secret.temg");
    if(file.open(QIODevice::ReadOnly)) {
        qWarning() << "secret: loading file";
        QByteArray secretInfo = QByteArray::fromHex(file.readAll());
        m_core->restoreConnection(secretInfo);
    }
    else{
        qWarning() << "secret: NOT loading file, please proceed to registration";
    }
    //setStatusIcon("");
    //statusIcon = new QString("");
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

    //conneting signals

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
    Chat* chat1 = new Chat("chat1");
    m_feedModel->appendRow(chat1);
    Message* msg1 = new Message("oia1","oib1","oic1");
    Message* msg2 = new Message("oia1","oib2","oic2");
    Message* msg3 = new Message("oia3","oib3","oic3");
    Message* msg4 = new Message("oia4","oib4","oic4");
    chat1->appendMessage(msg1);
    chat1->appendMessage(msg2);
    chat1->appendMessage(msg1);
    m_feedModel->appendRow(new Chat("chat2", m_feedModel));
    m_feedModel->appendMessage(1,msg3);
    m_feedModel->appendRow(new Chat("chat3", m_feedModel));
    m_feedModel->appendMessage("chat3",msg4);
}

//QT
TEMG* TEMG::create()
{
#ifdef HARMATTAN_BOOSTER
    return new TEMG(MDeclarativeCache::qDeclarativeView(), 0);
#else
    return new TEMG();
#endif
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
        default:
            qDebug() << "Unknown auth sign error:" << errorMessage;
            return;
    }
}

//telegram-qt handlers
void TEMG::setAppState(AppState newState){
    qWarning() << "changing state " << m_appState << " to " << newState;
    m_appState = newState;
    m_statusIcon->changeStatusIcon(newState);
}
