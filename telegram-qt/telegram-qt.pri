
QT += core network

#TEMPLATE = lib
#TARGET   = TelegramQt
#VERSION = 0.1.0

contains(options, static-lib) {
    CONFIG  += staticlib
} else {
    CONFIG  += dll
}

CONFIG += c++11

DEFINES += TELEGRAMQT_LIBRARY

SOURCES += $$PWD/CTelegramCore.cpp \
    $$PWD/CAppInformation.cpp \
    $$PWD/CTelegramDispatcher.cpp \
    $$PWD/CRawStream.cpp \
    $$PWD/CTelegramStream.cpp \
    $$PWD/Utils.cpp \
    $$PWD/TelegramUtils.cpp \
    $$PWD/CTcpTransport.cpp \
    $$PWD/TelegramNamespace.cpp \
    $$PWD/CTelegramConnection.cpp \
    $$PWD/TLValues.cpp

HEADERS += $$PWD/CTelegramCore.hpp \
    $$PWD/CAppInformation.hpp \
    $$PWD/CTelegramDispatcher.hpp \
    $$PWD/CTelegramStream.hpp \
    $$PWD/CRawStream.hpp \
    $$PWD/Utils.hpp \
    $$PWD/TelegramUtils.hpp \
    $$PWD/CTelegramTransport.hpp \
    $$PWD/CTcpTransport.hpp \
    $$PWD/TLTypes.hpp \
    $$PWD/TLNumbers.hpp \
    $$PWD/crypto-aes.hpp \
    $$PWD/crypto-rsa.hpp \
    $$PWD/CTelegramConnection.hpp \
    $$PWD/TelegramNamespace.hpp \
    $$PWD/TelegramNamespace_p.hpp \
    $$PWD/telegramqt_export.h \
    $$PWD/TLValues.hpp
INCLUDEPATH += $$PWD

contains(options, developer-build) {
    SOURCES += TLTypesDebug.cpp
    HEADERS += TLTypesDebug.hpp
    DEFINES += DEVELOPER_BUILD
}

OTHER_FILES += CMakeLists.txt

LIBS += -lssl -lcrypto
LIBS += -lz

contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/telegram-qt/lib
    INSTALLS += target
}
