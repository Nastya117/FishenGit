#include "login.h"
#include "ui_login.h"
#include <QString>

Login::Login(class Client &clienter) :
    client(clienter),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Login::loglog);
    connect(&client, &Client::temere, this, &Login::okok);
}

Login::~Login()
{
    delete ui;
}

void Login::loglog()
{
    QString messia;
    messia = QString("Login\n%1\n%2").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text());
    client.sendTextMessage(messia);
}

void Login::okok(QString message)
{
    if (message == "Ok!")
    {
    lipko();
    close();
    }
    else ui->label_3->setText("ХУУУУУЙ!!!");
}
