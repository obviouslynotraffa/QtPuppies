#include <QLabel>
#include <QGroupBox>


#include "DogVisitorInfoPanel.h"


QVBoxLayout* DogVisitorInfoPanel::getInfoPanel()const{
    return InfoPanel;
}


void DogVisitorInfoPanel::visitBoarding(Boarding &boarding){

    InfoPanel = new QVBoxLayout();


    QHBoxLayout* hbox= new QHBoxLayout();
    InfoPanel->addLayout(hbox);


    //--------Dog--------//

    QGroupBox* dogGroup= new QGroupBox(tr("Dog's info"));
    hbox->addWidget(dogGroup);

    QLabel* dogname= new QLabel("Name: " + QString::fromStdString(boarding.getName()));
    QLabel* dogdate= new QLabel("Arrival date: " +QString::fromStdString(boarding.getDate().toString()));
    QLabel* dogbreed= new QLabel("Breed: "+ QString::fromStdString(boarding.getBreed()));
    QLabel* dogsize= new QLabel("Size: ");


    //causa crash
    //QLabel* dogsize= new QLabel("Size: "+ QString::fromStdString(boarding.getSize()->toString()));


    //Optionals
    QLabel* dogoption= new QLabel("Optional serivices: ");

    QLabel* diet= new QLabel();
    QLabel* dietString= new QLabel("Diet");
    diet->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    if(boarding.didDiet()) diet->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else diet->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    QLabel* bath= new QLabel();
    bath->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    QLabel* bathString= new QLabel("Bath");
    if(boarding.didBath()) bath->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else bath->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    QLabel* walks= new QLabel();
    walks->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    QLabel* walksString= new QLabel("Walks");
    if(boarding.didWalking()) walks->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else walks->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    QLabel* training= new QLabel();
    training->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    QLabel* trainString= new QLabel("Training");
    if(boarding.didTraining()) training->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else training->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));




    //set up grid layout for dog
    QGridLayout* dogLayout= new QGridLayout;
    dogLayout->addWidget(dogname, 0,0);
    dogLayout->addWidget(dogdate, 1,0);
    dogLayout->addWidget(dogbreed, 2,0);
    dogLayout->addWidget(dogsize, 3,0);


    dogLayout->addWidget(dogoption, 4,0);

    dogLayout->addWidget(diet, 5,0);
    dogLayout->addWidget(dietString, 5,1);

    dogLayout->addWidget(bath, 6,0);
    dogLayout->addWidget(bathString, 6,1);

    dogLayout->addWidget(walks, 7,0);
    dogLayout->addWidget(walksString, 7,1);

    dogLayout->addWidget(training, 8,0);
    dogLayout->addWidget(trainString, 8,1);



    dogGroup->setLayout(dogLayout);



    //---------Owner-----------//
    QGroupBox* ownerBox= new QGroupBox(tr("Owner's info"));
    hbox->addWidget(ownerBox);

    Owner* ow=boarding.getOwner();

    //Name
    QLabel* owname= new QLabel("Name: "+QString::fromStdString(ow->getName())+ " " +QString::fromStdString(ow->getSurname()));
    QLabel* owdate= new QLabel("Day of birth: "+QString::fromStdString(ow->getBirthD().toString()));
    QLabel* number= new QLabel("Phone: " + QString::fromStdString(ow->getPhone()));
    QLabel* address= new QLabel("Address: " + QString::fromStdString(ow->getAddress())+ ", "+ QString::fromStdString(ow->getHouseNumber()));



    //set up owner layout
    QGridLayout* ownerLayout= new QGridLayout;
    ownerLayout->addWidget(owname, 0 ,0);
    ownerLayout->addWidget(owdate, 1 ,0);
    ownerLayout->addWidget(number, 2 ,0);
    ownerLayout->addWidget(address, 3 ,0);


    ownerBox->setLayout(ownerLayout);
}



void DogVisitorInfoPanel::visitBreeding(Breeding &breeding){


    InfoPanel = new QVBoxLayout();


    QHBoxLayout* hbox= new QHBoxLayout();
    InfoPanel->addLayout(hbox);



    //---------Dog---------//

    QGroupBox* dogGroup= new QGroupBox(tr("Dog's info"));
    hbox->addWidget(dogGroup);


    QLabel* dogname= new QLabel("Name: "+QString::fromStdString(breeding.getName()));
    QLabel* dogdate= new QLabel("Birthday: "+QString::fromStdString(breeding.getDate().toString()));
    QLabel* breedDog= new QLabel("Breed: ");

    //causa crash
    //QLabel* breedDog= new QLabel("Breed: "+ QString::fromStdString(breeding.getBreed()->toString()));



    //Optionals
    QLabel* dogoption= new QLabel("Details:");

    QLabel* vax= new QLabel();
    QLabel* vaxString= new QLabel("Vax");
    vax->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    if(breeding.isVax()) vax->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else vax->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));


    QLabel* purch= new QLabel();
    QLabel* purchString= new QLabel("Purchasable");
    purch->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    if(breeding.isPurchasable()) purch->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else purch->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    QLabel* booked= new QLabel();
    QLabel* bookedString= new QLabel("Booked");
    booked->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    if(breeding.isBooked()) booked->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else booked->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));



    //Set up layout
    QGridLayout* dogLayout= new QGridLayout;
    dogLayout->addWidget(dogname, 0,0);
    dogLayout->addWidget(dogdate, 1,0);
    dogLayout->addWidget(breedDog, 2,0);

    dogLayout->addWidget(dogoption, 4,0);

    dogLayout->addWidget(vax, 5,0);
    dogLayout->addWidget(vaxString, 5,1);

    dogLayout->addWidget(purch, 6,0);
    dogLayout->addWidget(purchString, 6,1);

    dogLayout->addWidget(booked, 7,0);
    dogLayout->addWidget(bookedString, 7,1);

    dogGroup->setLayout(dogLayout);



    //------Parents--------//
    QGroupBox* parentGroup= new QGroupBox(tr("Parent's info"));
    hbox->addWidget(parentGroup);


    //Mother
    QGroupBox* mom = new QGroupBox(tr("Mom"));
    QLabel* momName= new QLabel("Name: " + QString::fromStdString(breeding.getMother()->getName()));
    QLabel* momDate= new QLabel("Birthday: " + QString::fromStdString(breeding.getMother()->getDate().toString()));
    QLabel* momBreed = new QLabel("Breed: ");

    QGridLayout* momLayout= new QGridLayout;
    momLayout->addWidget(momName,0,0,1,50);
    momLayout->addWidget(momDate,1,0,1,50);
    momLayout->addWidget(momBreed,2,0,1,50);
    mom->setLayout(momLayout);


    //Father
    QGroupBox* dad = new QGroupBox(tr("Dad"));
    QLabel* dadName= new QLabel("Name: " + QString::fromStdString(breeding.getFather()->getName()));
    QLabel* dadDate= new QLabel("Birthday: " + QString::fromStdString(breeding.getFather()->getDate().toString()));
    QLabel* dadBreed = new QLabel("Breed: ");

    QGridLayout* dadLayout= new QGridLayout;
    dadLayout->addWidget(dadName,0,0);
    dadLayout->addWidget(dadDate,1,0);
    dadLayout->addWidget(dadBreed,2,0);
    dad->setLayout(dadLayout);

    //set up parent layout
    QGridLayout* parentLayout= new QGridLayout;
    parentLayout->addWidget(mom,0,0);
    parentLayout->addWidget(dad,1,0);

    parentGroup->setLayout(parentLayout);

}
