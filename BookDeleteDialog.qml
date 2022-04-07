import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4


Dialog {
    id:dialogdelete
    anchors.centerIn:parent
    visible: false
    title:"Are you sure you want <br> to remove this item ?"
    modal: true

    footer:RowLayout{

        height: parent.height
        width: parent.width
        spacing: 0

        Item {
            Layout.fillWidth: true
        }

        Button{
            Layout.preferredWidth: 50
            Layout.alignment: Qt.AlignBottom | Qt.AlignRight
            text: "OK"
            onClicked:{
                bookController.deleteBook(tableView.currentRow)
                dialogdelete.close()

            }
        }

        Button{
            Layout.preferredWidth: 50
            Layout.alignment: Qt.AlignBottom | Qt.AlignRight
            text: "Cancel"
            onClicked:{
                dialogdelete.close()
            }
        }
    }

}
