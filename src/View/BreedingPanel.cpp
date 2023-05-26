#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>

#include "doglist.h"
#include "BreedingPanel.h"


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


    DogList* list= new DogList(c.filterBreeding());


    //right search area with only breed dog
    QScrollArea* scroll= new QScrollArea();
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(2);
    scroll->setSizePolicy(spRight);
    hbox->addWidget(scroll);
    hbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);


    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll->setWidgetResizable(true);
    scroll->setWidget(list);



    //set up whole panel
    QVBoxLayout* all= new QVBoxLayout;

    all->addLayout(vbox);
    all->addSpacing(-400);
    all->addLayout(hbox);



    setLayout(all);
}
