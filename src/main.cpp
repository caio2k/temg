#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/qdeclarative.h>
#include "qmlapplicationviewer.h"
#include "chat.h"
#include "message.h"

#include <QDebug>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    qmlRegisterType<Chat>("Temg.Core", 1,0, "Chat");
    qmlRegisterType<Message>("Temg.Core", 1,0, "Message");

    app->setApplicationName("temg");
    app->setOrganizationName("temg");
    app->setApplicationVersion(APP_VERSION);

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer->setMainQmlFile(QLatin1String("qml/temg.qml"));
    viewer->showExpanded();

    Chat *testchat = new Chat(0,"newname");
    qWarning() << testchat->getName();
    testchat->setName("oi");
    qWarning() << testchat->getName();
    //Message *msg1 = new Message("mandador1","destinador1","olá, vou dominar o mundo");
    //Message msg2("mandador2", "destinador2","o pinky");
    //testchat->appendMessage(*msg1);
    //testchat->appendMessage(msg2);
   // testchat->appendMessage(new Message(0,"mandador3","e o cérebro"));
    //QDeclarativeListProperty<Message> testlist = testchat->messages();
    //qWarning() << testlist->count;
    //for(int i=0;i < (int) &testlist->count();i++){
    //    qWarning() << "oi " << i;
    //}
    //qWarning() << testchat->messages();

    return app->exec();
    //delete msg3;
    //delete msg1;
    delete testchat;

}
