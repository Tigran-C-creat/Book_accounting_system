#include "authormodel.h"
#include<QFile>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

Authormodel::Authormodel(QObject *parent)
    : QAbstractTableModel(parent)
{
  loadFromJson();
}

int Authormodel::rowCount(const QModelIndex &parent) const
{

    return authors.size();
}

int Authormodel::columnCount(const QModelIndex &parent) const
{

    return 3;

}


QVariant Authormodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == FirstName)
        return QVariant(authors.at(index.row()).firstName);

    if (role == Lastname)
        return QVariant(authors.at(index.row()).lastName);

    if (role == Data)
        return QVariant(authors.at(index.row()).data);


    else
        return QVariant();

}

bool Authormodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        stringList.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags Authormodel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void Authormodel::addAuthor(Author &new_auther)
{
    beginResetModel();
    authors.append(new_auther);
    endResetModel();
    saveToJson();
}


void Authormodel::deleteAuthor(int index){

    beginResetModel();
    authors.removeAt(index);
    endResetModel();
    saveToJson();

}

void Authormodel::editAuthor(int index, Author &new_auther){

    beginResetModel();
    authors.replace(index,new_auther);
    endResetModel();
    saveToJson();
}

void Authormodel::saveToJson()
{

    QJsonObject author = getJson();

    if(!QFile::exists("C:\\Users\\Tigran\\Desktop\\JSON.json" ))

    {
        QFile mFile("C:\\Users\\Tigran\\Desktop\\JSON.json");
        mFile.open(QIODevice::WriteOnly);
    }
    QFile mFile("C:\\Users\\Tigran\\Desktop\\JSON.json");
    mFile.open(QIODevice::WriteOnly);

    QJsonArray authorArray;
    for (const Author &jsonwrite : authors) {
        QJsonObject authorObject;
        authorObject["firstName"] = jsonwrite.firstName;
        authorObject["lastName"] = jsonwrite.lastName;
        authorObject["data"] = jsonwrite.data;
        authorArray.append(authorObject);
    }

    author["author"] = authorArray;

    mFile.write(QJsonDocument(author).toJson());

    mFile.close();

}


void Authormodel::loadFromJson(){

    QJsonObject mainObject = getJson();

    QJsonArray authorArray = mainObject["author"].toArray();
    qDebug()<<authorArray.count();
    for (const QJsonValueRef &authorObject : authorArray){
        Author author;
        author.firstName = authorObject.toObject()["firstName"].toString();
        author.lastName = authorObject.toObject()["lastName"].toString();
        author.data = authorObject.toObject()["data"].toInt();

        authors.append(author);

    }

}

QJsonObject Authormodel::getJson(){

    QFile loadFile(QStringLiteral ("C:\\Users\\Tigran\\Desktop\\JSON.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
    }
    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc( QJsonDocument::fromJson(saveData));

    return loadDoc.object();

}














