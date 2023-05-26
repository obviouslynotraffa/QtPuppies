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

#include "GeneralPanel.h"
#include "BoardingPanel.h"
#include "BreedingPanel.h"
#include "Dog/container.h"

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

signals:

};

#endif // MAINWINDOW_H
