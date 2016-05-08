import QtQuick 1.1
import com.nokia.meego 1.0

import Temg.Core 1.0

PageStackWindow {
  id: rootWin
  initialPage: mainPage
  showStatusBar: true
  showToolBar: true

  Component.onCompleted: {
      theme.inverted = !theme.inverted
      console.log("The chart has been cleared ",statusIcon.icon)
  }

  function showMessage(title, message) {
      messageDialog.titleText = title;
      messageDialog.message = message;
      messageDialog.open();
  }
  function addChat(chat){
//      var component = Qt.createComponent(Chat);
//      var dynamicObject = component.createObject(parent);
//      chatsModel.append({"name": chat.name, "messages": [{"sender": chat.name, "content": chat.messages}]})
    chatsModel.appendRow(chat)
////      chatsModel.append({"name": chat.name, "messages": chat.messages})
      //newMessage = new Message(chat.name, chat.message);
      //newChat = new Chat();
      //chatsModel.append(newChat);
  }
  //Component.onChangeStatusIcon: {console.log("The chart has been cleared")}

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
//        anchors.centerIn: parent
//        width:parent.width
//        height:parent.height-wa_notifier.height
//        spacing: 1
//        clip:true
//        cacheBuffer: 10000
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
      MenuItem {
        text: "Refresh"
        //onClicked: rootWin.refresh();
      }
      MenuItem {
        text: "About"
        onClicked: rootWin.showMessage("temg - temeelegram", "Author: Caio Tsumura (caio2k@gmail.com)\n\nLicense: GPL 3.0 or later\n\nFeel free to follow me, @caio2k")
      }
      MenuItem {
        text: "Privacy Policy"
        onClicked: rootWin.showMessage("Privacy Policy", "This application stores no information.");
      }
      MenuItem {
        text: "Add mock message"
        onClicked: {
            rootWin.addChat(teste1)
        }
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
      acceptButtonText: "Ok";
  }

  ListModel{
      id: chatsModelOld
      //chatName: Chat.getName
      ListElement{
          name: "teste"
          messages: [ ListElement{sender: "test"; content: "bla"} ]
      }
  }

  Component{
      id:chatsDelegate
      Item {
          width: parent.width
          height: 100
          Text {
              id: nameField
              width: parent.width
              color: "lightblue"
              font.bold: true
              text: name
          }
          Text {
              id: lastField
              anchors.top: nameField.bottom
              width: parent.width
              color: "lightgray"
              text: lastMessage
          }
          /*Row {
              anchors.top: lastField.bottom
              Repeater {
                  model: messages
                  Text {
                      width:parent.width
                      text:  sender + ">" + content
                  }
              }
          }*/
      }
  }

  Chat{
      id: teste1
      name: "chat1"
      messages: [
          Message { sender: "testador1"; destiny: "you1"; content: "bla1"},
          Message { sender: "testador2"; destiny: "you2"; content: "bla2"},
          Message { sender: "testador3"; destiny: "you3"; content: "bla3"}
      ]
  }
}
