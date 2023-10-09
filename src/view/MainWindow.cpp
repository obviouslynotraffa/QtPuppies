#include <QPushButton>
#include <QToolBar>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QDialog>
#include <QDateTime>
#include <QStatusBar>
#include <QFileDialog>
#include <QFileDevice>

#include "MainWindow.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"

#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"

#include "Dog/owner.h"
#include "./view/buttons/FinalButtonWidget.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow{parent}{

    //Actions
    QAction *newfile = new QAction(QIcon(QPixmap((":/assets/icons8-add-file-48.png"))),"New file");
    QAction *openfile = new QAction(QIcon(QPixmap((":/assets/icons8-folder-48.png"))),"Open file");
    save = new QAction(QIcon(QPixmap((":/assets/icons8-save-48.png"))),"Save");
    saveAs = new QAction(QIcon(QPixmap((":/assets/icons8-save-as-48.png"))),"Save as");
    boardBtn = new QAction(QIcon(QPixmap((":/assets/icons8-doge-48.png"))),"Add boarding dog");
    breedBtn = new QAction(QIcon(QPixmap((":/assets/icons8-puppy-48.png"))),"Add breeding dog");
    QAction *toolb = new QAction(QIcon(QPixmap((":/assets/icons8-invisible-48.png"))),"Toggled toolbar");

    save->setEnabled(false);
    saveAs->setEnabled(false);
    boardBtn->setEnabled(false);
    breedBtn->setEnabled(false);


    newfile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    openfile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    saveAs->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));


    //Menubar
    QMenu *file = menuBar()->addMenu("&File");
    QMenu *addDog = menuBar()->addMenu("&New Dog");
    QMenu *options = menuBar()->addMenu("&View");

    file->addAction(newfile);
    file->addAction(openfile);
    file->addAction(save);
    file->addAction(saveAs);

    addDog->addAction(boardBtn);
    addDog->addAction(breedBtn);

    options->addAction(toolb);

    //Toolbar
    toolbar = addToolBar("View Toolbar");
    toolbar->addAction(newfile);
    toolbar->addAction(openfile);
    toolbar->addAction(save);
    toolbar->addAction(saveAs);
    toolbar->addAction(breedBtn);
    toolbar->addAction(boardBtn);
    toolbar->setIconSize(QSize(32,32));


    //Panel
    general= new GeneralPanel(c,this);
    breeding= new BreedingPanel(c.filterBreeding(),this);
    boarding= new BoardingPanel(c.filterBoarding(),this);


    //Tab
    tab_widget= new QTabWidget();
    tab_widget->addTab(general,"General");
    tab_widget->addTab(breeding,"Breeding");
    tab_widget->addTab(boarding,"Boarding");
    setCentralWidget(tab_widget);


    QMainWindow::statusBar()->showMessage("Ready",3069);



    //connect
    connect(breedBtn, &QAction::triggered, this, &MainWindow::addBreeding);
    connect(boardBtn, &QAction::triggered, this, &MainWindow::addBoarding);
    connect(toolb, &QAction::triggered, this, &MainWindow::toggleToolbar);
    connect(general, &GeneralPanel::signalDelete, this, &MainWindow::removeDog);
    connect(breeding, &BreedingPanel::signalDelete, this, &MainWindow::removeDog);
    connect(boarding, &BoardingPanel::signalDelete, this, &MainWindow::removeDog);
    connect(newfile, &QAction::triggered, this, &MainWindow::newDataset);
    connect(openfile, &QAction::triggered, this, &MainWindow::openDataset);
    connect(save, &QAction::triggered, this, &MainWindow::saveDataset);
    connect(saveAs, &QAction::triggered, this, &MainWindow::saveAsDataset);

}


MainWindow::~MainWindow(){}



