#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>

#include "BreedingFilterWidget.h"


BreedingFilterWidget::BreedingFilterWidget(QWidget *parent)
    : QWidget{parent}
{


    QVBoxLayout* vbox= new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);



    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    //setup search bar
    QLabel* searchbar= new QLabel();
    searchbar->setText("Search Bar");


    QHBoxLayout* hbox= new QHBoxLayout();
    filterString= new QLineEdit();
    filterString->setPlaceholderText("Dog's name");

    QPushButton* search_button = new QPushButton(QPixmap((":/assets/icons8-search-48.png")),"");
    search_button->setIconSize(QSize(25,25));
    vbox->addWidget(searchbar);
    hbox->addWidget(filterString);
    hbox->addWidget(search_button);
    vbox->addLayout(hbox);


    vbox->addSpacing(30);


    //filter by breed
    QLabel* br= new QLabel();
    br->setText("Breeds:");

    QHBoxLayout* bre= new QHBoxLayout();
    bull= new QRadioButton();
    ams= new QRadioButton();
    all= new QRadioButton();

    bre->addWidget(all);
    bre->addWidget(bull);
    bre->addWidget(ams);

    vbox->addWidget(br);
    vbox->addLayout(bre);

    all->setText("All");
    bull->setText("Bulldog");
    ams->setText("AmStaff");

    all->setChecked(true);
    breedChose=all;
    breedChose->setText("All");


    vbox->addSpacing(30);


    //more features
    QPushButton* opt= new QPushButton();
    opt->setFlat(true);
    opt->setText("More options:");
    vbox->addWidget(opt);

    vax = new  QCheckBox();
    vax->setText("Vaccinated");
    vax->setVisible(false);

    booked = new  QCheckBox();
    booked->setText("Booked");
    booked->setVisible(false);

    purch = new  QCheckBox();
    purch->setText("Purchasable");
    purch->setVisible(false);

    vbox->addWidget(opt);
    vbox->addWidget(vax);
    vbox->addWidget(booked);
    vbox->addWidget(purch);


    //connect signals
    connect(all, &QRadioButton::pressed, this , &BreedingFilterWidget::searchAll);
    connect(bull, &QRadioButton::pressed, this , &BreedingFilterWidget::searchBulldog);
    connect(ams, &QRadioButton::pressed, this , &BreedingFilterWidget::searchAmstaff);
    connect(opt, &QPushButton::released, this, &BreedingFilterWidget::untoggleOptions);
    connect(search_button, &QPushButton::released, this, &BreedingFilterWidget::searchPressed);

    setLayout(vbox);
}


void BreedingFilterWidget::searchAll(){
    breedChose=all;
    breedChose->setText("All");
}


void BreedingFilterWidget::searchBulldog(){
    breedChose=bull;
    breedChose->setText("Bulldog");
}

void BreedingFilterWidget::searchAmstaff(){
    breedChose=ams;
    breedChose->setText("AmStaff");
}


void BreedingFilterWidget::searchPressed(){
    emit searchEvent(filterString->text(), breedChose, vax, booked, purch);
}



void BreedingFilterWidget::untoggleOptions(){
    vax->setVisible(!vax->isVisible());
    purch->setVisible(!purch->isVisible());
    booked->setVisible(!booked->isVisible());

    if(!vax->isVisible())vax->setChecked(false);
    if(!purch->isVisible())purch->setChecked(false);
    if(!booked->isVisible())booked->setChecked(false);

}
