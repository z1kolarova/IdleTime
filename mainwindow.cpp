#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pixmap = NULL;
    resizeEvent(NULL);

    runTimer = true;

    connect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));

    timer.start(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionStart_Stop_triggered()
{
    runTimer = !runTimer;
    if(runTimer)
        timer.start(0);
    else
        timer.stop();
}


void MainWindow::paintEvent(QPaintEvent *)
{
    if(runTimer) {
        QPainter painter(pixmap);
        painter.setPen(Qt::blue);
        painter.setBrush(Qt::white);
        painter.drawEllipse(QPoint(rand() % rect().width(), rand() % rect().height()), 30, 30);

        QPainter wndPainter(this);
        wndPainter.drawPixmap(0, 0, rect().width(), rect().height(), *pixmap);
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    delete pixmap;
    pixmap = new QPixmap(rect().size());

    QPainter painter(pixmap);
    painter.fillRect(rect(), QBrush(QWidget::palette().color(QWidget::backgroundRole())));
}
