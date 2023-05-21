#include <QLabel>

#include "DogVisitorInfoPanel.h"


QVBoxLayout* DogVisitorInfoPanel::getInfoPanel()const{
    return InfoPanel;
}


void DogVisitorInfoPanel::visitBoarding(Boarding &boarding){

    InfoPanel = new QVBoxLayout();


    //Title section
    QHBoxLayout* title= new QHBoxLayout();
    InfoPanel->addLayout(title);


    QLabel* titleLeft= new QLabel("Dog's details");
    titleLeft->setAlignment(Qt::AlignCenter);
    titleLeft->setFrameStyle(QFrame::Box|QFrame::Sunken);
    title->addWidget(titleLeft);

    QLabel* titleRight= new QLabel("Owner's details");
    titleRight->setAlignment(Qt::AlignCenter);
    titleRight->setFrameStyle(QFrame::Box|QFrame::Sunken);
    title->addWidget(titleRight);



    //Dog's info
    QHBoxLayout* infoBox= new QHBoxLayout;
    InfoPanel->addLayout(infoBox);


    //Left side with dog's info
    QVBoxLayout* leftInfo= new QVBoxLayout();
    infoBox->addLayout(leftInfo);
    leftInfo->setAlignment(Qt::AlignTop|Qt::AlignLeft);


    QLabel* nameDog= new QLabel("Name: " + QString::fromStdString(boarding.getName()));
    leftInfo->addWidget(nameDog);


    QLabel* date= new QLabel("Arrival date: " + QString::fromStdString(boarding.getDate().toString()));
    leftInfo->addWidget(date);

    QLabel* breed;
    if(boarding.getBreed()!="")
        breed= new QLabel("Breed: "+ QString::fromStdString(boarding.getBreed()));
    else
        breed= new QLabel("Breed: not defined");

    leftInfo->addWidget(breed);

    QLabel* size= new QLabel("Size: ");
    leftInfo->addWidget(size);

    leftInfo->addSpacing(15);


    //Optional services
    QLabel* services= new QLabel("Services: ");
    leftInfo->addWidget(services);


    //Bath
    QHBoxLayout* bathBox= new QHBoxLayout();
    leftInfo->addLayout(bathBox);

    QLabel* bath= new QLabel();
    QLabel* bathString= new QLabel("Bath");
    bath->setAlignment(Qt::AlignRight);

    if (boarding.didBath())
        bath->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        bath->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    bathBox->addWidget(bath);
    bathBox->addWidget(bathString);


    //Diet
    QHBoxLayout* dietBox= new QHBoxLayout();
    leftInfo->addLayout(dietBox);

    QLabel* diet= new QLabel();
    QLabel* dietString= new QLabel("Diet");
    diet->setAlignment(Qt::AlignRight);

    if (boarding.didDiet())
        diet->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        diet->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    dietBox->addWidget(diet);
    dietBox->addWidget(dietString);


    //Trainings
    QHBoxLayout* trainBox= new QHBoxLayout();
    leftInfo->addLayout(trainBox);

    QLabel* trainings= new QLabel();
    QLabel* trainString= new QLabel("Trainings");
    trainings->setAlignment(Qt::AlignRight);

    if (boarding.didTraining())
        trainings->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        trainings->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    trainBox->addWidget(trainings);
    trainBox->addWidget(trainString);


    //Walks
    QHBoxLayout* walksBox= new QHBoxLayout();
    leftInfo->addLayout(walksBox);

    QLabel* walks= new QLabel();
    QLabel* walksString= new QLabel("Walks");
    walks->setAlignment(Qt::AlignRight);

    if (boarding.didWalking())
        walks->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        walks->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    walksBox->addWidget(walks);
    walksBox->addWidget(walksString);

    //Middle line
    QFrame* line= new QFrame;
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    infoBox->addWidget(line);


    //Right side with owner's info
    QVBoxLayout* rightInfo= new QVBoxLayout();
    infoBox->addLayout(rightInfo);
    rightInfo->setAlignment(Qt::AlignTop|Qt::AlignLeft);

    QLabel* ownerName= new QLabel("Name: "+ QString::fromStdString(boarding.getOwner()->getName())
                                  + " " +QString::fromStdString(boarding.getOwner()->getSurname()));

    rightInfo->addWidget(ownerName);

    QLabel* birth= new QLabel("Day of birth: "+QString::fromStdString(boarding.getOwner()->getBirthD().toString()));
    rightInfo->addWidget(birth);

    QLabel* phone= new QLabel("Phone number: "+ QString::fromStdString(boarding.getOwner()->getPhone()));
    rightInfo->addWidget(phone);


    QLabel* address= new QLabel("Address: " + QString::fromStdString(boarding.getOwner()->getAddress()+ ", "
                                                                     +boarding.getOwner()->getHouseNumber()));
    rightInfo->addWidget(address);

    InfoPanel->addStretch();
}