void MainWindow::addBoarding(){

    QVBoxLayout* inputPanel= new QVBoxLayout;

    QHBoxLayout* hbox= new QHBoxLayout();
    inputPanel->addLayout(hbox);


    //--------Dog--------//

    QGroupBox* dogGroup= new QGroupBox(tr("Dog's info"));
    hbox->addWidget(dogGroup);

    //Name
    QLabel* dogname= new QLabel("Name: ");
    QLineEdit* nameEdit= new QLineEdit;
    nameEdit->setFixedWidth(150);


    //Date
    QLabel* dogdate= new QLabel("Arrival date: ");
    QLineEdit* dateEdit= new QLineEdit;
    dateEdit->setFixedWidth(150);
    QString today= QDate::currentDate().toString("dd/MM/yyyy");
    dateEdit->setText(today);


    //Breed
    QLabel* dogbreed= new QLabel("Breed: ");
    QLineEdit* breedEdit= new QLineEdit;
    breedEdit->setFixedWidth(150);


    //Size
    QLabel* dogsize= new QLabel("Size: ");
    QComboBox* sizeEdit= new QComboBox;
    sizeEdit->setFixedWidth(150);
    sizeEdit->addItem(tr("Large"));
    sizeEdit->addItem(tr("Medium"));
    sizeEdit->addItem(tr("Small"));




    //Optionals
    QLabel* dogoption= new QLabel("Optional serivces");
    QCheckBox* bath= new QCheckBox(QString("Bath"));
    QCheckBox* walks= new QCheckBox(QString("Walks"));
    QCheckBox* diet= new QCheckBox(QString("Diet"));
    QCheckBox* training= new QCheckBox(QString("Trainings"));




    //set up grid layout for dog
    QGridLayout* dogLayout= new QGridLayout;
    dogLayout->addWidget(dogname, 0,0);
    dogLayout->addWidget(nameEdit, 0,1);

    dogLayout->addWidget(dogdate, 1,0);
    dogLayout->addWidget(dateEdit, 1,1);

    dogLayout->addWidget(dogbreed, 2,0);
    dogLayout->addWidget(breedEdit, 2,1);

    dogLayout->addWidget(dogsize, 3,0);
    dogLayout->addWidget(sizeEdit, 3,1);

    dogLayout->addWidget(dogoption, 4,0);
    dogLayout->addWidget(bath, 5,1);
    dogLayout->addWidget(walks, 5,2);
    dogLayout->addWidget(diet, 6,1);
    dogLayout->addWidget(training, 6,2);

    dogGroup->setLayout(dogLayout);



    //---------Owner-----------//
    QGroupBox* ownerBox= new QGroupBox(tr("Owner's info"));
    hbox->addWidget(ownerBox);


    //Name
    QLabel* owname= new QLabel("Name: ");
    QLineEdit* ownameEdit= new QLineEdit;
    ownameEdit->setFixedWidth(150);

    //Surname
    QLabel* owsurname= new QLabel("Surname: ");
    QLineEdit* surnameEdit= new QLineEdit;
    surnameEdit->setFixedWidth(150);

    //Date
    QLabel* owdate= new QLabel("Day of birth: ");
    QLineEdit* owdateEdit= new QLineEdit;
    owdateEdit->setFixedWidth(150);

    //Phone number
    QLabel* number= new QLabel("Phone: ");
    QLineEdit* numberEdit= new QLineEdit;
    numberEdit->setFixedWidth(150);


    //Addres
    QLabel* address= new QLabel("Address: ");
    QLineEdit* addressEdit= new QLineEdit;
    addressEdit->setFixedWidth(150);


    //House number
    QLabel* hn= new QLabel("House's number: ");
    QLineEdit* hnEdit= new QLineEdit;
    hnEdit->setFixedWidth(150);

    //set up owner layout
    QGridLayout* ownerLayout= new QGridLayout;
    ownerLayout->addWidget(owname, 0 ,0);
    ownerLayout->addWidget(ownameEdit,0,1);

    ownerLayout->addWidget(owsurname, 1 ,0);
    ownerLayout->addWidget(surnameEdit,1,1);

    ownerLayout->addWidget(owdate, 2 ,0);
    ownerLayout->addWidget(owdateEdit,2,1);

    ownerLayout->addWidget(number, 3 ,0);
    ownerLayout->addWidget(numberEdit,3,1);

    ownerLayout->addWidget(address, 4 ,0);
    ownerLayout->addWidget(addressEdit,4,1);

    ownerLayout->addWidget(hn, 5 ,0);
    ownerLayout->addWidget(hnEdit,5,1);

    ownerBox->setLayout(ownerLayout);

    //save button
    FinalButtonWidget* button= new FinalButtonWidget(nameEdit, dateEdit, breedEdit, sizeEdit,bath, walks, diet, training,
                                                     ownameEdit, surnameEdit, owdateEdit, numberEdit, addressEdit, hnEdit);
    inputPanel->addWidget(button);

    connect(button, &FinalButtonWidget::addBoarding, this, &MainWindow::insertBoarding);
    connect(button, &FinalButtonWidget::closeDialog, this, &MainWindow::closeWindow);


    window= new QDialog;
    window->setLayout(inputPanel);
    window->setModal(true);
    window->show();


}


