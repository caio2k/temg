#ifndef ENUM_H
#define ENUM_H

enum AppState {
    AppStateNone,
    AppStateConnected,
    AppStateCodeRequired,
    AppStateCodeRequested,
    AppStateCodeSent,
    AppStateSignedIn,
    AppStateReady,
    AppStateLoggedOut,
    AppStateDisconnected
};

#endif // ENUM_H
