
#include <QPixmap>
#include "../breeding.h"
#include "../boarding.h"
#include "./breeds/bulldog.h"
#include "./breeds/amstaff.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QBoxLayout>
/*
QWidget* DogInfoVisitor::getWidget(){
    return widget;
}


void DogInfoVisitor::visitBoarding(Boarding& boarding){

    QHBoxLayout* box= new QHBoxLayout();
    QLabel* image= new QLabel(QPixmap(":/assets/icons8-dog-house-64.png"));
    image->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    box->addWidget(image);

    QVBoxLayout* info_box= new QVBoxLayout();

    QLabel* name= new QLabel();
    name->setText("Dog's name: "+QString(boarding.getName()));
    info_box->addWidget(name);

    QLabel* ow= new QLabel();
    ow->setText("Owner: "+QString(boarding.getOwner()));
    info_box->addWidget(ow);


    QHBoxLayout* opts= new QHBoxLayout();


    QLabel* bath=new QLabel("Bath");
    if(boarding.didBath())bath->setPixmap(":/assets/icons8-done-48.png");
    else bath->setPixmap(":/assets/icons8-close-48.png");
    opts->addWidget(bath);

    QLabel* walks=new QLabel("Walks");
    if(boarding.didWalking())walks->setPixmap(":/assets/icons8-done-48.png");
    else walks->setPixmap(":/assets/icons8-close-48.png");
    opts->addWidget(walks);

    QLabel* diet=new QLabel("Diet");
    if(boarding.didDiet())diet->setPixmap(":/assets/icons8-done-48.png");
    else diet->setPixmap(":/assets/icons8-close-48.png");
    opts->addWidget(diet);

    QLabel* tra=new QLabel("Training");
    if(boarding.didTraining())tra->setPixmap(":/assets/icons8-done-48.png");
    else tra->setPixmap(":/assets/icons8-close-48.png");
    opts->addWidget(tra);

    info_box->addLayout(opts);
    box->addLayout(info_box);
}

void DogInfoVisitor::visitBreeding(Breeding& breeding){

    QHBoxLayout* box= new QHBoxLayout();
    QLabel* image;
    Bulldog* b=dynamic_cast<Bulldog>(breeding.getBreed());
    if(b)
        image= new QLabel(QPixmap(":/assets/icons8-french-bulldog-64.png"));
    else
        image= new QLabel(QPixmap(":/assets/icons8-dog-64.png"));

    image->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
    box->addWidget(image);

    QVBoxLayout* info_box= new QVBoxLayout();

    QLabel* name= new QLabel();
    name->setText("Dog's name: "+QString(boarding.getName()));
    info_box->addWidget(name);

    QLabel* br= new QLabel();
    br->setText("Breed: "+b?"Bulldog":"AmStaff");
    info_box->addWidget(br);


    QHBoxLayout* opts= new QHBoxLayout();


    QLabel* booked=new QLabel("Booked");
    if(breeding.isBooked())booked->setPixmap(":/assets/icons8-done-48.png");
    else booked->setPixmap(":/assets/icons8-close-48.png");
    opts->addWidget(booked);

    QLabel* purch=new QLabel("Purchasable");
    if(breeding.isPurchasable())purch->setPixmap(":/assets/icons8-done-48.png");
    else purch->setPixmap(":/assets/icons8-close-48.png");
    opts->addWidget(purch);

    QLabel* vax=new QLabel("Vaxxed");
    if(breeding.isVax())vax->setPixmap(":/assets/icons8-done-48.png");
    else vax->setPixmap(":/assets/icons8-close-48.png");
    opts->addWidget(vax);



    info_box->addLayout(opts);
    box->addLayout(info_box);

}*/

