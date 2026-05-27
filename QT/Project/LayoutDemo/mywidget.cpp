#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::resizeEvent(QResizeEvent *event)
{
    static int index = 1;

    int linecnt = ui->textEdit->document()->lineCount();
    if(linecnt > 100*6)
    {
        ui->textEdit->clear();
        index = 1;
    }

    //索引
    QString strIndex = QString("[%1]-----------").arg(index++);

    //按钮的宽度
    QString width = QString("按钮宽度: \t%1, %2, %3, %4")
                        .arg(ui->btnAdd->width())
                        .arg(ui->btnDelete->width())
                        .arg(ui->btnModify->width())
                        .arg(ui->btnFind->width());

    ui->textEdit->append(strIndex);
    ui->textEdit->append(width);

    //边距
    QMargins margins = ui->horizontalwidget->layout()->contentsMargins();
    QString strMargins = QString("边距(左上右下): \t%1, %2, %3, %4")
                             .arg(margins.left())
                             .arg(margins.top())
                             .arg(margins.right())
                             .arg(margins.bottom());

    ui->textEdit->append(strMargins);

    //移动光标到最后一行
    ui->textEdit->moveCursor(QTextCursor::End);


}
