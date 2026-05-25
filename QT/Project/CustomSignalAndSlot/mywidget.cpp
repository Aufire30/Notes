#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //1、SIGNAL/SLOT(QT4)
#if 0
    commander = new Commander(this);
    soldier = new Soldier(this);

    connect(commander,SIGNAL(go()),soldier,SLOT(fight()));
    connect(commander,SIGNAL(go(QString)),soldier,SLOT(fight(QString)));

    commander->go();
    commander->go("freedom");
#endif

    //2、自定义函数指针
#if 0
    commander = new Commander(this);
    soldier = new Soldier(this);

    //没用同名的信号和槽时，可以直接这样写，因为不存在二义性
    //connect(commander,&Commander::go,soldier,&Soldier::fight);

    void (Commander::*Pgo)() = &Commander::go;
    void (Soldier::*Pfight)() = &Soldier::fight;
    connect(commander,Pgo,soldier,Pfight);

    void (Commander::*PgoForFreedom)(QString) = &Commander::go;
    void (Soldier::*PfightForFreedom)(QString) = &Soldier::fight;
    connect(commander,PgoForFreedom,soldier,PfightForFreedom);

    commander->go();
    commander->go("freedom");
#endif

    //3、信号槽重载：精简写法
#if 0
    commander = new Commander(this);
    soldier = new Soldier(this);

    //使用类模板:QOverload
    connect(commander,QOverload<>::of(&Commander::go),soldier,QOverload<>::of(&Soldier::fight));
    connect(commander,QOverload<QString>::of(&Commander::go),soldier,QOverload<QString>::of(&Soldier::fight));

    //或者使用函数模板:qOverload
    connect(commander,qOverload<>(&Commander::go),qOverload<>(&Soldier::fight));
    connect(commander,qOverload<QString>(&Commander::go),soldier,qOverload<QString>(&Soldier::fight));

    commander->go();
    commander->go("freedom");
#endif

    //4、一个槽连接多个信号
#if 0
    commander = new Commander(this);
    soldier = new Soldier(this);

    soldier2 = new Soldier(this);

    //冲锋
    connect(commander,QOverload<>::of(&Commander::go),soldier,QOverload<>::of(&Soldier::fight));

    //逃跑
    connect(commander,QOverload<>::of(&Commander::go),soldier2,QOverload<>::of(&Soldier::escape));


    commander->go();
#endif

    //5、多个槽连接一个信号
#if 0
    commander = new Commander(this);
    soldier = new Soldier(this);


    //冲锋
    connect(commander,QOverload<>::of(&Commander::go),soldier,QOverload<>::of(&Soldier::fight));

    connect(commander,QOverload<>::of(&Commander::move),soldier,QOverload<>::of(&Soldier::fight));



    commander->go();
    commander->move();
#endif

    //6、信号连接信号
#if 0
    commander = new Commander(this);
    soldier = new Soldier(this);


    //冲锋
    connect(ui->btnSginal2Signal,&QPushButton::clicked,commander,&Commander::move);

    connect(commander,&Commander::move,soldier,QOverload<>::of(&Soldier::fight));


    commander->go();
    commander->move();
#endif

    //7、断开信号连接
#if 0
    commander = new Commander(this);
    soldier = new Soldier(this);

    //使用类模板:QOverload
    connect(commander,QOverload<>::of(&Commander::go),soldier,QOverload<>::of(&Soldier::fight));
    connect(commander,QOverload<QString>::of(&Commander::go),soldier,QOverload<QString>::of(&Soldier::fight));


    commander->go();

    commander->disconnect();//断开信号槽连接
    commander->go("freedom");

#endif

    //8、获取发送信号的对象
#if 1
    connect(ui->btnStart,&QPushButton::clicked,this,&MyWidget::onBtnsClicked);
    connect(ui->btnStop,&QPushButton::clicked,this,&MyWidget::onBtnsClicked);
#endif
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::onBtnsClicked()
{
    //获取发送信号的对象指针
    QObject* senderobj = sender();

    //将指针转换成QPushbutton类型
    QPushButton* button =  qobject_cast<QPushButton*>(senderobj);

    //如果转换成功，说明是一个按钮发送了信号
    if(button)
    {
        if(button == ui->btnStart)
        {
            qDebug() << "启动";
        }
        else if(button == ui->btnStop)
        {
            qDebug() << "停止";
        }
    }
}