void MainWindow::closeWindow(){
    window->deleteLater();
}


void MainWindow::insertBoarding(Boarding* boardingDog){
    c=c.push_back(boardingDog);

    repository->create(boardingDog);
    repository->create(boardingDog->getOwner());

    general->setContainer(c);
    boarding->setContainer(c.filterBoarding());

    general->refresh();
    boarding->refresh();

    QMainWindow::statusBar()->showMessage("New dog created",3000);


}


void MainWindow::addBreeding(){


    QVBoxLayout* inputPanel= new QVBoxLayout;

    QHBoxLayout* hbox= new QHBoxLayout();
    inputPanel->addLayout(hbox);



    //---------Dog---------//

    QGroupBox* dogGroup= new QGroupBox(tr("Dog's info"));
    hbox->addWidget(dogGroup);

    //Name
    QLabel* dogname= new QLabel("Name: ");
    QLineEdit* nameEdit= new QLineEdit;
    nameEdit->setFixedWidth(150);


    //Date
    QLabel* dogdate= new QLabel("Birthday: ");
    QLineEdit* dateEdit= new QLineEdit;
    dateEdit->setFixedWidth(150);
    dateEdit->setFixedWidth(150);
    QString today= QDate::currentDate().toString("dd/MM/yyyy");
    dateEdit->setText(today);


    //Breed
    QLabel* breedDog= new QLabel("Breed: ");
    QComboBox* breedEdit= new QComboBox;
    breedEdit->setFixedWidth(150);
    breedEdit->addItem(tr("AmStaff"));
    breedEdit->addItem(tr("Bulldog"));


    //Optionals
    QLabel* dogoption= new QLabel("Options: ");
    QCheckBox* vax= new QCheckBox(QString("Vaxxed"));
    QCheckBox* purch= new QCheckBox(QString("Purchasable"));
    QCheckBox* booked= new QCheckBox(QString("Booked"));


    //set up dog layout
    QGridLayout* dogLayout= new QGridLayout;
    dogLayout->addWidget(dogname, 0,0,1,10);
    dogLayout->addWidget(nameEdit, 0,1,1,10);

    dogLayout->addWidget(dogdate, 1,0,1,10);
    dogLayout->addWidget(dateEdit, 1,1,1,10);

    dogLayout->addWidget(breedDog, 2,0,1,10);
    dogLayout->addWidget(breedEdit, 2,1,1,10);

    dogLayout->addWidget(dogoption, 4,0);
    dogLayout->addWidget(vax, 5,1);
    dogLayout->addWidget(purch, 5,2);
    dogLayout->addWidget(booked, 6,1);

    dogGroup->setLayout(dogLayout);



    //------Parents--------//
    QGroupBox* parentGroup= new QGroupBox(tr("Parent's info"));
    hbox->addWidget(parentGroup);

    std::vector<Breeding*> parents = c.filterParent();

    //Mother
    QGroupBox* mom = new QGroupBox(tr("Mom"));

    QLabel* mother= new QLabel("Select mother: ");
    QComboBox* listmom= new QComboBox;
    if(parents.empty())
    {
        listmom->addItem("None");
    }
    else
    {
        listmom->addItem("None");
        for(auto it=parents.begin(); it!= parents.end(); it++){
            listmom->addItem(QString::fromStdString((*it)->getName()));
        }


    }



    QGridLayout* momLayout= new QGridLayout;

    momLayout->addWidget(mother,0,0);
    momLayout->addWidget(listmom,0,1);
    mom->setLayout(momLayout);


    //Father
    QGroupBox* dad = new QGroupBox(tr("Dad"));
    QLabel* father= new QLabel("Select father: ");
    QComboBox* listdad= new QComboBox;
    if(parents.empty())
    {
        listdad->addItem("None");
    }
    else
    {
        listdad->addItem("None");
        for(auto it=parents.begin(); it!= parents.end(); it++){
            listdad->addItem(QString::fromStdString((*it)->getName()));
        }


    }



    QGridLayout* dadLayout= new QGridLayout;

    dadLayout->addWidget(father,0,0);
    dadLayout->addWidget(listdad,0,1);

    dad->setLayout(dadLayout);

    //set up parent layout
    QGridLayout* parentLayout= new QGridLayout;
    parentLayout->addWidget(mom,0,0,1,10);
    parentLayout->addWidget(dad,1,0,1,10);

    parentGroup->setLayout(parentLayout);



    //save button
    FinalButtonWidget* button= new FinalButtonWidget(nameEdit, dateEdit, breedEdit, vax, booked, purch, listmom, listdad, c);
    inputPanel->addWidget(button);

    connect(button, &FinalButtonWidget::addBreeding, this, &MainWindow::insertBreeding);
    connect(button, &FinalButtonWidget::closeDialog, this, &MainWindow::closeWindow);


    //create window
    window= new QDialog;
    window->setLayout(inputPanel);
    window->setModal(true);
    window->show();


}


