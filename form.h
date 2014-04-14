#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "database.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form(Database *db,QTableWidget *table,QWidget *parent = 0);
    ~Form();
    
public slots:
    void edit();

private:
    Ui::Form *ui;
    Database *database;
    QTableWidget *tableWidget;
};

#endif // FORM_H
