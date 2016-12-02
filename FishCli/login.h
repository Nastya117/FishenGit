#ifndef LOGIN_H
#define LOGIN_H
#include <client.h>

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(Client &clienter);
    ~Login();

private:
    Client &client;
    Ui::Login *ui;
    void loglog();
    void okok(QString message);
signals:
    void lipko();
};

#endif // LOGIN_H
