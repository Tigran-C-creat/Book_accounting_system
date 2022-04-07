#ifndef AUTHORCONTROLLER_H
#define AUTHORCONTROLLER_H

#include<QObject>
#include"authormodel.h"


class AuthorController: public QObject
{

    Q_OBJECT



public:
    explicit AuthorController(Authormodel *model,QObject *parent = nullptr);

    AuthorController(){}

    Q_INVOKABLE void addAuthor(QString fs,QString ls,int dt);
    Q_INVOKABLE void deleteAuthor(int index);
    Q_INVOKABLE void editAuthor(int index,QString fs,QString ls,int dt);



    Authormodel *model;

};

#endif // AUTHORCONTROLLER_H
