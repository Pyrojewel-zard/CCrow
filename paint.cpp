#include "paint.h"
#include "ui_paint.h"
#include<QDebug>
#include <math.h>
#include<location_anchor2.h>
#include<ccserial.h>
extern int n[10];
extern int location_tag_pos_x;
extern int location_tag_pos_y;

paint::paint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paint)
{
    ui->setupUi(this);
    //轨迹初始化
//    last_point[0]=QPoint(tag_pos_x+20+400-20,20+400-tag_pos_y);
//    current_point[0]=QPoint(tag_pos_x+20+400,20+400-tag_pos_y);
    connect(ui->track_box,&QCheckBox::clicked,[=](){
        if(ui->track_box->isChecked())
        {
            qDebug()<<"1";
         //   timer_1=startTimer(500);
        }
        else
        {
          //  killTimer(timer_1);
            qDebug()<<"0";
        }
    });
    //连接按钮信号和赋值
    connect(ui->Anchor_2,&QRadioButton::clicked,[=](){Anchor_2=1;Anchor_3=0;Anchor_4=0;});
    connect(ui->Anchor_3,&QRadioButton::clicked,[=](){Anchor_2=0;Anchor_3=1;Anchor_4=0;});
    connect(ui->Anchor_4,&QRadioButton::clicked,[=](){Anchor_2=0;Anchor_3=0;Anchor_4=1;});
    //CCserial *serial=new CCserial;
   // connect(serial, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    //serial->show();
    //连接坐标
    connect(ui->anchor_pos_button,&QPushButton::clicked,[=](){
        anchor1_pos_x = ui->anchor1_pos_x->text().toInt();
        anchor1_pos_y = ui->anchor1_pos_y->text().toInt();
        anchor1_pos_z = ui->anchor1_pos_z->text().toInt();
        anchor2_pos_x = ui->anchor2_pos_x->text().toInt();
        anchor2_pos_y = ui->anchor2_pos_y->text().toInt();
        anchor2_pos_z = ui->anchor2_pos_z->text().toInt();

        update();
    });
    connect(ui->Startpaint_button,&QPushButton::clicked,[=](){
        if(ui->Startpaint_button->text()=="开始绘制")
            {
            Startpaint=1;
            //qDebug()<<"1";
            timer_1=this->startTimer(1000);
            update();
            ui->Startpaint_button->setText("结束绘制");

        }
        else if(ui->Startpaint_button->text()=="结束绘制")
            {
            killTimer(timer_1);
            Startpaint=0;
            //qDebug()<<"0";

            ui->Startpaint_button->setText("开始绘制");
        }

    });

}

paint::~paint()
{
    delete ui;
}
void paint::paintEvent(QPaintEvent *)
{
    //画边框,画坐标系，默认画笔
    QPainter painter(this);
    painter.drawRect(20, 20, 800, 800);//x,y,w,h
    painter.drawLine(420,20,420,820);
    painter.drawLine(20,420,820,420);
    painter.drawText(830,420,"x");
    painter.drawText(420,10,"y");

    //画圆，黑色画笔
    QPen pen0(QColor(Qt::black));
    pen0.setWidth(2);
    //画基站，红色画笔
    QPen pen1(QColor(Qt::red));
    pen1.setWidth(8);

    //画位置点，绿色画笔
    QPen pen2(QColor(Qt::green));
    pen2.setWidth(8);


    if(Startpaint==1)
    {
        painter.setPen(pen2);
        painter.drawPoint(tag_pos_x+20+400,20+400-tag_pos_y);
        if(ui->track_box->isChecked())
        {
             painter.drawLine(last_point[i],current_point[i]);
        }

        if(Anchor_2)
        {
            painter.setPen(pen1);
            painter.drawPoint(anchor1_pos_x+20+400,20+400-anchor1_pos_y);
            painter.drawPoint(anchor2_pos_x+20+400,20+400-anchor2_pos_y);
            painter.setPen(pen0);
            painter.drawEllipse(QPoint(anchor1_pos_x+20+400,20+400-anchor1_pos_y),tag_dis_1,tag_dis_1);
            painter.drawEllipse(QPoint(anchor2_pos_x+20+400,20+400-anchor2_pos_y),tag_dis_2,tag_dis_2);

        }
    }
    }
void paint::timerEvent(QTimerEvent *){
    i++;
    //anchor1_pos_x=0;
    //anchor1_pos_y=0;
    //tag_dis_1=400;
    //anchor2_pos_x=10;
    //anchor2_pos_y=0;
    //tag_dis_2=400;
//    tag_dis_1=n[0];
//    tag_dis_2=n[1];
//    tag_pos_x=location_tag_pos_x;
//    tag_pos_y=location_tag_pos_y;
    tag_pos_x=tag_pos_x+10;
    tag_pos_y=tag_pos_y+10;
    location_Anchor2(anchor1_pos_x,anchor1_pos_y,tag_dis_1,anchor2_pos_x,anchor2_pos_y,tag_dis_2);


    last_point[i]=current_point[i-1];
    if(i==10)
    {
        last_point[1]=current_point[i-1];
        i=1;
    }
    current_point[i]=QPoint(tag_pos_x+20+400,20+400-tag_pos_y);
    update();


}

void paint::receiveData(QString data)
{
    //ui->tmp_textEdit->setText(str);     //获取传递过来的数据
}
