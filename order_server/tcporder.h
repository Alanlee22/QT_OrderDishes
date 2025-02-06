#ifndef TCPORDER_H
#define TCPORDER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class TcpOrder : public QThread
{
    Q_OBJECT
 public:
    explicit TcpOrder(QTcpSocket* tcp, QObject *parent = nullptr);

 protected:
    void run() override;

 signals:
    void trans_over(QVector<int> num_Dishes);

 private:
    QTcpSocket* m_tcp;
    QString data;
    QVector<int> num_Dishes;
};

#endif
