import QtQuick 1.1
import com.nokia.meego 1.0

import Temg.Core 1.0

PageStackWindow {
  id: rootWin
  initialPage: mainPage
  showStatusBar: true
  showToolBar: true

  signal registerGetCode(string msg)
  signal registerSign(string msg, string code, string name, string surname)

  Component.onCompleted: {
      theme.inverted = !theme.inverted
      chatsList.currentIndex = -1
  }

  function showMessage(title, message) {
      messageDialog.titleText = title;
      messageDialog.message = message;
//      messageDialog.rejectButtonText = "logoff";
      messageDialog.open();
  }
  function gotoRegister(){
      pageStack.push(registerPage);
  }
  function requestRegisterGetCode(){
      //registerSignIn.enable = true;
      //registerCode.enable = true;
      registerGetCode(registerPhoneNumber.text)
  }
  function requestRegisterSign(){
      //registerSignIn.enable = true;
      //registerCode.enable = true;
      registerSign(registerPhoneNumber.text, registerCode.text, registerName.text, registerSurname.text)
  }


  Page{
    id: mainPage
    tools: mainTool

  TabGroup{
    id: mainTab
    currentTab: chatsTab
    Page {
      id: chatsTab
      ListView {
        id: chatsList
        delegate: chatsDelegate
        model: chatsModel
        anchors.fill: parent
        //verticalLayoutDirection: ListView.BottomToTop
        //onCurrentItemChanged: console.log(chatsList.currentItem + ' selected')
      }
    }

    Page {
      id: contactsTab
      Label {
        id: contactsTab1
        text: qsTr("This is a list of contacts")
        anchors.centerIn: parent
        platformStyle: LabelStyle {
          textColor: "white"
          fontFamily: "Arial"
          fontPixelSize: 30
        }
      }
    }
  }
  }

  Menu {
    id: mainMenu
    //visualParent: pageStack
    content: MenuLayout {
      //MenuItem {
      //  text: "Refresh"
      //  onClicked: rootWin.refresh();
      //}
      MenuItem {
        text: "Launch registration"
        onClicked: {
            rootWin.gotoRegister()
        }
      }
      MenuItem {
        text: "Privacy Policy"
        onClicked: rootWin.showMessage("Privacy Policy", "This application stores no information.");
      }
      MenuItem {
         text: "About"
        onClicked: rootWin.showMessage("temg - temeelegram", "Author: Caio Tsumura (caio2k@gmail.com)\n\nLicense: GPL 3.0 or later\n\nFeel free to follow me, @caio2k")
      }
    }
  }

  ToolBarLayout {
    id: mainTool
    visible: true

    ToolItem {
      objectName: statusIcon
      iconId: statusIcon.icon
    }
    ButtonRow {
      TabButton {
        id: galeryIcon;
        iconSource: "image://theme/icon-m-toolbar-new-chat-white";
        tab: chatsTab
      }
      TabButton {
        id: cameraIcon;
        iconSource: "image://theme/icon-m-toolbar-addressbook-white";
        tab: contactsTab
      }
    }
    ToolItem {
      id: menuIcon
      iconId: "icon-m-toolbar-view-menu-white";
      onClicked: mainMenu.open()
    }
  }

  QueryDialog {
      id: messageDialog;
      acceptButtonText: "Ok"
  }

  Component{
      id:chatsDelegate
      Item {
          width: parent.width
          height: 120
          Text {
              id: nameField
              width: parent.width
              color: "lightblue"
              font.pixelSize: 50
              font.bold: true
              text: model.name
          }
          Text {
              id: lastField
              anchors.top: nameField.bottom
              width: parent.width
              color: "lightgray"
              font.pixelSize: 40
              text: model.lastMessage
          }
          MouseArea{
              id: chatMouseArea
              anchors.fill: parent
              onClicked: {
                  messagesModel.clear();
//                console.log("msgs "+ model.message);
                  for (var i = 0; i < model.count ; i++)
                  {
                      messagesModel.append({"peer": model.peer[i], "content": model.text[i] });
                  }
                  pageStack.push(chatPage);
              }
          }
      }
  }

  Page{
    id: registerPage
    tools: registerTool
    Column {
        id: registerColumn
        spacing: 5
        width: parent.width

        TextField {
            id: registerPhoneNumber
            placeholderText: "Phone number without +"
            width: 400
            inputMethodHints: Qt.ImhDigitsOnly
        }
        Button {
            id: registerCodeButton
            text: "Get Registration Code"
            onClicked: rootWin.requestRegisterGetCode()
        }
        TextField {
            id: registerName
            //enabled: false
            placeholderText: "your name"
            width: 300
        }
        TextField {
            id: registerSurname
            //enabled: false
            placeholderText: "your last name"
            width: 300
        }
        TextField {
            id: registerCode
            //enabled: false
            placeholderText: "received code"
            width: 200
            inputMethodHints: Qt.ImhDigitsOnly
        }
        Button {
            id: registerSignUpButton
            //enabled: false
            text: "Insert Registration Code"
            onClicked: rootWin.requestRegisterSign()
        }
    }
  }

  ToolBarLayout {
    id: registerTool
    visible: false

    ToolItem {
       id: backIcon
       iconId: "icon-m-toolbar-back-white";
       onClicked: {
         pageStack.pop();
       }
    }
  }

  Page {
    id: chatPage
    //property variant chat
    tools: messagesTool
    ListView {
      id: messagesList
      delegate: messagesDelegate
      model: messagesModel
      anchors.fill: parent
    }
  }
  ListModel {
      id: messagesModel
      ListElement{
          peer: "fulano"
          content: "oi mundo"
      }
      ListElement{
          peer: "fulano2"
          content: "oi mundo2"
      }
  }
  Component{
      id:messagesDelegate
      Item {
          width: parent.width
          height: 50
          Text {
              width: parent.width
              text:  model.peer + ">> " + model.content
              color: "lightgray"
              font.pixelSize: 40
          }
          MouseArea{
              id: chatMouseArea
              anchors.fill: parent
          }
      }
  }

  ToolBarLayout {
    id: messagesTool
    visible: false

    ToolItem {
       id: messagesBackIcon
       iconId: "icon-m-toolbar-back-white";
       onClicked: {
           pageStack.pop();
       }
    }
  }
}
