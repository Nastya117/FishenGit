#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include "serv.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int port = 1170;

    serv *server = new serv(port);
    QObject::connect(server, &serv::closed, &a, &QCoreApplication::quit);
    qDebug() << "Hello, word!";
    return a.exec();
}
