#include <QApplication>
#include <QIcon>

#include "view/mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Qt Puppies");
    a.setWindowIcon(QIcon(":/assets/appIcon.png"));
    w.resize(900, 600);
    w.setMinimumHeight(600);
    w.setMinimumWidth(1000);
    w.setMaximumHeight(600);
    w.setMaximumWidth(1000);
    w.show();
    return a.exec();
}
