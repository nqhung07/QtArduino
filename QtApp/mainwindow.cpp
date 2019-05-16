#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_serial(new QSerialPort(this))

{
    openSerialPort();
    ui->setupUi(this);

    QWidget *layout = new QWidget;

    //creation and attribute of the slider
    slider = new QSlider(this);
    slider->resize(255,20);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0,255);

    //creation and attribute of the lcd display
    lcd = new QLCDNumber(this);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setFixedSize(200,300);

    //creation of a layout containing the slider
    main_layout = new QVBoxLayout;
    main_layout->addWidget(slider);
    main_layout->addWidget(lcd);


    layout->setLayout(main_layout);
    setCentralWidget(layout);

    //connection between the slider event and the lcd value
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(transmitCmd(int)));
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);


}
void MainWindow::openSerialPort(){

    m_serial->setPortName("COM4");
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    m_serial->open(QIODevice::ReadWrite);

    if (!m_serial->isOpen()){
        QMessageBox::warning(this, "port error", "Impossible to open the port!");
    }
}
void MainWindow::closeSerialPort(){
    m_serial->close();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::transmitCmd(int value)
{
  // send 1 byte to Arduino
  if(value < 0 || value >255)return; //if the value is not between 0 and 255

  QByteArray buf(reinterpret_cast<const char *>(&value), 1); //sizeof(int) for 4 byte of int
  m_serial->write(buf); //send the buffer to Arduino
  qDebug()<<"value: "<<value<<", Byte write to serial port (Hex): "<<buf.toHex(' ');
}

void MainWindow::readSerialData(){
    // received 1 byte from arduino
    QByteArray readData;
    readData = m_serial->readAll();
    bool ok;
    int dec = readData.toHex().toInt(&ok, 16);
    qDebug()<<"Received data from Arduino: (ASCII): "<<readData<<", dec: "<<dec;
}
