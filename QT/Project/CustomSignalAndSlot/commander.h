#ifndef COMMANDER_H
#define COMMANDER_H

#include <QObject>

class Commander : public QObject
{
    Q_OBJECT
public:
    explicit Commander(QObject *parent = nullptr);

signals:
    //冲锋的信号
    void go();
    void go(QString);

    //添加一个"移动"信号
    void move();
};

#endif // COMMANDER_H
