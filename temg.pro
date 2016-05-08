# Add more folders to ship with the application, here
folder_qml.source = qml
folder_qml.target = ./
DEPLOYMENTFOLDERS = folder_qml

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH = src

symbian:TARGET.UID3 = 0xEB54CF20

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
# CONFIG += qt-components
VERSION = 0.0.1
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# The .cpp file which was generated for your project. Feel free to hack it.
HEADERS += \
    src/listmodel.h \
    src/chat.h \
    src/message.h \
    src/feed.h \
    src/temg.h

SOURCES += \
    src/main.cpp \
    src/listmodel.cpp \
    src/chat.cpp \
    src/message.cpp \
    src/feed.cpp \
    src/temg.cpp

INCLUDEPATH += telegram-qt

TEMPLATE = app
TARGET = temg
SUBDIRS = telegram-qt

include(options.pri)

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog


# QT: Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

# library telegram-qt
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/telegram-qt/release/ -lTelegramQt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/telegram-qt/debug/ -lTelegramQt
else:symbian: LIBS += -lTelegramQt
else:unix: LIBS += -L$$OUT_PWD/telegram-qt/ -lTelegramQt

INCLUDEPATH += $$PWD/telegram-qt
DEPENDPATH += $$PWD/telegram-qt


