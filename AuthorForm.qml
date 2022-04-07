import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import Authormodel 1.0

Rectangle {
    id: rect
    color: '#B0C4DE'
    implicitWidth: 200
    implicitHeight: 200

    Row{
        id: buttonAuthor
        spacing: 15
        x:20
        y:50
        Button {
            id: add
            width:150
            height: 50
            text: "add author"
            style: ButtonStyle{
                background: Rectangle {
                    radius: 20
                    border.color: "black"
                    color: "#00FFFF"
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: control.pressed ? "#1E90FF" : "#00FFFF" }
                        GradientStop { position: 1 ; color: control.pressed ? "#00FFFF" : "#1E90FF" }
                    }
                }
            }
            onClicked:{
                dialogAdd.open()

            }
        }

        Button {
            width:150
            height: 50
            text: "delete author"
            style: ButtonStyle{
                background: Rectangle {
                    radius: 20
                    border.color: "black"
                    color: "#00FFFF"
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: control.pressed ? "#1E90FF" : "#00FFFF" }
                        GradientStop { position: 1 ; color: control.pressed ? "#00FFFF" : "#1E90FF" }
                    }
                }
            }
            onClicked: {

                console.log(tableView.currentRow)
                dialogDelete.open()
            }
        }

        Button {
            width:150
            height: 50
            text: "edit author"
            style: ButtonStyle{
                background: Rectangle {
                    radius: 20
                    border.color: "black"
                    color: "#00FFFF"
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: control.pressed ? "#1E90FF" : "#00FFFF" }
                        GradientStop { position: 1 ; color: control.pressed ? "#00FFFF" : "#1E90FF" }
                    }
                }
            }
            onClicked: {
                console.log(tableView.currentRow)
                dialogEdit.open()

            }
        }

    }

    TableView {
        id: tableView
        anchors{
            margins: 20
            top: buttonAuthor.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        model:authormodel

        TableViewColumn {
            role: "firstName"
            title: "FirstName"
            width: 250
        }
        TableViewColumn {
            role: "lastname"
            title: "Lastname"
            width: 350
        }

        TableViewColumn {
            role: "data"
            title: "Data"
        }

    }



    AuthorAddDialog {
        id: dialogAdd
    }

    AuthorDeleteDialog {
        id: dialogDelete
    }

    AuthorEditDialog{
        id: dialogEdit

    }
}




