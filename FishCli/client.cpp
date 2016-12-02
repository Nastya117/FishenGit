#include "client.h"
#include <QDebug>


Client::Client(const QUrl &url, bool debug, QObject *parent) :
    QObject(parent),
    m_url(url),
    m_debug(debug)
{
    if (m_debug)
        qDebug() << "WebSocket server:" << url;
    connect(&m_webSocket, &QWebSocket::connected, this, &Client::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &Client::closed);
    m_webSocket.open(QUrl(url));
}

void Client::onConnected()
{
    if (m_debug)
        qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &Client::onTextMessageReceived);

    connect(&m_webSocket, &QWebSocket::binaryMessageReceived,
                this, &Client::onBinaryMessageReceived);

    m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void Client::sendTextMessage(QString message)
{
    m_webSocket.sendTextMessage(message);
}

void Client::onTextMessageReceived(QString message)
{
    if (m_debug)
        qDebug() << "Message received:" << message;
    temere(message);
}

void Client::onBinaryMessageReceived(QByteArray message)
{
    roll(message);
}
