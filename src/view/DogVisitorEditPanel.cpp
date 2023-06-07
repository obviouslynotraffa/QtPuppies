#include <QLabel>
#include <QLineEdit>
#include <QFrame>
#include <QGroupBox>
#include <QGridLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>

#include "DogVisitorEditPanel.h"
#include "FinalButtonWidget.h"

#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"




QVBoxLayout* DogVisitorEditPanel::getEditPanel()const{
    return editPanel;
}






void DogVisitorEditPanel::visitBoarding(Boarding &boarding){

    editPanel= new QVBoxLayout;

    QHBoxLayout* hbox= new QHBoxLayout();
    editPanel->addLayout(hbox);


    //--------Dog--------//

    QGroupBox* dogGroup= new QGroupBox(tr("Dog's info"));
    hbox->addWidget(dogGroup);

    //Name
    QLabel* dogname= new QLabel("Name: ");
    QLineEdit* nameEdit= new QLineEdit;
    nameEdit->setText(QString::fromStdString(boarding.getName()));
    nameEdit->setFixedWidth(150);


    //Date
    QLabel* dogdate= new QLabel("Arrival date: ");
    QLineEdit* dateEdit= new QLineEdit;
    dateEdit->setText(QString::fromStdString(boarding.getDate().toString()));
    dateEdit->setFixedWidth(150);


    //Breed
    QLabel* dogbreed= new QLabel("Breed: ");
    QLineEdit* breedEdit= new QLineEdit;
    breedEdit->setText(QString::fromStdString(boarding.getBreed()));
    breedEdit->setFixedWidth(150);


    //Size
    QLabel* dogsize= new QLabel("Size: ");
    QComboBox* sizeEdit= new QComboBox;
    sizeEdit->setFixedWidth(150);
    sizeEdit->addItem(tr("Large"));
    sizeEdit->addItem(tr("Medium"));
    sizeEdit->addItem(tr("Small"));


    if(dynamic_cast<Large*>(boarding.getSize()))
        sizeEdit->setCurrentIndex(0);

    if(dynamic_cast<Medium*>(boarding.getSize()))
        sizeEdit->setCurrentIndex(1);

    if(dynamic_cast<Small*>(boarding.getSize()))
        sizeEdit->setCurrentIndex(2);



    //Optionals
    QLabel* dogoption= new QLabel("Optional serivces");
    QCheckBox* bath= new QCheckBox(QString("Bath"));
    QCheckBox* walks= new QCheckBox(QString("Walks"));
    QCheckBox* diet= new QCheckBox(QString("Diet"));
    QCheckBox* training= new QCheckBox(QString("Trainings"));

    if(boarding.didBath()) bath->setChecked(true);
    if(boarding.didWalking()) walks->setChecked(true);
    if(boarding.didDiet()) diet->setChecked(true);
    if(boarding.didTraining()) training->setChecked(true);



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

    Owner* ow=boarding.getOwner();

    //Name
    QLabel* owname= new QLabel("Name: ");
    QLineEdit* ownameEdit= new QLineEdit;
    ownameEdit->setText(QString::fromStdString(ow->getName()));
    ownameEdit->setFixedWidth(150);

    //Surname
    QLabel* owsurname= new QLabel("Surname: ");
    QLineEdit* surnameEdit= new QLineEdit;
    surnameEdit->setText(QString::fromStdString(ow->getSurname()));
    surnameEdit->setFixedWidth(150);

    //Date
    QLabel* owdate= new QLabel("Day of birth: ");
    QLineEdit* owdateEdit= new QLineEdit;
    owdateEdit->setText(QString::fromStdString(ow->getBirthD().toString()));
    owdateEdit->setFixedWidth(150);

    //Phone number
    QLabel* number= new QLabel("Phone: ");
    QLineEdit* numberEdit= new QLineEdit;
    numberEdit->setText(QString::fromStdString(ow->getPhone()));
    numberEdit->setFixedWidth(150);


    //Addres
    QLabel* address= new QLabel("Address: ");
    QLineEdit* addressEdit= new QLineEdit;
    addressEdit->setText(QString::fromStdString(ow->getAddress()));
    addressEdit->setFixedWidth(150);


    //House number
    QLabel* hn= new QLabel("House's number: ");
    QLineEdit* hnEdit= new QLineEdit;
    hnEdit->setText(QString::fromStdString(ow->getHouseNumber()));
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

    FinalButtonWidget* btn= new FinalButtonWidget(&boarding, nameEdit, dateEdit, breedEdit, sizeEdit,bath, walks, diet, training,
                                                  ownameEdit, surnameEdit, owdateEdit, numberEdit, addressEdit, hnEdit);
    editPanel->addWidget(btn);

}







