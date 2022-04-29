#ifndef CCSERIAL_H
#define CCSERIAL_H

#include <QDialog>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kalman.h"

namespace Ui {
class CCserial;
}

class CCserial : public QDialog
{
    Q_OBJECT

public:
    explicit CCserial(QWidget *parent = 0);
    ~CCserial();


private slots:
    void on_clearButton_clicked();
    void on_sendButton_clicked();
    void on_openButton_clicked();
    void Read_Data();
    void transport();
    void on_debug_clicked();

signals:
    void serialok(int*,int,int);
   void sendData(float,float);   //用来传递数据的
private:
    Ui::CCserial *ui;
    QSerialPort *serial;
    QByteArray tempdata = "0";
    QByteArray Achor1;
    QByteArray Achor2;
    QByteArray Achor3;
    QByteArray Achor4;
   // Ui::map *m;
protected:
    QByteArray head;
    QByteArray bagbuff;
    QByteArray tail;
    bool ok;
    bool buffok;
    bool bagok;
    bool showok;
};

#endif // CCSERIAL_H
