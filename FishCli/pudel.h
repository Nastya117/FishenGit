#ifndef PUDEL_H
#define PUDEL_H
#include <client.h>

#include <QWidget>

namespace Ui {
class Pudel;
}

class Pudel : public QWidget
{
    Q_OBJECT

public:
    explicit Pudel(Client &clienter);
    ~Pudel();

private:
    void kokok(QString mes);
    void ololo(QByteArray lol);
    void regreg();
    Client &client;
    Ui::Pudel *ui;
    void vibr(QString s);
    void sochi();
};

#endif // PUDEL_H
