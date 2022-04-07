#ifndef AUTHORMODEL_H
#define AUTHORMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include<QJsonObject>
#include"author.h"

class Authormodel : public QAbstractTableModel
{
    Q_OBJECT

public:

    QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles {
            {  FirstName, "firstName" },
            {  Lastname, "lastname" },
            {  Data, "data"}
        };
        return roles;
    }



    explicit Authormodel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;


    enum AuthorRole {
        FirstName,
        Lastname,
        Data
    };

    void addAuthor(Author &new_auther);
    void deleteAuthor(int index);
    void editAuthor(int index,Author &new_auther);

    void saveToJson();
    void loadFromJson();
    QJsonObject getJson();



private:
    QStringList stringList;

    QList<Author> authors;

};

#endif // AUTHORMODEL_H
