#include "dogcard.h"
#include "../Dog/breeding.h"
#include "../Dog/boarding.h"
#include "../sizes/size.h"
#include "../breeds/breed.h"
#include "../breeds/amstaff.h"
#include "../breeds/bulldog.h"
#include "../Dog/owner.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <string>
#include <QPushButton>
#include <QIcon>
#include <QFrame>

DogCard::DogCard(Dog* dog, QWidget *parent)
    : QWidget(parent), dog(dog)
{
    if(dog){
    Breeding* isBreeding=dynamic_cast<Breeding*>(dog);



    //image
    QHBoxLayout* hbox= new QHBoxLayout();
    QLabel* image= new QLabel("");
    hbox->addWidget(image);
    if(!isBreeding)
        image->setPixmap(QPixmap(":/assets/icons8-dog-house-64.png"));
    else
    {
      Breeding* ff = static_cast<Breeding*>(dog);
      Breed* bb= ff->getBreed();
      if(dynamic_cast<Bulldog*>(bb))
          image->setPixmap(QPixmap(":/assets/icons8-french-bulldog-64.png"));
      else
          image->setPixmap(QPixmap(":/assets/icons8-dog-64.png"));
    }
    image->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    /*QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    image->setSizePolicy(spLeft);*/

    QVBoxLayout* info= new QVBoxLayout();
    hbox->addSpacing(-270);

    //name
    QLabel* name= new QLabel("Name: "+ QString::fromStdString(dog->getName()));

    //date
    std::string d=std::to_string(dog->getDate().getDay());
    std::string m=std::to_string(dog->getDate().getMonth());
    std::string y=std::to_string(dog->getDate().getYear());
    std::string date_string = d + "/" + m + "/" + y ;



    QLabel* date;
    if(!isBreeding)
        date= new QLabel("Arrival date: "+ QString::fromStdString(date_string));
    else
        date= new QLabel("Day of birth: "+ QString::fromStdString(date_string));



    //owner/breed
    QLabel* ob;
    if(isBreeding)
    {
        Breeding* a=static_cast<Breeding*>(dog);
        Breed* bb=a->getBreed();
        ob=new QLabel("Breed: "+QString::fromStdString(bb->toString()));
    }
    else
    {
        Boarding* a=static_cast<Boarding*>(dog);
        Owner* bb=a->getOwner();
        std::string n=bb->getName();
        std::string s=bb->getSurname();
        std::string no = n + " " +s ;
        ob= new QLabel("Owner: " + QString::fromStdString(no));
    }


    QLabel* options= new QLabel("Options: ");



    //options
    QHBoxLayout* opts= new QHBoxLayout();
    QLabel* op1;
    QLabel* op2;
    QLabel* op3;
    QLabel* op4;
    QLabel* l1;
    QLabel* l2;
    QLabel* l3;
    QLabel* l4;

    if(isBreeding){
        Breeding* f=static_cast<Breeding*>(dog);

        op1= new QLabel("Vaxxed");
        if(f->isVax())
            op1->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
        else
            op1->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));
        l1=new QLabel("Vaxxed");
        op1->setAlignment(Qt::AlignRight|Qt::AlignCenter);


        op2= new QLabel("Purchasable");
        if(f->isPurchasable())
            op2->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
        else
            op2->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));
        l2=new QLabel("Purchasable");
        op2->setAlignment(Qt::AlignRight|Qt::AlignCenter);


        op3= new QLabel("Booked");
        if(f->isBooked())
            op3->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
        else
            op3->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));
        l3=new QLabel("Booked");
        op3->setAlignment(Qt::AlignRight|Qt::AlignCenter);


        op4= new QLabel("");
        l4=new QLabel("");

    }else{
        Boarding* f=static_cast<Boarding*>(dog);

        op1= new QLabel("Bath");
        if(f->didBath())
            op1->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
        else
            op1->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));
        l1=new QLabel("Bath");
        op1->setAlignment(Qt::AlignRight|Qt::AlignCenter);


        op2= new QLabel("Diet");
        if(f->didDiet())
            op2->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
        else
            op2->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));
        l2=new QLabel("Diet");
        op2->setAlignment(Qt::AlignRight|Qt::AlignCenter);


        op3= new QLabel("Trainings");
        if(f->didTraining())
            op3->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
        else
            op3->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));
        l3=new QLabel("Trainings");
        op3->setAlignment(Qt::AlignRight|Qt::AlignCenter);


        op4= new QLabel("Walks");
        if(f->didWalking())
            op4->setPixmap(QPixmap(":/assets/icons8-done-48.png").scaled(10,10,Qt::KeepAspectRatio));
        else
            op4->setPixmap(QPixmap(":/assets/icons8-close-48.png").scaled(10,10,Qt::KeepAspectRatio));
        l4=new QLabel("Walks");
        op4->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    }




    info->addWidget(name);
    info->addWidget(date);
    info->addWidget(ob);
    info->addWidget(options);
    info->addLayout(opts);


    opts->addWidget(op1);
    opts->addWidget(l1);
    opts->addWidget(op2);
    opts->addWidget(l2);
    opts->addWidget(op3);
    opts->addWidget(l3);
    opts->addWidget(op4);
    opts->addWidget(l4);

    hbox->addLayout(info);
    hbox->addSpacing(25);


    /*
     * Button to fix
     *
    QVBoxLayout * bts= new QVBoxLayout();
    hbox->addLayout(bts);

    QPushButton* edit= new QPushButton();
    edit->setIcon(QIcon(":/assets/icons8-edit-48.png"));
    edit->setIconSize(QSize(26,26));
    edit->setFixedSize(QSize(26,26));
    bts->addWidget(edit);
    edit->setStyleSheet(QString("QPushButton {border: 0px;}"));

    QPushButton* view= new QPushButton();
    view->setIcon(QIcon(":/assets/icons8-view-more-48.png"));
    view->setIconSize(QSize(30,30));
    view->setFixedSize(QSize(30,30));
    bts->addWidget(view);
    view->setStyleSheet(QString("QPushButton {border: 0px;}"));

    QPushButton* release= new QPushButton();
    release->setIcon(QIcon(":/assets/icons8-dog-collar-64.png"));
    release->setIconSize(QSize(30,30));
    release->setFixedSize(QSize(30,30));
    bts->addWidget(release);
    release->setStyleSheet(QString("QPushButton {border: 0px;}"));
    */

    QVBoxLayout* all= new QVBoxLayout();
    all->addLayout(hbox);
    QFrame* line= new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    all->addWidget(line);

    setLayout(all);
    }
}
