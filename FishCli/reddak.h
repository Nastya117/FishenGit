#ifndef REDDAK_H
#define REDDAK_H

#include <QDialog>
#include <client.h>

namespace Ui {
class Reddak;
}

class Reddak : public QDialog
{
    Q_OBJECT

public:
    explicit Reddak(Client &vvv, QWidget *parent = 0);
    ~Reddak();

private:
    Ui::Reddak *ui;
    void addolf();
    void raz(QString message);
    Client &vvvv;
};

#endif // REDDAK_H
