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
#include <QSerialPort>
#include <QChar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void openSerialPort();
    void closeSerialPort();
    void transmitCmd(int value);
    void readSerialData();
private:
    Ui::MainWindow *ui;
    QSlider * slider;
    QLCDNumber * lcd;
    QVBoxLayout *main_layout;
    QSerialPort *m_serial = nullptr;
};

#endif // MAINWINDOW_H
