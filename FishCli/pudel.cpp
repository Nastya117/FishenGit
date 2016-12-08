#include "pudel.h"
#include "ui_pudel.h"
#include <QString>
#include <QImage>
#include <QDataStream>
#include <reddak.h>

Pudel::Pudel(class Client &clienter) :
    client(clienter),
    ui(new Ui::Pudel)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Pudel::regreg);
    connect(&client, &Client::temere, this, &Pudel::kokok);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &Pudel::vibr);
    connect(&client, &Client::roll, this, &Pudel::ololo);
    connect(ui->pushButton, &QPushButton::clicked, this, &Pudel::sochi);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Pudel::redok);
}

Pudel::~Pudel()
{
    delete ui;
}

void Pudel::kokok(QString mes)
{
    if (mes == "Zaregalis") ui->label_5->setText("OK");
    else ui->label_5->setText("FAIL");
}

void Pudel::ololo(QByteArray lol)
{
    QDataStream kill(lol);
    kill.setVersion(QDataStream::Qt_5_6);
    QString kk;
    kill >> kk;
    qDebug() << kk;
    if (kk == "Lovikor")
    {
        QString m0, m1;
        QList<QImage> klop;
        kill >> klop;
        QStringList yy;

        kill >> yy;
        m0 = yy[0];
        m1 = yy[1];
        yy.pop_front();
        yy.pop_front();
        ui->listWidget->clear();
        for (int i = 0; i < klop.size(); ++i)
        {
            QIcon kit(QPixmap::fromImage(klop[i]));
            QListWidgetItem *lok = new QListWidgetItem(kit, yy[i]);
            lok->setData(Qt::UserRole + 1, m0);
            lok->setData(Qt::UserRole + 2, m1);
            ui->listWidget->addItem(lok);
        }
    }
}

void Pudel::regreg()
{
    QString ss = QString("Reg\n%1\n%2").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text());
    client.sendTextMessage(ss);
}

void Pudel::vibr(QString s)
{
}

void Pudel::sochi()
{
    QStringList lopa;
    lopa.append("sochi");
    lopa.append(ui->lineEdit_3->text());
    for (int i = 0; i < ui->listWidget_2->count(); ++i)
    {
        QString kola = ui->listWidget_2->item(i)->data(Qt::UserRole + 1).toString() + "/"
        + ui->listWidget_2->item(i)->data(Qt::UserRole + 2).toString()
        + "/" + ui->listWidget_2->item(i)->text();
        lopa.append(kola);
    }
    QString kk = lopa.join("\n");
    client.sendTextMessage(kk);
    ui->listWidget_2->clear();
}

void Pudel::redok()
{
    Reddak kot(client, this);
    kot.exec();
}
