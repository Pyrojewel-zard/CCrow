#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdockwidget.h>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    paint1 = new paint();
    setCentralWidget(paint1);
//把赵银笛那个设置成setcentral
    QDockWidget *dock1 = new QDockWidget(tr("serial"),this);
    seriall = new CCserial();

    dock1->setWidget(seriall);
    addDockWidget(Qt::RightDockWidgetArea,dock1);


}

MainWindow::~MainWindow()
{
    workerthread.quit();
    workerthread.wait();
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    //    QPainter painter(this);
    //    painter.translate(200,10);
    //    painter.scale(0.05,0.05);
}
void MainWindow::on_serial_triggered()
{
    seriall = new CCserial(this);
    // mdiarea->addSubWindow(seriall);
    seriall->show();
}
