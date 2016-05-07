#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/qdeclarative.h>
#include "qmlapplicationviewer.h"
#include "chat.h"
#include "message.h"
#include "listmodel.h"

#include <QDebug>

MyListModel* createModel(QObject* parent) {
    MyListModel* model = new MyListModel(new Chat, parent);
    model->appendRow(new Chat("chat1", model));
    model->appendRow(new Chat("chat2", model));
    model->appendRow(new Chat("chat3", model));
    return model;
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
