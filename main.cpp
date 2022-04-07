#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "authormodel.h"
#include "authorcontroller.h"
#include <QQmlContext>
#include "bookmodel.h"
#include "bookcontroller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType <Authormodel>("Authormodel",1,0,"Authormodel");
    Authormodel am;
    engine.rootContext()->setContextProperty("authormodel", &am);

    qmlRegisterType <AuthorController>("AuthorController",1,0,"AuthorController");
    AuthorController ac (&am);
    engine.rootContext()->setContextProperty("authorController", &ac);

    qmlRegisterType <BookModel>("BookModel",1,0,"BookModel");
    BookModel bm;
    engine.rootContext()->setContextProperty("bookmodel", &bm);

    qmlRegisterType <BookController>("BookController",1,0,"BookController");
    BookController bc (&bm);
    engine.rootContext()->setContextProperty("bookController", &bc);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
