#include <QApplication>
#include "client.h"
#include <QDebug>
#include <logi.h>
#include <login.h>
#include <pudel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client client(QUrl(QStringLiteral("ws://localhost:1170")));
    qDebug() << "\\__|-|__/";
    Logi log(client);
    log.show();
    Login loging(client);
    Pudel pu(client);
    QObject::connect(&log, &Logi::fong, &loging, &Login::show);

    QObject::connect(&loging, &Login::lipko, &pu, &Pudel::show);

    return a.exec();
}
