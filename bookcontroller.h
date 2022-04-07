#ifndef BOOKCONTROLLER_H
#define BOOKCONTROLLER_H

#include<QObject>
#include"bookmodel.h"

class BookController:public QObject
{
    Q_OBJECT

public:
    explicit BookController(BookModel *model,QObject *parent = nullptr);

    BookController(){}

    Q_INVOKABLE void addBook(QString ti,int dat,QString annot,QString auth,QString no );
    Q_INVOKABLE void deleteBook(int index);
    Q_INVOKABLE void editeBook(int index,QString ti,int dat,QString annot,QString auth,QString no);

    BookModel *model;

};

#endif // BOOKCONTROLLER_H