void DogVisitorInfoPanel::visitBreeding(Breeding &breeding){


    InfoPanel = new QVBoxLayout();

    InfoPanel->addStretch();


    //Title section
    QHBoxLayout* title= new QHBoxLayout();
    InfoPanel->addLayout(title);


    QLabel* titleLeft= new QLabel("Dog's details");
    titleLeft->setAlignment(Qt::AlignCenter);
    titleLeft->setFrameStyle(QFrame::Box|QFrame::Sunken);
    title->addWidget(titleLeft);

    QLabel* titleRight= new QLabel("Parent's details");
    titleRight->setAlignment(Qt::AlignCenter);
    titleRight->setFrameStyle(QFrame::Box|QFrame::Sunken);
    title->addWidget(titleRight);



    //Dog's info
    QHBoxLayout* infoBox= new QHBoxLayout;
    InfoPanel->addLayout(infoBox);


    //Left side with dog's info
    QVBoxLayout* leftInfo= new QVBoxLayout();
    infoBox->addLayout(leftInfo);
    leftInfo->setAlignment(Qt::AlignTop|Qt::AlignLeft);


    QLabel* nameDog= new QLabel("Name: " + QString::fromStdString(breeding.getName()));
    leftInfo->addWidget(nameDog);


    QLabel* date= new QLabel("Day of birth : " + QString::fromStdString(breeding.getDate().toString()));
    leftInfo->addWidget(date);

    QLabel* breed= new QLabel("Breed: ");
    leftInfo->addWidget(breed);


    leftInfo->addSpacing(15);


    //Options
    QLabel* opt= new QLabel("Options: ");
    leftInfo->addWidget(opt);


    //Vax
    QHBoxLayout* vaxBox= new QHBoxLayout();
    leftInfo->addLayout(vaxBox);

    QLabel* vax= new QLabel();
    QLabel* vaxString= new QLabel("Vaxxed");
    vax->setAlignment(Qt::AlignRight);

    if (breeding.isVax())
        vax->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        vax->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    vaxBox->addWidget(vax);
    vaxBox->addWidget(vaxString);


    //Booked
    QHBoxLayout* bookedBox= new QHBoxLayout();
    leftInfo->addLayout(bookedBox);

    QLabel* booked= new QLabel();
    QLabel* bookedString= new QLabel("Booked");
    booked->setAlignment(Qt::AlignRight);

    if (breeding.isBooked())
        booked->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        booked->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    bookedBox->addWidget(booked);
    bookedBox->addWidget(bookedString);


    //Purchasable
    QHBoxLayout* purchBox= new QHBoxLayout();
    leftInfo->addLayout(purchBox);

    QLabel* purchase= new QLabel();
    QLabel* purchaseString= new QLabel("Purchasable");
    purchase->setAlignment(Qt::AlignRight);

    if (breeding.isPurchasable())
        purchase->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        purchase->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    purchBox->addWidget(purchase);
    purchBox->addWidget(purchaseString);



    //Middle line
    QFrame* line= new QFrame;
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    infoBox->addWidget(line);


    //Right side with owner's info
    QVBoxLayout* rightInfo= new QVBoxLayout();
    infoBox->addLayout(rightInfo);



    if(breeding.getFather() && breeding.getMother()){


        //Mother
        QLabel* titleMother= new QLabel("Mom");
        titleMother->setAlignment(Qt::AlignHCenter);
        rightInfo->addWidget(titleMother);


        QLabel* motherName= new QLabel("Name: "+ QString::fromStdString(breeding.getMother()->getName()));
        rightInfo->addWidget(motherName);

        QLabel* motherBreed= new QLabel("Breed: ");
        rightInfo->addWidget(motherBreed);

        QLabel* motherDate= new QLabel("Day of birth: "+ QString::fromStdString(breeding.getMother()->getDate().toString()));
        rightInfo->addWidget(motherDate);



        rightInfo->addStretch();

        //Line
        QFrame* line= new QFrame;
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        rightInfo->addWidget(line);

        rightInfo->addStretch();


        //Dad
        QLabel* titleFather= new QLabel("Dad");
        titleFather->setAlignment(Qt::AlignHCenter);
        rightInfo->addWidget(titleFather);

        QLabel* fatherName= new QLabel("Name: "+ QString::fromStdString(breeding.getFather()->getName()));
        rightInfo->addWidget(fatherName);

        QLabel* fatherBreed= new QLabel("Breed: ");
        rightInfo->addWidget(fatherBreed);

        QLabel* fatherDate= new QLabel("Day of birth: "+ QString::fromStdString(breeding.getFather()->getDate().toString()));
        rightInfo->addWidget(fatherDate);



    } else{
        QLabel* noParents= new QLabel("No data avaiable");
        rightInfo->addWidget(noParents);
        noParents->setAlignment(Qt::AlignCenter);
    }

    InfoPanel->addStretch();

}
