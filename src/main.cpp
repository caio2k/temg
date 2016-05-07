#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/qdeclarative.h>
#include "qmlapplicationviewer.h"
#include "chat.h"
#include "message.h"
#include "listmodel.h"
#include "feed.h"

#include <QDebug>

MyListModel* createModel(QObject* parent) {
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
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    qmlRegisterType<Chat>("Temg.Core", 1,0, "Chat");
    qmlRegisterType<Message>("Temg.Core", 1,0, "Message");
    //qmlRegisterType<MyListModel>("Temg.Core", 1,0, "MyListModel");

    app->setApplicationName("temg");
    app->setOrganizationName("temg");
    app->setApplicationVersion(APP_VERSION);

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer->setMainQmlFile(QLatin1String("qml/temg.qml"));
    MyListModel* chatsModel2 = createModel(viewer->parent());
    //Message *msg1 = new Message("mandador1","destinador1","olá, vou dominar o mundo");
    viewer->rootContext()->setContextProperty("chatsModel2",  chatsModel2);
    //chatsModel2->takeRow(0)->appendRow(msg1);
    viewer->showExpanded();

    Chat *testchat = new Chat("newname");
    qWarning() << testchat->name();
    testchat->changeName("oi");
    qWarning() << testchat->name();
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
    //viewer->setSource(QUrl::fromLocalFile("qml/temg.qml"));

}
