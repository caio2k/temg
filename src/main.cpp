//QT includes
#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/qdeclarative.h>
//#include "qmlapplicationviewer.h"

//temg classes
#include "chatItem.h"
#include "chatModel.h"
#include "messageItem.h"
#include "listModel.h"
#include "statusicon.h"
#include "temg.h"

//telegram-qt classes
#include "telegram-qt/CTelegramCore.hpp"
#include "telegram-qt/CAppInformation.hpp"

#include <QDebug>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    //temg: making classes available in QML
    qmlRegisterType<ChatItem>("Temg.Core", 1,0, "ChatItem");
    qmlRegisterType<ChatModel>("Temg.Core", 1,0, "ChatModel");
    qmlRegisterType<MessageItem>("Temg.Core", 1,0, "MessageItem");
    qmlRegisterType<MessageModel>("Temg.Core", 1,0, "MessageModel");
    qmlRegisterType<StatusIcon>("Temg.Core", 1,0, "StatusIcon");
    //qmlRegisterType<Register>("Temg.Core", 1,0, "Register");

    //QT
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<TEMG> viewer(TEMG::create());

    //QT
    app->setApplicationName("temg");
    app->setOrganizationName("temg");
    app->setApplicationVersion(APP_VERSION);

    //temg: intialize QML signals
    viewer->loadQML();
    viewer->createMockChats();
    viewer->showExpanded();

    return app->exec();


}
