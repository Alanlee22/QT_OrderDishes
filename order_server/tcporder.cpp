#include "tcporder.h"
#include <QStringList>
#include <QVector>

TcpOrder::TcpOrder(QTcpSocket* tcp, QObject *parent) : QThread(parent)
{
    m_tcp = tcp;
}

void TcpOrder::run()
{
    qDebug()<<"服务器子线程"<< QThread::currentThread();
    connect(m_tcp, &QTcpSocket::readyRead, this, [=](){
        data = m_tcp->readAll();
    QStringList numbers = data.split(",");
        for (const QString &numStr : numbers) {
            bool ok;
            int num = numStr.toInt(&ok);
            if (ok){
                num_Dishes.append(num);
            }
        }
        emit trans_over(num_Dishes);


        num_Dishes.clear();
    });

    exec();
}
