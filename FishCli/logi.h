#ifndef LOGI_H
#define LOGI_H
#include <client.h>

#include <QDialog>

namespace Ui {
class Logi;
}

class Logi : public QDialog
{
    Q_OBJECT

public:
    explicit Logi(Client &clienter);
    ~Logi();

private:
    void cloosLe();
    Ui::Logi *ui;
    Client &client;
signals:
    void fong();
};

#endif // LOGI_H
