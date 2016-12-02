#ifndef client_H
#define client_H

#include <QObject>
#include <QtWebSockets/QWebSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QUrl &url, bool debug = true, QObject *parent = Q_NULLPTR);

    void sendTextMessage(QString message);
    void onBinaryMessageReceived(QByteArray message);
Q_SIGNALS:
    void closed();
    void temere(QString mess);
    void roll(QByteArray lol);

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
};

#endif // client_H
