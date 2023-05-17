#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QSizePolicy>


#include "DogVisitorCard.h"
#include "Dog/owner.h"

#include "Breeds/breed.h"
#include "Breeds/amstaff.h"
#include "Breeds/bulldog.h"



QVBoxLayout* DogVisitorCard::getCard() const{
    return cardLayout;
}

void DogVisitorCard::visitBoarding(Boarding &boarding) {

    QHBoxLayout* hbox=new QHBoxLayout();

    hbox->addSpacing(30);

    //left image
    QHBoxLayout* img= new QHBoxLayout();
    QLabel* image= new QLabel();
    image->setPixmap(QPixmap(":/assets/icons8-dog-house-64.png"));
    image->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    img->addWidget(image);
    hbox->addLayout(img);


    hbox->addSpacing(25);


    //Dog's info
    QVBoxLayout* info= new QVBoxLayout();
    hbox->addLayout(info);
    info->setAlignment(Qt::AlignCenter);



    //name
    QLabel* name= new QLabel("Name: "+ QString::fromStdString(boarding.getName()));
    info->addWidget(name);

    //date
    std::string d=std::to_string(boarding.getDate().getDay());
    std::string m=std::to_string(boarding.getDate().getMonth());
    std::string y=std::to_string(boarding.getDate().getYear());
    std::string date_string = d + "/" + m + "/" + y ;

    QLabel* date= new QLabel("Arrival date: "+ QString::fromStdString(date_string));
    info->addWidget(date);

    //Owner
    Owner* owner=boarding.getOwner();
    std::string OwnerName=owner->getName();
    std::string OwnerSurname=owner->getSurname();
    QLabel* ownerString= new QLabel("Owner: " + QString::fromStdString(OwnerName + " " + OwnerSurname));
    info->addWidget(ownerString);


    //Optional services
    QLabel* optionalService= new QLabel("Optional services: ");
    info->addWidget(optionalService);


    QHBoxLayout* srvc= new QHBoxLayout();
    info->addLayout(srvc);


    //Bath
    QLabel* bath= new QLabel();
    QLabel* bathString= new QLabel("Bath");
    bath->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    if (boarding.didBath())
        bath->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        bath->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    srvc->addWidget(bath);
    srvc->addWidget(bathString);


    //Diet
    QLabel* diet= new QLabel();
    QLabel* dietString= new QLabel("Diet");
    diet->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    if (boarding.didDiet())
        diet->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        diet->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    srvc->addWidget(diet);
    srvc->addWidget(dietString);


    //Trainings
    QLabel* trainings= new QLabel();
    QLabel* trainString= new QLabel("Trainings");
    trainings->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    if (boarding.didTraining())
        trainings->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        trainings->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    srvc->addWidget(trainings);
    srvc->addWidget(trainString);


    //Walks
    QLabel* walks= new QLabel();
    QLabel* walksString= new QLabel("Walks");
    walks->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    if (boarding.didWalking())
        walks->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        walks->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    srvc->addWidget(walks);
    srvc->addWidget(walksString);

    hbox->addStretch();


    //End line
    QFrame* line= new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);


    //put all things togheter
    cardLayout= new QVBoxLayout();
    cardLayout->addLayout(hbox);
    cardLayout->addWidget(line);

}




void DogVisitorCard::visitBreeding(Breeding &breeding) {

    QHBoxLayout* hbox=new QHBoxLayout();

    hbox->addSpacing(30);

    //left image
    QHBoxLayout* img= new QHBoxLayout();
    QLabel* image= new QLabel();

    Breed* bulldogPointer=breeding.getBreed();


    if(dynamic_cast<Bulldog*>(bulldogPointer))
        image->setPixmap(QPixmap(":/assets/icons8-french-bulldog-64.png"));
    else
        image->setPixmap(QPixmap(":/assets/icons8-dog-64.png"));


    image->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    img->addWidget(image);
    hbox->addLayout(img);


    hbox->addSpacing(25);


    //Dog's info
    QVBoxLayout* info= new QVBoxLayout();
    hbox->addLayout(info);
    info->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);


    //name
    QLabel* name= new QLabel("Name: "+ QString::fromStdString(breeding.getName()));
    info->addWidget(name);

    //date
    std::string d=std::to_string(breeding.getDate().getDay());
    std::string m=std::to_string(breeding.getDate().getMonth());
    std::string y=std::to_string(breeding.getDate().getYear());
    std::string date_string = d + "/" + m + "/" + y ;

    QLabel* date= new QLabel("Day of birth: "+ QString::fromStdString(date_string));
    info->addWidget(date);

    //Breed
    QLabel* breed= new QLabel("Breed: "+QString::fromStdString(breeding.getBreed()->toString()));
    info->addWidget(breed);


    //Optional services
    QLabel* options= new QLabel("Options: ");
    info->addWidget(options);


    QHBoxLayout* opt= new QHBoxLayout();
    info->addLayout(opt);


    //Vax
    QLabel* vax= new QLabel();
    QLabel* vaxString= new QLabel("Vaxxed");
    vax->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    if (breeding.isVax())
        vax->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        vax->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    opt->addWidget(vax);
    opt->addWidget(vaxString);


    //Purchasable
    QLabel* purch= new QLabel();
    QLabel* purchString= new QLabel("Purchasable");
    purch->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    if (breeding.isPurchasable())
        purch->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        purch->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    opt->addWidget(purch);
    opt->addWidget(purchString);


    //Booked
    QLabel* booked= new QLabel();
    QLabel* bookedString= new QLabel("Booked");
    booked->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    if (breeding.isBooked())
        booked->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
    else
        booked->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));

    opt->addWidget(booked);
    opt->addWidget(bookedString);


    hbox->addStretch();

    //End line
    QFrame* line= new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);


    //put all things togheter
    cardLayout= new QVBoxLayout();
    cardLayout->addLayout(hbox);
    cardLayout->addWidget(line);


}
