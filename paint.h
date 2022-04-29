#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QPainter>
namespace Ui {
class paint;
}

class paint : public QWidget
{
    Q_OBJECT

public:
    explicit paint(QWidget *parent = 0);
    ~paint();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    int timer_1;
    //ui上对应的按钮
    bool Anchor_2 = 0;
    bool Anchor_3 = 0;
    bool Anchor_4 = 0;
    //绘制与否变量
    bool Startpaint = 0;
    //标签位置
    int tag_pos_x = 0;
    int tag_pos_y = 0;
    //轨迹最大点数.轨迹点坐标数组,qpoint点数组
    #define number_tag 10
    int i=0;
    int severaltag_x[number_tag];
    int severaltag_y[number_tag];
    QPoint last_point[number_tag];
    QPoint current_point[number_tag];

    //ui上对应的基站位置
    int anchor1_pos_x = 0;
    int anchor1_pos_y = 0;
    int anchor1_pos_z = 0;
    int anchor2_pos_x = 0;
    int anchor2_pos_y = 0;
    int anchor2_pos_z = 0;
    int anchor3_pos_x = 0;
    int anchor3_pos_y = 0;
    int anchor3_pos_z = 0;
    //用于二基站定位的距离
    int tag_dis_1 = 200 ;
    int tag_dis_2 = 200 ;
private:
    Ui::paint *ui;
private slots:
    void receiveData(QString data);   //接收传递过来的数据的槽
};

#endif // PAINT_H
