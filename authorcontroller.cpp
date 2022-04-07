#include "authorcontroller.h"

AuthorController::AuthorController(Authormodel *model,QObject *parent):
    model(model)
{

}

void AuthorController::addAuthor(QString fs,QString ls,int dt){

    Author ex = {fs,ls,dt};
    model->addAuthor(ex);


}

void AuthorController::deleteAuthor(int index){

    model->deleteAuthor(index);
}


void AuthorController::editAuthor(int index,QString fs,QString ls,int dt){

    Author ex = {fs,ls,dt};
    model->editAuthor(index,ex);

}
