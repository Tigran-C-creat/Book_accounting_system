#include "bookmodel.h"
#include<QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

BookModel::BookModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    loadFromJson();
}



int BookModel::rowCount(const QModelIndex &parent) const
{
    return books.size();
}

int BookModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant BookModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Title)
        return QVariant(books.at(index.row()).title);

    if (role == Data)
        return QVariant(books.at(index.row()).data);

    if (role == Annotation)
        return QVariant(books.at(index.row()).annotation);

    if (role == Authors)
        return QVariant(books.at(index.row()).authors);

    if (role == Notes)
        return QVariant(books.at(index.row()).notes);

    else
        return QVariant();

}

bool BookModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        stringList.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags BookModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void BookModel::addBook(Book &new_book)
{
    beginResetModel();
    books.append(new_book);
    endResetModel();
    saveToJson();
}

void BookModel::deleteBook(int index){

    beginResetModel();
    books.removeAt(index);
    endResetModel();
    saveToJson();

}

void BookModel::editeBook(int index, Book &new_book){

    beginResetModel();
    books.replace(index,new_book);
    endResetModel();
    saveToJson();
}

void BookModel::saveToJson(){

    QJsonObject book = getJson();

    if(!QFile::exists("C:\\Users\\Tigran\\Desktop\\JSON.json" ))

    {
        QFile mFile("C:\\Users\\Tigran\\Desktop\\JSON.json");
        mFile.open(QIODevice::WriteOnly);
    }
    QFile mFile("C:\\Users\\Tigran\\Desktop\\JSON.json");
    mFile.open(QIODevice::WriteOnly);

    QJsonArray bookArray;
    for (const Book &jsonwrite : books) {
        QJsonObject bookObject;
        bookObject["title"] = jsonwrite.title;
        bookObject["data"] = jsonwrite.data;
        bookObject["annotation"] = jsonwrite.annotation;
        bookObject["authors"] = jsonwrite.authors;
        bookObject["notes"] = jsonwrite.notes;
        bookArray.append(bookObject);
    }

    book["book"] = bookArray;

    mFile.write(QJsonDocument(book).toJson());

    mFile.close();

}

void BookModel::loadFromJson()
{

    QJsonObject mainObject = getJson();

    QJsonArray bookArray = mainObject["book"].toArray() ;

    for (const QJsonValueRef &bookObject : bookArray) {
        Book book;
        book.title =  bookObject.toObject()["title"].toString();
        book.data =  bookObject.toObject()["data"].toInt();
        book.annotation =  bookObject.toObject()["annotation"].toString();
        book.authors =  bookObject.toObject()["authors"].toString();
        book.notes =  bookObject.toObject()["notes"].toString();

        books.append(book);
    }

}


QJsonObject BookModel::getJson()
{
    QFile loadFile( QStringLiteral("C:\\Users\\Tigran\\Desktop\\JSON.json") );

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        // return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc( QJsonDocument::fromJson(saveData));

    return loadDoc.object();
}