void DogVisitorEditPanel::visitBreeding(Breeding &breeding){

    editPanel= new QVBoxLayout;

    QHBoxLayout* hbox= new QHBoxLayout();
    editPanel->addLayout(hbox);



    //---------Dog---------//

    QGroupBox* dogGroup= new QGroupBox(tr("Dog's info"));
    hbox->addWidget(dogGroup);

    //Name
    QLabel* dogname= new QLabel("Name: ");
    QLineEdit* nameEdit= new QLineEdit;
    nameEdit->setText(QString::fromStdString(breeding.getName()));
    nameEdit->setFixedWidth(150);


    //Date
    QLabel* dogdate= new QLabel("Birthday: ");
    QLineEdit* dateEdit= new QLineEdit;
    dateEdit->setText(QString::fromStdString(breeding.getDate().toString()));
    dateEdit->setFixedWidth(150);


    //Breed
    QLabel* breedDog= new QLabel("Breed: ");
    QComboBox* breedEdit= new QComboBox;
    breedEdit->setFixedWidth(150);
    breedEdit->addItem(tr("AmStaff"));
    breedEdit->addItem(tr("Bulldog"));

    if(dynamic_cast<AmStaff*>(breeding.getBreed()))
        breedEdit->setCurrentIndex(0);
    if(dynamic_cast<Bulldog*>(breeding.getBreed()))
        breedEdit->setCurrentIndex(1);


    //Optionals
    QLabel* dogoption= new QLabel("Options: ");
    QCheckBox* vax= new QCheckBox(QString("Vaxxed"));
    QCheckBox* purch= new QCheckBox(QString("Purchasable"));
    QCheckBox* booked= new QCheckBox(QString("Booked"));

    if(breeding.isVax()) vax->setChecked(true);
    if(breeding.isPurchasable()) purch->setChecked(true);
    if(breeding.isBooked()) booked->setChecked(true);


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


    if(breeding.getFather() && breeding.getMother()){
        //Mother
        QGroupBox* mom = new QGroupBox(tr("Mom"));

        QLabel* mother= new QLabel("Select mother: ");
        QComboBox* listmom= new QComboBox;
        listmom->addItem(QString::fromStdString(breeding.getMother()->getName()));

        QGridLayout* momLayout= new QGridLayout;

        momLayout->addWidget(mother,0,0);
        momLayout->addWidget(listmom,0,1);
        mom->setLayout(momLayout);


        //Father
        QGroupBox* dad = new QGroupBox(tr("Dad"));
        QLabel* father= new QLabel("Select father: ");
        QComboBox* listdad= new QComboBox;
        listdad->addItem(QString::fromStdString(breeding.getFather()->getName()));


        QGridLayout* dadLayout= new QGridLayout;

        dadLayout->addWidget(father,0,0);
        dadLayout->addWidget(listdad,0,1);

        dad->setLayout(dadLayout);

        //set up parent layout
        QGridLayout* parentLayout= new QGridLayout;
        parentLayout->addWidget(mom,0,0,1,10);
        parentLayout->addWidget(dad,1,0,1,10);

        parentGroup->setLayout(parentLayout);
    }
    else{  //show no data
            QLabel* noParents= new QLabel("No parental data available");
            QVBoxLayout* vbox= new QVBoxLayout;
            vbox->addWidget(noParents);
            vbox->setAlignment(Qt::AlignCenter);
            parentGroup->setLayout(vbox);
        }


    //save button
    FinalButtonWidget* btn= new FinalButtonWidget(&breeding, nameEdit, dateEdit, breedEdit, vax, purch, booked);
    editPanel->addWidget(btn);



}



