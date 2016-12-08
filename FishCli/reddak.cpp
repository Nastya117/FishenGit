#include "reddak.h"
#include "ui_reddak.h"
#include <QTextStream>
#include <QFileDialog>
#include <QImage>
#include <QFileInfo>

Reddak::Reddak(Client &vvv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reddak),
    vvvv(vvv)
{
    ui->setupUi(this);
    vvvv.sendTextMessage("inired");
    connect(ui->pushButton, &QPushButton::clicked, this, &Reddak::addolf);
    connect(&vvvv, &Client::temere, this, &Reddak::raz);
}

Reddak::~Reddak()
{
    delete ui;
}

void Reddak::addolf()
{
    if (!ui->treeWidget->currentItem())
    {
        QStringList goo = {ui->lineEdit->text()};
        QTreeWidgetItem* kod = new QTreeWidgetItem (goo);
        ui->treeWidget->addTopLevelItem(kod);
        vvvv.sendTextMessage("addolf\n" + ui->lineEdit->text());
    }
    else
        if (ui->treeWidget->currentItem()->parent() == nullptr)
    {
        QTreeWidgetItem* pod = ui->treeWidget->currentItem();
        QStringList goo = {ui->lineEdit->text()};
        QTreeWidgetItem* kod = new QTreeWidgetItem (goo);
        pod->addChild(kod);
        vvvv.sendTextMessage("podaddolf\n" + ui->lineEdit->text() + "\n" + pod->text(0));
    }
    else
        {
            QString ss = QFileDialog::getOpenFileName();
            QImage kol(ss);
            QFileInfo klo(ss);
            QByteArray liktor;
            QDataStream kilka(&liktor, QFile::WriteOnly);
            kilka.setVersion(QDataStream::Qt_5_6);
            QString jj = klo.baseName();
            for (int kk = 0; kk < klo.baseName().size(); ++kk)
                if (jj[kk] == ' ') jj[kk] = '_';

            QTreeWidgetItem* kod = new QTreeWidgetItem ({jj});
            ui->treeWidget->currentItem()->addChild(kod);

            kilka << QString("Lovikor") << ui->treeWidget->currentItem()->parent()->text(0) << ui->treeWidget->currentItem()->text(0) << jj << kol;
            vvvv.sendBinaryMessage(liktor);

        }
}

void Reddak::raz(QString message)
{
    QTextStream joke(&message);
    QString s;
    joke >> s;
    if (s == "dirs")
    {
        int k;
        joke >> k;
        for (int i = 0; i < k; ++i)
        {
            joke >> s;
            QStringList goo = {s};
            QTreeWidgetItem* kod = new QTreeWidgetItem (goo);
            ui->treeWidget->addTopLevelItem(kod);
            int l;
            joke >> l;
            for (int j = 0; j < l; ++j)
            {
                joke >> s;
                QStringList goo1 = {s};
                QTreeWidgetItem* kod1 = new QTreeWidgetItem (goo1);
                kod->addChild(kod1);
                int t;
                joke >> t;
                for (int f = 0; f < t; ++f)
                {
                    joke >> s;
                    QStringList goo2 = {s};
                    QTreeWidgetItem* kod2 = new QTreeWidgetItem (goo2);
                    kod1->addChild(kod2);
                }
            }
        }
    }
}
