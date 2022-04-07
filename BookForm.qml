import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import BookModel 1.0

Rectangle {
    id:rect2
    color: '#B0C4DE'
    implicitWidth: 300
    implicitHeight: 200

    Row{
        id:buttonBook
        spacing: 15
        x:20
        y:50


        Button {
            id:addbook
            width:150
            height: 50
            text: "add book"
            style: ButtonStyle{
                background: Rectangle {
                    radius: 20
                    border.color: "black"
                    color: "#00FFFF"
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: control.pressed ? "#20B2AA" : "#708090" }
                        GradientStop { position: 1 ; color: control.pressed ? "#708090" : "#20B2AA" }
                    }
                }
            }
            onClicked: {
                dialogadd.open()
            }
        }
        Button {
            id:deletebook
            width:150
            height: 50
            text: "delete book"
            style: ButtonStyle{
                background: Rectangle {
                    radius: 20
                    border.color: "black"
                    color: "#00FFFF"
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: control.pressed ? "#20B2AA" : "#708090" }
                        GradientStop { position: 1 ; color: control.pressed ? "#708090" : "#20B2AA" }
                    }
                }
            }
            onClicked: {
                console.log(tableView.currentRow)
                dialogdelete.open()
            }
        }

        Button {
            id:editbook
            width:150
            height: 50
            text: "edite book"
            style: ButtonStyle{
                background: Rectangle {
                    radius: 20
                    border.color: "black"
                    color: "#00FFFF"
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: control.pressed ? "#20B2AA" : "#708090" }
                        GradientStop { position: 1 ; color: control.pressed ? "#708090" : "#20B2AA" }
                    }
                }
            }
            onClicked: {
                console.log(tableView.currentRow)
                dialogedit.open()
            }
        }

    }

    TableView {
        id: tableView
        anchors{
            margins: 20
            top: buttonBook.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right

        }

        model: bookmodel

        TableViewColumn {
            role: "title"
            title: "Title"
            width: 100
        }

        TableViewColumn {
            role: "data"
            title: "Data"
            width: 50
        }

        TableViewColumn {
            role: "annotation"
            title: "Annotation"
            width: 200
        }

        TableViewColumn {
            role: "authors"
            title: "Authors"
            width: 200
        }

        TableViewColumn {
            role: "notes"
            title: "Notes"
        }



    }
    BookAddDialog{
        id:dialogadd
    }
    BookDeleteDialog{
        id:dialogdelete
    }

    BookEditDialog{
        id:dialogedit
    }

}
