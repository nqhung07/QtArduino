#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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

}

MainWindow::~MainWindow()
{
    delete ui;
}
