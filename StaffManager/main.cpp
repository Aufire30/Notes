#include "staffmanager.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

bool createDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("staffmanager.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                            QObject::tr("Cannot open database:\n%1")
                            .arg(db.lastError().text()));
        return false;
    }

    // Check if tables already exist
    QSqlQuery query;
    query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='employee'");

    if (query.next()) {
        // Database already exists
        return true;
    }

    // Read and execute SQL file
    QFile file("create_tables_staffmanager.sql");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                            QObject::tr("Cannot open SQL file: create_tables_staffmanager.sql"));
        return false;
    }

    QTextStream in(&file);
    QString sqlScript = in.readAll();
    file.close();

    // Split SQL script by semicolons and execute each statement
    QStringList sqlStatements = sqlScript.split(';', Qt::SkipEmptyParts);

    for (const QString &statement : sqlStatements) {
        QString trimmed = statement.trimmed();
        if (trimmed.isEmpty() || trimmed.startsWith("--")) {
            continue;
        }

        if (!query.exec(trimmed)) {
            QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                QObject::tr("Failed to execute SQL:\n%1\n\nError: %2")
                                .arg(trimmed).arg(query.lastError().text()));
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!createDatabase()) {
        return 1;
    }

    StaffManager manager;
    manager.show();

    return app.exec();
}