void MainWindow::insertBreeding(Breeding *breedingDog){
    c=c.push_back(breedingDog);

    repository->create(breedingDog);

    general->setContainer(c);
    breeding->setContainer(c.filterBreeding());

    general->refresh();
    breeding->refresh();

    QMainWindow::statusBar()->showMessage("New dog created",3000);
}


void MainWindow::removeDog(Dog *dog){

    c=c.erase(dog);
    if(dynamic_cast<Breeding*>(dog))
    {
        breeding->setContainer(c.filterBreeding());

        std::vector<Dog*>w (repository->readAllDogs());

        for(Dog* d: w)
        {
            Breeding* breeding = dynamic_cast<Breeding*>(d);
            if(breeding)
            {
                if(breeding->getFather()==dog)breeding->setDad(nullptr);
                if(breeding->getMother()==dog)breeding->setMom(nullptr);
            }
        }

    }
    else if(dynamic_cast<Boarding*>(dog))
    {
        boarding->setContainer(c.filterBoarding());
        repository->removeOwner(static_cast<Boarding*>(dog)->getOwner());

    }

    QMainWindow::statusBar()->showMessage(QString::fromStdString(dog->getName()) + " has been deleted",3000);
    repository->removeDog(dog);



    general->setContainer(c);

    general->refresh();
    breeding->refresh();
    boarding->refresh();


    delete dog;
}


void MainWindow::toggleToolbar(){
    toolbar->setVisible(!toolbar->isVisible());
}


MainWindow& MainWindow::reloadData(){

    c.clearAll();

    std::vector<Dog*> dogs (repository->readAllDogs());


    for(auto it = dogs.begin();
        it!=dogs.end();
        it++)
    {
        c.push_back(*it);
    }


    general->setContainer(c);
    boarding->setContainer(c.filterBoarding());
    breeding->setContainer(c.filterBreeding());


    return *this;
}


void MainWindow::newDataset(){
    QString path = QFileDialog::getSaveFileName(
                this,
                "Creates new Dataset",
                "./",
                "JSON files *.json"
            );

    if(path.isEmpty()){
        return;
    }


    if(repository != nullptr){
        repository->store();
        delete repository;
    }


    Reader reader;
    Json converter(reader);

    c=c.clearAll();
    general->setContainer(c);
    breeding->setContainer(c.filterBreeding());
    boarding->setContainer(c.filterBoarding());


    JsonFile data_mapper(path.toStdString(),converter);
    repository =  new JsonRepo(data_mapper);


    boardBtn->setEnabled(true);
    breedBtn->setEnabled(true);
    save->setEnabled(true);
    saveAs->setEnabled(true);



    QMainWindow::statusBar()->showMessage("New dataset created",3000);

}




void MainWindow::openDataset(){
    QString path = QFileDialog::getOpenFileName(
                this,
                "Open Dataset",
                "./",
                "JSON files *.json"
            );

    if(path.isEmpty()){
        return;
    }

    if(repository!=nullptr){
        delete repository;
    }

    Reader reader;
    Json converter(reader);
    JsonFile data_mapper(path.toStdString(),converter);
    repository =  new JsonRepo(data_mapper);

    reloadData();

    boardBtn->setEnabled(true);
    breedBtn->setEnabled(true);
    save->setEnabled(true);
    saveAs->setEnabled(true);

    general->refresh();
    breeding->refresh();
    boarding->refresh();

   QMainWindow::statusBar()->showMessage("Dataset loaded correctly",3000);
}


void MainWindow::saveDataset(){

    if(repository==nullptr)return;

    general->refresh();
    breeding->refresh();
    boarding->refresh();

    repository->store();
    QMainWindow::statusBar()->showMessage("Dataset saved",3000);

}


void MainWindow::saveAsDataset(){
    QString path = QFileDialog::getSaveFileName(
            this,
            "Save as Dataset",
            "./",
            "JSON files *.json"
        );
        if (path.isEmpty() || repository == nullptr) {
            return;
        }

        repository->setPath(path.toStdString()).store();
        QMainWindow::statusBar()->showMessage("Dataset saved as\"" + path + "\".",3000);
}

