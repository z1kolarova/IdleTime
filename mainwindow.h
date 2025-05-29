#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionStart_Stop_triggered();

private:
    Ui::MainWindow *ui;
    QPixmap *pixmap;
    QTimer timer;
    bool runTimer;

    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);

};

#endif // MAINWINDOW_H
