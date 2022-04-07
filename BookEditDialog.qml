import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4

Dialog {
    id:dialogedit
    anchors.centerIn:parent
    visible: false
    title:"Dialog"
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
            enabled: title.text !== "" && data.text !== "" && annotation.text !== "" && authors.text !== "" && notes.text !==""

            onClicked:{
                bookController.editeBook(tableView.currentRow,title.text, data.text, annotation.text, authors.text, notes.text)
                dialogedit.close()
                title.text = ""
                data.text = ""
                annotation.text = ""
                authors.text = ""
                notes.text = ""
            }
        }

        Button{
            Layout.preferredWidth: 50
            Layout.alignment: Qt.AlignBottom | Qt.AlignRight
            text: "Cancel"
            onClicked:{
                dialogedit.close()
                title.txt = ""
                data.text = ""
                annotation.text = ""
                authors.text = ""
                notes.text = ""
            }
        }
    }

    contentItem:  Row{

        id:textBook

        spacing: 15

        Column{
            Text {

                text: qsTr("title")
            }
            TextField{

                id: title
                width:150
                height: 20

            }
        }


        Column{
            Text {

                text: qsTr("data")
            }

            TextField{

                id: data
                width:150
                height: 20

            }
        }


        Column{
            Text {

                text: qsTr("annotation")
            }

            TextField{

                id: annotation
                width:150
                height: 20

            }
        }

        Column{
            Text {

                text: qsTr("authers")
            }

            TextField{

                id: authors
                width:150
                height: 20

            }
        }

        Column{
            Text {

                text: qsTr("notes")
            }

            TextField{

                id: notes
                width:150
                height: 20

            }
        }

    }

}
