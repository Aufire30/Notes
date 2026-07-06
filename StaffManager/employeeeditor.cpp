#include "employeeeditor.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QSqlRelationalDelegate>
#include <QDate>

EmployeeEditor::EmployeeEditor(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Edit Employees"));
    setMinimumSize(500, 300);

    setupModel();
    setupUI();
    setupMapper();

    mapper->toFirst();
}

EmployeeEditor::~EmployeeEditor()
{
}

void EmployeeEditor::setupModel()
{
    tableModel = new QSqlRelationalTableModel(this);
    tableModel->setTable("employee");
    tableModel->setRelation(2, QSqlRelation("department", "id", "name"));
    tableModel->setSort(1, Qt::AscendingOrder);
    tableModel->select();
}

void EmployeeEditor::setupUI()
{
    nameEdit = new QLineEdit;
    departmentComboBox = new QComboBox;
    extensionLineEdit = new QLineEdit;
    emailEdit = new QLineEdit;
    startDateEdit = new QDateEdit;
    startDateEdit->setCalendarPopup(true);
    startDateEdit->setDisplayFormat("M/d/yy");

    QSqlTableModel *relationModel = tableModel->relationModel(2);
    departmentComboBox->setModel(relationModel);
    departmentComboBox->setModelColumn(relationModel->fieldIndex("name"));

    firstButton = new QPushButton(tr("<< First"));
    previousButton = new QPushButton(tr("< Previous"));
    nextButton = new QPushButton(tr("Next >"));
    lastButton = new QPushButton(tr("Last >>"));
    addButton = new QPushButton(tr("Add"));
    deleteButton = new QPushButton(tr("Delete"));
    closeButton = new QPushButton(tr("Close"));

    connect(firstButton, &QPushButton::clicked, this, &EmployeeEditor::first);
    connect(previousButton, &QPushButton::clicked, this, &EmployeeEditor::previous);
    connect(nextButton, &QPushButton::clicked, this, &EmployeeEditor::next);
    connect(lastButton, &QPushButton::clicked, this, &EmployeeEditor::last);
    connect(addButton, &QPushButton::clicked, this, &EmployeeEditor::addEmployee);
    connect(deleteButton, &QPushButton::clicked, this, &EmployeeEditor::deleteEmployee);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);

    QHBoxLayout *navigationLayout = new QHBoxLayout;
    navigationLayout->addWidget(firstButton);
    navigationLayout->addWidget(previousButton);
    navigationLayout->addWidget(nextButton);
    navigationLayout->addWidget(lastButton);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("Name:"), nameEdit);
    formLayout->addRow(tr("Department:"), departmentComboBox);
    formLayout->addRow(tr("Extension:"), extensionLineEdit);
    formLayout->addRow(tr("Email:"), emailEdit);
    formLayout->addRow(tr("Start Date:"), startDateEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(navigationLayout);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void EmployeeEditor::setupMapper()
{
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper->setModel(tableModel);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(nameEdit, 1);
    mapper->addMapping(departmentComboBox, 2);
    mapper->addMapping(extensionLineEdit, 3);
    mapper->addMapping(emailEdit, 4);
    mapper->addMapping(startDateEdit, 5);
}

void EmployeeEditor::first()
{
    mapper->toFirst();
}

void EmployeeEditor::previous()
{
    mapper->toPrevious();
}

void EmployeeEditor::next()
{
    mapper->toNext();
}

void EmployeeEditor::last()
{
    mapper->toLast();
}

void EmployeeEditor::addEmployee()
{
    int row = tableModel->rowCount();
    tableModel->insertRow(row);
    mapper->setCurrentIndex(row);

    nameEdit->clear();
    extensionLineEdit->clear();
    emailEdit->clear();
    startDateEdit->setDate(QDate::currentDate());

    nameEdit->setFocus();
    emit employeesUpdated();
}

void EmployeeEditor::deleteEmployee()
{
    int currentRow = mapper->currentIndex();

    if (currentRow < 0)
        return;

    QSqlRecord record = tableModel->record(currentRow);
    QString employeeName = record.value("name").toString();

    int ret = QMessageBox::question(this, tr("Delete Employee"),
                                   tr("Are you sure you want to delete employee '%1'?")
                                   .arg(employeeName),
                                   QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        tableModel->removeRow(currentRow);
        tableModel->submitAll();
        tableModel->select();

        if (currentRow >= tableModel->rowCount()) {
            mapper->toLast();
        } else {
            mapper->setCurrentIndex(currentRow);
        }

        emit employeesUpdated();
    }
}
