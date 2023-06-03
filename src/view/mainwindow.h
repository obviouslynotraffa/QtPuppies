#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QIcon>
#include <QToolBar>
#include <QTabWidget>
#include <QMainWindow>
#include <QPushButton>

#include "GeneralPanel.h"
#include "BoardingPanel.h"
#include "BreedingPanel.h"
#include "Dog/container.h"
#include "ButtonsWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
       GeneralPanel* general;
       BoardingPanel* boarding;
       BreedingPanel* breeding;

       Container c;

       QTabWidget* tab_widget;
       QToolBar* toolbar;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

       QLineEdit* nameEdit=nullptr;
       QLineEdit* dateEdit=nullptr;
       QPushButton* btn;
       ButtonsWidget* buttonsw;

public slots:
        void addBreeding();
        void addBoarding();
        void toggleToolbar();

        void insertBoarding(Boarding* boardingDog);
        void insertBreeding(Breeding* breedingDog);
        void removeDog(Dog* dog);

};

#endif // MAINWINDOW_H
