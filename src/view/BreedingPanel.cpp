#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>

#include "DogList.h"
#include "BreedingPanel.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"


BreedingPanel::BreedingPanel(Container c,QWidget *parent)
    :  QWidget{parent}, c(c)
{
    QVBoxLayout* vbox= new QVBoxLayout();
    vbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);

    //title
    QLabel* title= new QLabel("Breeding Dogs Search");
    vbox->addWidget(title);


    filter= new BreedingFilterWidget();

    QHBoxLayout* hbox= new QHBoxLayout();

    //left search area
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    filter->setSizePolicy(spLeft);
    hbox->addWidget(filter);


    list= new DogList();


    //right search area with only breed dog
    QScrollArea* scroll= new QScrollArea();
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(2);
    scroll->setSizePolicy(spRight);
    scroll->setWidgetResizable(true);
    scroll->setWidget(list);
    scroll->setFixedHeight(410);
    scroll->setFixedWidth(650);
    scroll->setAlignment(Qt::AlignTop);



    hbox->addWidget(scroll);
    hbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);



    //set up whole panel
    QVBoxLayout* all= new QVBoxLayout;

    all->addLayout(vbox);
    all->addSpacing(-400);
    all->addLayout(hbox);



    setLayout(all);

    //connect
    connect(filter, &BreedingFilterWidget::searchEvent, this, &BreedingPanel::search);
    connect(list, &DogList::signalDelete, this, &BreedingPanel::receiveDelete);

}


void BreedingPanel::search(QString s, QRadioButton* r, QCheckBox* vax, QCheckBox* booked, QCheckBox* purch ){

    Container aux=c;

    if(r->text()=="All")
    {
        if(vax->isChecked())c=c.filterVax();
        if(booked->isChecked())c=c.filterBooked();
        if(purch->isChecked())c=c.filterPurch();

        list->refresh(c.searchDog(s.toStdString()));

    }
    if(r->text()=="Bulldog"){

        if(vax->isChecked())c=c.filterVax();
        if(booked->isChecked())c=c.filterBooked();
        if(purch->isChecked())c=c.filterPurch();

        Bulldog bulldog;
        list->refresh(c.searchDog(s.toStdString()).filterBreed(&bulldog));
    }

    if(r->text()=="AmStaff"){

        if(vax->isChecked())c=c.filterVax();
        if(booked->isChecked())c=c.filterBooked();
        if(purch->isChecked())c=c.filterPurch();

        AmStaff amstaff;
        list->refresh(c.searchDog(s.toStdString()).filterBreed(&amstaff));
    }
    c=aux;

}



void BreedingPanel::setContainer(Container w){
    c=w;
}



void BreedingPanel::receiveDelete(Dog *d){
    emit signalDelete(d);
}





void BreedingPanel::refresh() const{

    list->refresh(c);

}
