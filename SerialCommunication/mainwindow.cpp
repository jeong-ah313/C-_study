#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qserialport.h>
#include <qserialportinfo.h>
#include <stdio.h>

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        ui->lcd_temp->setPalette(Qt::red);
        serial = new QSerialPort(this);
        connect(ui->rescan_Button, SIGNAL(clicked()), this, SLOT(serial_rescan()));
        connect(ui->connect_button, SIGNAL(clicked()), this, SLOT (serial_connect()));
        connect(ui->slider1, SIGNAL(valueChanged(int)), this, SLOT(widget_changed()));
        connect(ui->slider2, SIGNAL(valueChanged(int)), this, SLOT(widget_changed()));
        connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(widget_changed()));
        connect(serial, SIGNAL(readyRead()), this, SLOT(serial_received()));
        serial_rescan();
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

void MainWindow::serial_connect()
{
        serial->setPortName(ui->port_box->currentText());
        serial->setBaudRate(QSerialPort::Baud115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
//        serial->write("Hello World!\n");

        if(!serial->open(QIODevice::ReadWrite)){
            qDebug() << "Serial port open error";
        }
}

void MainWindow::serial_rescan()
{
    ui->port_box->clear();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        ui->port_box->addItem(serialPortInfo.portName());
    }
}

void MainWindow::widget_changed()
{
    QString buffer;
    buffer.sprintf("A%03i;%03i;%03i\n",ui->slider1->value(),ui->slider2->value(),ui->dial->value());
    qDebug() << buffer;
    serial->write( buffer.toStdString().c_str(), buffer.size());
    serial->QSerialPort::waitForBytesWritten(-1);
    ui->lcd_led1->display(ui->slider1->value());
    ui->lcd_led2->display(ui->slider2->value());
    ui->lcd_pwm->display(ui->dial->value());
}

void MainWindow::send_test()
{
    serial->write("test!\n");
}


void MainWindow::serial_received()
{
//    usleep(10000);
//    QString received = serial->readAll();
    QString received;
    while (serial->canReadLine()){
        received = serial->readLine();  //reads in data line by line, separated by \n or \r characters
    }

    QStringList splitted = received.split(";");
    if (splitted.value(0) == "A"){
        ui->lcd_temp->display(splitted.value(1));
    }
}
