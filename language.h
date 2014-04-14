#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QWidget>
#include "database.h"

namespace Ui {
class Language;
}

class Language : public QWidget
{
    Q_OBJECT
    
public:
    explicit Language(Database *db,QComboBox *box,QWidget *parent = 0);
    ~Language();

public slots:
    void addLanguage();
    
private:
    Ui::Language *ui;
    Database *db;
    QComboBox *comboBox;
};

#endif // LANGUAGE_H
