#include "statusicon.h"

StatusIcon::StatusIcon(QDeclarativeItem *parent) :
    QDeclarativeItem(parent), m_icon(QString("icon-m-presence-offline"))
{
    qWarning() << "initial icon" << m_icon;
}


void StatusIcon::changeStatusIcon(AppState as){
    if(m_status==as){
        qWarning() << "got called to change to the same  " << as;
        return;
    }
    qWarning() << "got called to change to different " << as;
    switch (as){
    case AppStateConnected:
        m_icon = QString("icon-m-presence-online");
        break;
    case AppStateCodeRequired:
        m_icon = QString("icon-m-presence-busy");
        break;
    case AppStateSignedIn:
        m_icon = QString("icon-m-presence-online");
        break;
    case AppStateReady:
        m_icon = QString("icon-m-presence-online");
        break;
    case AppStateDisconnected:
        m_icon = QString("icon-m-presence-offline");
        break;
    default:
        m_icon = QString("icon-m-presence-unknown");
        break;
    }
    emit changeIcon();
}

