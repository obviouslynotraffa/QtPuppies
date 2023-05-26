#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>

#include "doglist.h"
#include "BoardingPanel.h"

BoardingPanel::BoardingPanel(Container c, QWidget *parent)
    : QWidget{parent}, c(c)
{
    QVBoxLayout* vbox= new QVBoxLayout();
    vbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);

    //title
    QLabel* title= new QLabel("Boarding Dogs Search");
    vbox->addWidget(title);


    filter = new BoardingFilterWidget();


    QHBoxLayout* hbox= new QHBoxLayout();

    //left search area
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);

    spLeft.setHorizontalStretch(1);
    filter->setSizePolicy(spLeft);
    hbox->addWidget(filter);


    DogList* list= new DogList(c.filterBoarding());

    //right scroll area with only boarding dogs
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




    //panel
    QVBoxLayout* all= new QVBoxLayout;

    all->addLayout(vbox);
    all->addSpacing(-400);
    all->addLayout(hbox);

    setLayout(all);
}
