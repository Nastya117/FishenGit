#include "serv.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>
#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QImage>
#include <iostream>


serv::serv(quint16 port, bool debug, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
                                            QWebSocketServer::NonSecureMode, this)),
    m_clients(),
    m_debug(debug)
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
        if (m_debug)
            qDebug() << "serv listening on port" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &serv::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &serv::closed);
    }
}

serv::~serv()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void serv::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &serv::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &serv::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &serv::socketDisconnected);

    m_clients << pSocket;
}

void serv::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Message received:" << message;
    if (pClient) {
        QStringList msgs = message.split("\n");
        if (msgs[0] == "Login")
        {
            if ((msgs[1] == "root") && (msgs[2] == "[eqnfvgkfdfk"))
            {pClient->sendTextMessage("Ok!"); return;}
            else
            {
                QString fish = QDir::homePath() + "/Gits/" + msgs[1];
                QFile fil(fish);
                if (fil.open(QFile::ReadOnly | QFile::Text))
                {
                    if (fil.readAll() == msgs[2])
                    {pClient->sendTextMessage("Ok!"); return;}
                }
            }
            pClient->sendTextMessage("No");
        }
        else
            if (msgs[0] == "Reg")
            {
                QString fish = QDir::homePath() + "/Gits/" + msgs[1];
                QFile fil(fish);
                fil.open(QFile::WriteOnly | QFile::Text);
                fil.write(msgs[2].toUtf8());
                pClient->sendTextMessage("Zaregalis");
            }
        else
                if (msgs[0] == "imgdie")
                {
                    QString fish = QDir::homePath() + "/img/" + msgs[1] + "/" + msgs[2];
                    qDebug() << fish;
                    QDir hh(fish);
                    QList<QImage> kol;
                    QStringList yy = hh.entryList({"*.jpg"});

                    for (int i = 0; i <yy.size(); ++i)
                    {
                    kol.append(QImage(fish + "/" + yy[i]));
                    yy[i] = yy[i].left(yy[i].size() - 4);
                    }
                    QByteArray liktor;
                    QDataStream kilka(&liktor, QFile::WriteOnly);
                    kilka.setVersion(QDataStream::Qt_5_6);
                    yy.prepend(msgs[2]);
                    yy.prepend(msgs[1]);
                    kilka << QString("Lovikor") << kol << yy;
                    pClient->sendBinaryMessage(liktor);
                }
        else
                if (msgs[0] == "sochi")
                {
                    for (int i = 2; i < msgs.size(); ++i)
                    {
                        QString fish = QDir::homePath() + "/img/" + msgs[i] + ".txt";
                        QFile hh(fish);
                        hh.open(QFile::WriteOnly | QFile::Text);
                        hh.write(msgs[1].toUtf8());
                        hh.write("\n");
                    }
                }
    }
}

void serv::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}

void serv::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
