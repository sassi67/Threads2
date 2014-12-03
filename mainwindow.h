#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    MyThread thread1;
    MyThread thread2;

private slots:
    void thread1_StartStop();
    void thread2_StartStop();



};

#endif // MAINWINDOW_H
