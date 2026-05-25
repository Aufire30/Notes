#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QDateTime>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //1、最大化显示(SIGNAL/SLOT)
    connect(ui->btnMax,SIGNAL(clicked()),this,SLOT(showMaximized()));

    //2、正常显示(函数地址)
    connect(ui->Normal,&QPushButton::clicked,this,&QWidget::showNormal);

    //3、lambda表达式
    //(1)匿名函数的定义
#if 0
    []()
    {
        qDebug() << "lambda..";
    };
#endif
    //(2)匿名函数的调用
#if 0
    []()
    {
        qDebug() << "lambda..";
    }();
#endif
    //(3)不捕获任何变量
    int a = 10;
#if 0
    []()
    {
        qDebug() << a;
    }();
#endif
    //(4)按引用进行捕获
#if 0
    [&]()
    {
        qDebug() << a++;//引用，在lambda表达式内被修改，原来的对象的值也会被修改
    }();
    qDebug() << a;
#endif
    //(5)按值进行捕获
#if 0
    [=]()
    {
        qDebug() << a++;//按值捕获的变量，在lambda表达式中是只读的，不能被修改
    }();
#endif
    //(6)按值捕获 + mutable选项
    //添加mutable选项，就可以在lambda表达式内修改捕获的变量了
    //按值捕获，里面的修改，不会影响外面
#if 0
    [=]()mutable
    {
        qDebug() << a++;//10
    }();
    qDebug() << a; //11 ?
#endif
    //(7)参数
#if 0
    [](int x,int y)
    {
        qDebug() << x + y;
    }(1 , 2);
#endif
    //(8)返回值
#if 0
    int sum =[](int x,int y)-> int
    {
        return  x + y;
    }(1 , 2);
    qDebug() << sum;
#endif

    //使用lambda表达式做槽函数
    connect(ui->Title,&QPushButton::clicked,this,
        [this]()
        {
            QString title = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss");
            this->setWindowTitle(title);
        });
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_btnMin_clicked()
{
    this->showMinimized();
}

