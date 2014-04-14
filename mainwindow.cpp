#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <database.h>
#include "language.h"
#include "form.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Ui-tableView
    ui->setupUi(this);
    ui->tableWidget->setRowCount(50);
    //ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //Menu
    QMenu *menuBdd = ui->menuBar->addMenu("Base de données");
    QAction *addLanguage = new QAction("Ajouter Language", this);
    QAction *editProject = new QAction("Modifier Projet", this);
    QAction *quit = new QAction("Quitter", this);
    menuBdd->addAction(addLanguage);
    menuBdd->addAction(editProject);
    menuBdd->addAction(quit);
    QObject::connect(addLanguage, SIGNAL(triggered()), this, SLOT(addLanguage()));
    QObject::connect(quit, SIGNAL(triggered()), this, SLOT(close()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(dbAdd()));
    QObject::connect(editProject, SIGNAL(triggered()),this, SLOT(editData()));
    //DATA
    database = new Database;
    database->loadData(ui->tableWidget);
    database->loadLanguage(ui->comboBox);
    //Etat
    ui->comboBox_2->addItem("Commencé");
    ui->comboBox_2->addItem("Fonctionnel");
    ui->comboBox_2->addItem("Terminé");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dbAdd()
{
    database->add(ui->lineEdit->text(), ui->lineEdit_2->text(),ui->comboBox->currentText(),ui->comboBox_2->currentText(), ui->lineEdit_3->text());
    ui->tableWidget->clearContents();
    database->loadData(ui->tableWidget);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
void MainWindow::addLanguage()
{
    Language *language = new Language(database, ui->comboBox);
    language->show();
    std::cout << "Affichage de la fenetre" << std::endl;
}
void MainWindow::editData()
{
    Form *f= new Form(database, ui->tableWidget);
    f->show();
}
