#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>

class Soldier : public QObject
{
    Q_OBJECT
public:
    explicit Soldier(QObject *parent = nullptr);

signals:

//添加槽函数
public slots:
    void fight();
    void fight(QString);

    //添加一个"逃跑"信号
    void escape();

};

#endif // SOLDIER_H
