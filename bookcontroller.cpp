#include "bookcontroller.h"

BookController::BookController(BookModel *model,QObject *parent):
    model(model)
{

}

void BookController::addBook(QString ti,int dat,QString annot,QString auth,QString no ){
    Book ex = {ti,dat,annot,auth,no};
    model->addBook(ex);
}

void BookController::deleteBook(int index){

    model->deleteBook(index);
}


void BookController::editeBook(int index,QString ti,int dat,QString annot,QString auth,QString no){

    Book ex = {ti,dat,annot,auth,no};
    model->editeBook(index,ex);

}
