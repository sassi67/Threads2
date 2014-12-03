#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread1.setMessage("Msg1");
    thread2.setMessage("Msg2");

    connect(ui->btnThread1, SIGNAL(clicked()),
            this, SLOT(thread1_StartStop()));
    connect(ui->btnThread2, SIGNAL(clicked()),
            this, SLOT(thread2_StartStop()));
}

MainWindow::~MainWindow()
{
    thread1.stop();
    thread2.stop();

    thread1.wait();
    thread2.wait();

    delete ui;
}

void MainWindow::thread1_StartStop()
{
    if (thread1.isRunning())
    {
        thread1.stop();
        ui->btnThread1->setText("Start 1");
    }
    else
    {
        thread1.start();
        ui->btnThread1->setText("Stop 1");
    }
}

void MainWindow::thread2_StartStop()
{
    if (thread2.isRunning())
    {
        thread2.stop();
        ui->btnThread2->setText("Start 2");
    }
    else
    {
        thread2.start();
        ui->btnThread2->setText("Stop 2");
    }
}

