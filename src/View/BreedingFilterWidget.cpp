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
    QRadioButton* bull= new QRadioButton();
    QRadioButton* ams= new QRadioButton();
    QRadioButton* all= new QRadioButton();

    bre->addWidget(all);
    bre->addWidget(bull);
    bre->addWidget(ams);

    vbox->addWidget(br);
    vbox->addLayout(bre);

    all->setText("All");
    bull->setText("Bulldog");
    ams->setText("AmStaff");

    all->setChecked(true);



    vbox->addSpacing(30);


    //more features
    QCheckBox* opt= new QCheckBox();
    opt->setText("Options:");
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
    connect(opt,SIGNAL(clicked(bool)),vax,SLOT(setVisible(bool)));
    connect(opt,SIGNAL(clicked(bool)),booked,SLOT(setVisible(bool)));
    connect(opt,SIGNAL(clicked(bool)),purch,SLOT(setVisible(bool)));

    setLayout(vbox);
}
