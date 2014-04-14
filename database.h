#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QtWidgets>

class Database : public QObject
{
    Q_OBJECT

public:
    Database();
    void add(QString name,QString version, QString language, QString etat, QString git);
    void loadLanguage(QComboBox *comboBox);
    void addLanguage(QString name);
    void loadData(QTableWidget *tableWidget);
    void edit(int ID, QString name, QString version, QString language, QString etat, QString git);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
