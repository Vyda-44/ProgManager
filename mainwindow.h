#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <database.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void dbAdd();
    void addLanguage();
    void editData();
private:
    Ui::MainWindow *ui;
    Database *database;

};

#endif // MAINWINDOW_H
