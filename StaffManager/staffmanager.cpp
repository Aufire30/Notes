#include "staffmanager.h"
#include "employeeeditor.h"
#include <QSqlRelationalDelegate>
#include <QMessageBox>
#include <QLabel>
#include <QHeaderView>

StaffManager::StaffManager(QWidget *parent)
    : QWidget(parent), employeeEditor(nullptr)
{
    setWindowTitle(tr("Staff Manager"));
    setMinimumSize(800, 600);

    setupDepartmentView();
    setupEmployeeView();
    setupButtons();

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Department section
    QGroupBox *departmentGroup = new QGroupBox(tr("Departments"));
    QVBoxLayout *deptLayout = new QVBoxLayout;
    deptLayout->addWidget(departmentView);
    departmentGroup->setLayout(deptLayout);

    // Employee section
    QGroupBox *employeeGroup = new QGroupBox(tr("Employees in the Marketing Department"));
    QVBoxLayout *empLayout = new QVBoxLayout;
    empLayout->addWidget(employeeView);
    employeeGroup->setLayout(empLayout);

    // Buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addDeptButton);
    buttonLayout->addWidget(deleteDeptButton);
    buttonLayout->addWidget(editEmployeesButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(quitButton);

    mainLayout->addWidget(departmentGroup, 1);
    mainLayout->addWidget(employeeGroup, 2);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    // Select first department by default
    if (departmentModel->rowCount() > 0) {
        departmentView->selectRow(0);
        updateEmployeeView();
    }
}

StaffManager::~StaffManager()
{
}

void StaffManager::setupDepartmentView()
{
    departmentModel = new QSqlRelationalTableModel(this);
    departmentModel->setTable("department");
    departmentModel->setRelation(2, QSqlRelation("location", "id", "name"));
    departmentModel->setSort(1, Qt::AscendingOrder);
    departmentModel->setHeaderData(1, Qt::Horizontal, tr("Dept."));
    departmentModel->setHeaderData(2, Qt::Horizontal, tr("Location"));
    departmentModel->select();

    departmentView = new QTableView;
    departmentView->setModel(departmentModel);
    departmentView->setItemDelegate(new QSqlRelationalDelegate(this));
    departmentView->setSelectionMode(QAbstractItemView::SingleSelection);
    departmentView->setSelectionBehavior(QAbstractItemView::SelectRows);
    departmentView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    departmentView->resizeColumnsToContents();
    departmentView->horizontalHeader()->setStretchLastSection(true);
    departmentView->setColumnHidden(0, true);

    connect(departmentView->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            this, &StaffManager::updateEmployeeView);
}

void StaffManager::setupEmployeeView()
{
    employeeModel = new QSqlRelationalTableModel(this);
    employeeModel->setTable("employee");
    employeeModel->setRelation(2, QSqlRelation("department", "id", "name"));
    employeeModel->setSort(1, Qt::AscendingOrder);
    employeeModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    employeeModel->setHeaderData(2, Qt::Horizontal, tr("Dept."));
    employeeModel->setHeaderData(3, Qt::Horizontal, tr("Ext."));
    employeeModel->setHeaderData(4, Qt::Horizontal, tr("Email"));
    employeeModel->setHeaderData(5, Qt::Horizontal, tr("Start Date"));

    employeeView = new QTableView;
    employeeView->setModel(employeeModel);
    employeeView->setItemDelegate(new QSqlRelationalDelegate(this));
    employeeView->setSelectionMode(QAbstractItemView::SingleSelection);
    employeeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    employeeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    employeeView->resizeColumnsToContents();
    employeeView->horizontalHeader()->setStretchLastSection(true);
    employeeView->setColumnHidden(0, true);
}

void StaffManager::setupButtons()
{
    addDeptButton = new QPushButton(tr("Add Dept."));
    deleteDeptButton = new QPushButton(tr("Delete Dept."));
    editEmployeesButton = new QPushButton(tr("Edit Employees..."));
    quitButton = new QPushButton(tr("Quit"));

    connect(addDeptButton, &QPushButton::clicked, this, &StaffManager::addDepartment);
    connect(deleteDeptButton, &QPushButton::clicked, this, &StaffManager::deleteDepartment);
    connect(editEmployeesButton, &QPushButton::clicked, this, &StaffManager::editEmployees);
    connect(quitButton, &QPushButton::clicked, this, &QWidget::close);
}

void StaffManager::updateEmployeeView()
{
    QModelIndex index = departmentView->currentIndex();
    if (!index.isValid())
        return;

    QSqlRecord record = departmentModel->record(index.row());
    int departmentId = record.value("id").toInt();
    QString departmentName = record.value("name").toString();

    employeeModel->setFilter(QString("departmentid = %1").arg(departmentId));
    employeeModel->select();

    QGroupBox *employeeGroup = qobject_cast<QGroupBox*>(employeeView->parentWidget());
    if (employeeGroup) {
        employeeGroup->setTitle(tr("Employees in the %1 Department").arg(departmentName));
    }
}

void StaffManager::addDepartment()
{
    int row = departmentModel->rowCount();
    departmentModel->insertRow(row);
    QModelIndex index = departmentModel->index(row, 1);
    departmentView->setCurrentIndex(index);
    departmentView->edit(index);
}

void StaffManager::deleteDepartment()
{
    QModelIndex index = departmentView->currentIndex();
    if (!index.isValid())
        return;

    QSqlRecord record = departmentModel->record(index.row());
    QString departmentName = record.value("name").toString();
    int departmentId = record.value("id").toInt();

    QSqlRelationalTableModel checkModel;
    checkModel.setTable("employee");
    checkModel.setFilter(QString("departmentid = %1").arg(departmentId));
    checkModel.select();

    if (checkModel.rowCount() > 0) {
        QMessageBox::warning(this, tr("Delete Department"),
                           tr("Cannot delete department '%1' because it has %2 employee(s).\n"
                              "Please reassign or delete the employees first.")
                           .arg(departmentName).arg(checkModel.rowCount()));
        return;
    }

    int ret = QMessageBox::question(this, tr("Delete Department"),
                                   tr("Are you sure you want to delete department '%1'?")
                                   .arg(departmentName),
                                   QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        departmentModel->removeRow(index.row());
        departmentModel->submitAll();
        departmentModel->select();
    }
}

void StaffManager::editEmployees()
{
    if (!employeeEditor) {
        employeeEditor = new EmployeeEditor(this);
        connect(employeeEditor, &EmployeeEditor::employeesUpdated,
                this, &StaffManager::updateEmployeeView);
    }
    employeeEditor->show();
    employeeEditor->raise();
    employeeEditor->activateWindow();
}
