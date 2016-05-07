//QT includes
#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/qdeclarative.h>
#include "qmlapplicationviewer.h"

//temg classes
#include "chat.h"
#include "message.h"
#include "listmodel.h"
#include "feed.h"

//telegram-qt classes
#include "telegram-qt/CTelegramCore.hpp"
#include "telegram-qt/CAppInformation.hpp"

#include <QDebug>

Feed* createModel(QObject* parent) {
    Chat* chat1 = new Chat("chat1");
    Feed* feed = new Feed(chat1,parent);
    Message* msg1 = new Message("oia1","oib1","oic1");
    Message* msg2 = new Message("oia1","oib2","oic2");
    Message* msg3 = new Message("oia3","oib3","oic3");
    Message* msg4 = new Message("oia4","oib4","oic4");
    chat1->appendMessage(msg1);
    chat1->appendMessage(msg2);
    chat1->appendMessage(msg1);
    feed->appendRow(new Chat("chat2", feed));
    feed->appendMessage(1,msg3);
    feed->appendRow(new Chat("chat3", feed));
    feed->appendMessage("chat3",msg4);
    return feed;
}


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    //QT
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    //temg: making classes available in QML
    qmlRegisterType<Chat>("Temg.Core", 1,0, "Chat");
    qmlRegisterType<Message>("Temg.Core", 1,0, "Message");
    qmlRegisterType<Feed>("Temg.Core", 1,0, "Feed");

    //QT
    app->setApplicationName("temg");
    app->setOrganizationName("temg");
    app->setApplicationVersion(APP_VERSION);

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer->setMainQmlFile(QLatin1String("qml/temg.qml"));

    //temg: mock model creation
    Feed* chatsModel = createModel(viewer->parent());
    viewer->rootContext()->setContextProperty("chatsModel",  chatsModel);
    viewer->showExpanded();
    Chat *testchat = new Chat("newname");
    qWarning() << testchat->name();
    testchat->changeName("oi");
    qWarning() << testchat->name();
    chatsModel->appendRow(testchat);

    //telegram-qt: setting initial values
    CAppInformation appInfo;
    ///todo: get an app hash and id
    appInfo.setAppId(14617);
    appInfo.setAppHash(QLatin1String("e17ac360fd072f83d5d08db45ce9a121"));
    appInfo.setAppVersion(QLatin1String("0.1"));
    appInfo.setDeviceInfo(QLatin1String("pc"));
    appInfo.setOsInfo(QLatin1String("GNU/Linux"));
    appInfo.setLanguageCode(QLatin1String("en"));

    //CTelegramCore* m_core2=new CTelegramCore(viewer->parent()),
    //m_core2->setAppInformation(&appInfo);
    //m_core2->setAutoReconnection(true);

    return app->exec();


    delete testchat;

}
