#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QtGui>
#include <QVBoxLayout>
#include <QSlider>
#include <QLCDNumber>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSlider * slider;
    QLCDNumber * lcd;
    QVBoxLayout *main_layout;
};

#endif // MAINWINDOW_H
