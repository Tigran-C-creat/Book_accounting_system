import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.1
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4
import Authormodel 1.0

Window {
    id: mainWindow

    title: qsTr("library")
    minimumWidth: 850
    minimumHeight: 500
    visible: true

    StackLayout {
        id: layout
        anchors.fill: parent
        currentIndex: bar.currentIndex

        AuthorForm{
            id: authorform
        }

        BookForm{
            id: bookform
        }
    }

    TabBar {
        id: bar
        width: parent.width

        TabButton {
            text: qsTr("Authors")
        }
        TabButton {
            text: qsTr("Books")
        }

    }

}



