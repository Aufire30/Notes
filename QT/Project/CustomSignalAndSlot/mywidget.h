#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

#include "commander.h"
#include "soldier.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;
}
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget() override;

public slots:
    void onBtnsClicked();


private:
    Ui::MyWidget *ui;

    Commander *commander;
    Soldier *soldier;

    Soldier *soldier2;

};
#endif // MYWIDGET_H
