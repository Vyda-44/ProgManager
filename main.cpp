#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("ProgManager");
    w.show();
    
    return a.exec();
}
