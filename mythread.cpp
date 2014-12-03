#include "mythread.h"
#include <QDebug>
#include <QMutexLocker>

MyThread::MyThread(QObject *parent) :
    QThread(parent),
    m_Stopped(false)
{
}

void MyThread::setMessage(const QString& msg)
{
    m_Msg = msg;
}

void MyThread::stop()
{
//    m_Mutex.lock();
//    m_Stopped = true;
//    m_Mutex.unlock();
    QMutexLocker locker(&m_Mutex);
    m_Stopped = true;
}

void MyThread::run()
{
    while(true)
    {
//       m_Mutex.lock();
//       if (m_Stopped)
//       {
//            m_Stopped = false;
//            m_Mutex.unlock();
//            break;
//       }
//       m_Mutex.unlock();
        { // important!!
            QMutexLocker locker(&m_Mutex);
            if (m_Stopped)
            {
                m_Stopped = false;
                break;
            }
        }
        qDebug() << qPrintable(m_Msg);
        sleep(1);
    }
}
