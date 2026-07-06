#ifndef STAFFMANAGER_H
#define STAFFMANAGER_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>

class EmployeeEditor;

class StaffManager : public QWidget
{
    Q_OBJECT

public:
    explicit StaffManager(QWidget *parent = nullptr);
    ~StaffManager();

private slots:
    void updateEmployeeView();
    void addDepartment();
    void deleteDepartment();
    void editEmployees();

private:
    void setupDepartmentView();
    void setupEmployeeView();
    void setupButtons();

    QTableView *departmentView;
    QTableView *employeeView;
    QSqlRelationalTableModel *departmentModel;
    QSqlRelationalTableModel *employeeModel;

    QPushButton *addDeptButton;
    QPushButton *deleteDeptButton;
    QPushButton *editEmployeesButton;
    QPushButton *quitButton;

    EmployeeEditor *employeeEditor;
};

#endif // STAFFMANAGER_H
