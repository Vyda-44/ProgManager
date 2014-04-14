#include "language.h"
#include "ui_language.h"
#include "database.h"

Language::Language(Database *database,QComboBox *box,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Language)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addLanguage()));
    db = database;
    this->activateWindow();
    comboBox = box;
}

Language::~Language()
{
    delete ui;
}
void Language::addLanguage()
{
    db->addLanguage(ui->lineEdit->text());
    for(int i = 0; i < comboBox->count(); i++)
    {
        comboBox->removeItem(i);
    }
    db->loadLanguage(comboBox);
    this->close();
}
