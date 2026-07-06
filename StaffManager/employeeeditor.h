#ifndef EMPLOYEEEDITOR_H
#define EMPLOYEEEDITOR_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>

class EmployeeEditor : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeEditor(QWidget *parent = nullptr);
    ~EmployeeEditor();

signals:
    void employeesUpdated();

private slots:
    void first();
    void previous();
    void next();
    void last();
    void addEmployee();
    void deleteEmployee();

private:
    void setupModel();
    void setupUI();
    void setupMapper();

    QSqlRelationalTableModel *tableModel;
    QDataWidgetMapper *mapper;

    QLineEdit *nameEdit;
    QComboBox *departmentComboBox;
    QLineEdit *extensionLineEdit;
    QLineEdit *emailEdit;
    QDateEdit *startDateEdit;

    QPushButton *firstButton;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *lastButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *closeButton;
};

#endif // EMPLOYEEEDITOR_H
