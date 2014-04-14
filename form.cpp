#include "form.h"
#include "ui_form.h"

Form::Form(Database *db, QTableWidget *table,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    database = db;
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(edit()));
    database->loadLanguage(ui->comboBox);
    ui->comboBox_2->addItem("Commencé");
    ui->comboBox_2->addItem("Fonctionnel");
    ui->comboBox_2->addItem("Terminé");
    tableWidget = table;
}

Form::~Form()
{
    delete ui;
}
void Form::edit()
{
    database->edit(ui->spinBox->value(),ui->lineEdit->text(), ui->lineEdit_2->text(), ui->comboBox->currentText(), ui->comboBox_2->currentText(), ui->lineEdit_3->text());
    tableWidget->reset();
    database->loadData(tableWidget);
    this->close();
}
