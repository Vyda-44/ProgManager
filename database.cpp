#include "database.h"
#include <iostream>
#include <sstream>

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Prog.db");
    if(db.open())
    {
        std::cout << "Ouverture de la base de données ..." << std::endl;
        db.exec("CREATE TABLE IF NOT EXISTS Logiciel(id INTEGER PRIMARY KEY AUTOINCREMENT,name VARCHAR(40) NOT NULL,version VARCHAR(15) NOT NULL,language VARCHAR(20) NOT NULL,etat VARCAHR(20) NOT NULL, git VARCHAR(150));");
        std::cout << db.lastError().text().toStdString() << std::endl;
        db.exec("CREATE TABLE IF NOT EXISTS Language(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(40), UNIQUE(name));");
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    else
    {
        std::cout << "Impossible d'ouvrir la base de données : " << db.lastError().text().toStdString() << std::endl;
    }
}

void Database::add(QString name, QString version,QString language, QString etat, QString git)
{
    QSqlQuery query(db);
    name = "'" + name + "'";
    version = "'" + version + "'";
    language = "'" + language + "'";
    etat = "'" + etat + "'";
    if(git != "NULL")
    {
        git = "'" + git + "'";
    }

    QString request = "INSERT INTO Logiciel VALUES (NULL ,"+ name + "," + version +"," + language + "," + etat + ","+ git + ");";
    query.exec(request);
    std::cout << "Commande executée : " << request.toStdString() << std::endl;
}
void Database::loadLanguage(QComboBox *comboBox)
{
    for(int i = 0; i < comboBox->count(); i++)
    {
        comboBox->removeItem(i);
    }
    QSqlQueryModel model;
    model.setQuery("SELECT * FROM Language");

    for (int i = 0; i < model.rowCount(); ++i)
    {
      QString name = model.record(i).value("name").toString();
      comboBox->addItem(name);
      std::cout << name.toStdString() << std::endl;
    }
}
void Database::addLanguage(QString name)
{
    db.exec("INSERT INTO Language VALUES(NULL, '"+ name + "')");
}
void Database::loadData(QTableWidget *tableWidget)
{
    QSqlQueryModel model;

    model.setQuery("SELECT * FROM Logiciel");
    for(int i = 0; i < model.rowCount(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        QTableWidgetItem *item4 = new QTableWidgetItem();
        item->setText(model.record(i).value("name").toString());
        tableWidget->setItem(i, 0, item);
        item1->setText(model.record(i).value("version").toString());
        tableWidget->setItem(i, 1, item1);
        item2->setText(model.record(i).value("language").toString());
        tableWidget->setItem(i, 2, item2);
        item3->setText(model.record(i).value("etat").toString());
        tableWidget->setItem(i, 3, item3);
        item4->setText(model.record(i).value("git").toString());
        tableWidget->setItem(i, 4, item4);
    }

}
void Database::edit(int ID, QString name, QString version, QString language, QString etat, QString git)
{
    std::ostringstream id;
    id << ID;
    QString sID = QString::fromStdString(id.str());
    db.exec("UPDATE Logiciel SET name='"+name+"', version='"+version+"',language='"+language+"',etat='"+etat+"',git='"+git+"'WHERE id="+ sID +";");
    std::cout << "Erreur lors de la modification : " << db.lastError().text().toStdString() << std::endl;

}
