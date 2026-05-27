#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

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

protected:
    //事件处理函数，用于响应窗口或控件的大小变化
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
