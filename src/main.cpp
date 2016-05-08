//QT includes
#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/qdeclarative.h>
//#include "qmlapplicationviewer.h"

//temg classes
#include "chat.h"
#include "message.h"
#include "listmodel.h"
#include "feed.h"
#include "statusicon.h"
#include "temg.h"

//telegram-qt classes
#include "telegram-qt/CTelegramCore.hpp"
#include "telegram-qt/CAppInformation.hpp"

#include <QDebug>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    //QT
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<TEMG> viewer(TEMG::create());

    //temg: making classes available in QML
    qmlRegisterType<Chat>("Temg.Core", 1,0, "Chat");
    qmlRegisterType<Message>("Temg.Core", 1,0, "Message");
    qmlRegisterType<Feed>("Temg.Core", 1,0, "Feed");
    qmlRegisterType<StatusIcon>("Temg.Core", 1,0, "StatusIcon");

    //QT
    app->setApplicationName("temg");
    app->setOrganizationName("temg");
    app->setApplicationVersion(APP_VERSION);

    viewer->showExpanded();
    //temg: intialize QML signals
    viewer->loadQML();
    viewer->createMockChats();

    return app->exec();


}
