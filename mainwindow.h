#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<paint.h>

#include <QMainWindow>
#include <ccserial.h>
#include <qmdiarea.h>
#include <qmdisubwindow.h>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread workerthread;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    paint * paint1;
protected:
    void paintEvent (QPaintEvent *event);

private slots:
    void on_serial_triggered();

private:
    Ui::MainWindow *ui;

    CCserial *seriall;
    QMdiArea *mdiarea;
};

#endif // MAINWINDOW_H
