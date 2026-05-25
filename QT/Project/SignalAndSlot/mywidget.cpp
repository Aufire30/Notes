#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    connect(ui->btnMin,&QPushButton::clicked,this,&QWidget::showMinimized);
    connect(ui->btnMax,&QPushButton::clicked,this,&QWidget::showMaximized);
    connect(ui->Normal,&QPushButton::clicked,this,&QWidget::showNormal);
    connect(ui->Close,&QPushButton::clicked,this,&QWidget::close);
}

MyWidget::~MyWidget()
{
    delete ui;
}
