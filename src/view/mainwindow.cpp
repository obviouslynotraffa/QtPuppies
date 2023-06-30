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

#include "mainwindow.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"

#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"

#include "Dog/owner.h"
#include "FinalButtonWidget.h"


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



    //set up container

    /*Large* large= new Large();
    Medium* medium= new Medium();
    Small* small= new Small();

    //AmStaff* amsatff= new AmStaff();
    //Bulldog* bulldog= new Bulldog();

    Owner* ow1= new Owner("Pino", "Daniele", "+39 65165132", 18, 5, 1999, "Piazza Garibaldi", "18");
    Owner* ow2= new Owner("Gennaro", "Bullo", "+39 3698547215", 11, 2, 1984, "Via Falcone Borsellino", "2");
    Owner* ow3= new Owner("Annalisa", "Di Maggio", "+39 3365214895", 31, 1, 1990, "Via XV Luglio", "30");
    Owner* ow4= new Owner("Pino", "Daniele", "+39 65165132", 1, 7, 1996, "Via Brombeis", "1");

    owners.push_back(ow1);
    owners.push_back(ow2);
    owners.push_back(ow3);
    owners.push_back(ow4);


    Boarding* guest1= new Boarding(20,4,2023,"Jack",medium,ow1,"Boxer",true, false, true, false);
    Boarding* guest2= new Boarding(20,4,2023,"Pablo",small,ow2,"Pinchir",false, true, false, true);
    Boarding* guest3= new Boarding(20,4,2023,"Zoe",large,ow3,"Cane-lupo cecoslovacco",false, false, false, false);
    Boarding* guest4= new Boarding(20,4,2023,"Maya",small,ow4,"Bassotto",true, true, false, true);


    Breeding* BulFather= new Breeding(19,11,2015, "Pepe", bulldog,true, false, false);
    Breeding* BulMother= new Breeding(5,8,2016, "Vik", bulldog,true, false, false);

    Breeding* Bulpuppie1= new Breeding(20,1,2023, "Bink", bulldog, true, false, true, BulMother, BulFather);
    Breeding* Bulpuppie2= new Breeding(20,1,2023, "Sip", bulldog, true, false, true, BulMother, BulFather);
    Breeding* Bulpuppie3= new Breeding(20,1,2023, "Zip", bulldog, true, true, true, BulMother, BulFather);
    Breeding* Bulpuppie4= new Breeding(20,1,2023, "Ettore", bulldog, true, false, true, BulMother, BulFather);


    Breeding* AmSFather= new Breeding(19,11,2015, "Orio",amsatff, true, false, false);
    Breeding* AmSMother= new Breeding(5,8,2016, "Nida", amsatff, true, false, false);

    Breeding* AmSpuppie1= new Breeding(13,8,2022, "Zil", amsatff, true, true, true ,AmSMother, AmSFather);
    Breeding* AmSpuppie2= new Breeding(13,8,2022, "Paky",amsatff, true, false, true,AmSMother, AmSFather);
    Breeding* AmSpuppie3= new Breeding(13,8,2022, "Chuck", amsatff, true, true, true, AmSMother, AmSFather);
    Breeding* AmSpuppie4= new Breeding(13,8,2022, "Bone", amsatff, true, false, true,AmSMother, AmSFather);


    c.push_back(BulFather);
    c.push_back(BulMother);
    c.push_back(AmSFather);
    c.push_back(AmSMother);

    c.push_back(AmSpuppie1);
    c.push_back(AmSpuppie2);
    c.push_back(AmSpuppie3);
    c.push_back(AmSpuppie4);

    c.push_back(Bulpuppie1);
    c.push_back(Bulpuppie2);
    c.push_back(Bulpuppie3);
    c.push_back(Bulpuppie4);


    c.push_back(guest1);
    c.push_back(guest2);
    c.push_back(guest3);
    c.push_back(guest4);*/


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
    general= new GeneralPanel(c);
    breeding= new BreedingPanel(c.filterBreeding());
    boarding= new BoardingPanel(c.filterBoarding());


    //Tab
    tab_widget= new QTabWidget();
    tab_widget->addTab(general,"General");
    tab_widget->addTab(breeding,"Breeding");
    tab_widget->addTab(boarding,"Boarding");
    setCentralWidget(tab_widget);



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
    window->hide();
}


void MainWindow::insertBoarding(Boarding* boardingDog){
    c=c.push_back(boardingDog);

    repository->create(boardingDog);
    repository->create(boardingDog->getOwner());

    general->setContainer(c);
    boarding->setContainer(c.filterBoarding());
    //breeding->setContainer(c.filterBreeding());

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
}


void MainWindow::removeDog(Dog *dog){
    c=c.erase(dog);
    general->setContainer(c);

    if(dynamic_cast<Breeding*>(dog))breeding->setContainer(c.filterBreeding());
    if(dynamic_cast<Boarding*>(dog))boarding->setContainer(c.filterBoarding());

    delete dog;
}


void MainWindow::toggleToolbar(){
    toolbar->setVisible(!toolbar->isVisible());
}


MainWindow& MainWindow::reloadData(){
    owners.clear();
    c.clearAll();
    std::vector<Owner*> owns (repository->readAllOwners());
    std::vector<Dog*> dogs (repository->readAllDogs());

    for (auto it= owns.begin();
         it!= owns.end();
         it++)
    {
        owners.push_back(*it);
    }


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
        delete repository;
    }


    Reader reader;
    Json converter(reader);

    JsonFile data_mapper(path.toStdString(),converter);
    repository =  new JsonRepo(data_mapper);

    owners.clear();
    c.clearAll();

    boardBtn->setEnabled(true);
    breedBtn->setEnabled(true);
    save->setEnabled(true);
    saveAs->setEnabled(true);

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

}


void MainWindow::saveDataset(){

    if(repository==nullptr)return;

    repository->store();

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
}

