import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4

Dialog {
    id:dialogAdd
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
            enabled: firstname.text !== "" && lastname.text !== "" && data.text !== ""

            onClicked:{
                authorController.addAuthor(firstname.text,lastname.text,data.text)
                dialogAdd.close()
                firstname.text = ""
                lastname.text = ""
                data.text = ""

            }
        }

        Button{
            Layout.preferredWidth: 50
            Layout.alignment: Qt.AlignBottom | Qt.AlignRight
            text: "Cancel"
            onClicked:{
                dialogAdd.close()
                firstname.text = ""
                lastname.text = ""
                data.text = ""
            }
        }
    }

    contentItem:  Row{

        id:textAuthor

        spacing: 15

        Column{
            Text {

                text: qsTr("firstname")
            }
            TextField{

                id: firstname
                width:150
                height: 20

            }
        }

        Column{
            Text {

                text: qsTr("lastname")
            }

            TextField{

                id: lastname
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

    }

}
