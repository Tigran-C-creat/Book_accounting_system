#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include"book.h"
#include<QJsonObject>

class BookModel : public QAbstractTableModel
{
    Q_OBJECT

    QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles {
            {  Title, "title" },
            {  Data, "data" },
            {  Annotation, "annotation"},
            {  Authors,"authors"},
            {  Notes,"notes"}
        };
        return roles;
    }

public:
    explicit BookModel(QObject *parent = nullptr);



    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    enum BookRole{
        Title,
        Data,
        Annotation,
        Authors,
        Notes,
    };

    void addBook(Book &new_book);
    void deleteBook(int index);
    void editeBook(int index,Book &new_auther);

    void saveToJson();
    void loadFromJson();
    QJsonObject getJson();





private:

    QStringList stringList;
    QList<Book> books;
};

#endif // BOOKMODEL_H
