#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QScrollArea>

#include "GeneralPanel.h"
#include "doglist.h"


GeneralPanel::GeneralPanel(Container c,QWidget* parent)
    :  QWidget{parent}, c(c)
{

    QVBoxLayout* vbox= new QVBoxLayout();
    vbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);

    //title
    QLabel* title= new QLabel("General Search");
    vbox->addWidget(title);



    QHBoxLayout* hbox= new QHBoxLayout();

    //left area - Search widget
    filter= new GeneralFilterWidget();
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    filter->setSizePolicy(spLeft);
    hbox->addWidget(filter);


    DogList* list= new DogList(c);


    //right area - List of all dogs
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


    //set up panel
    QVBoxLayout* all= new QVBoxLayout;

    all->addLayout(vbox);
    all->addSpacing(-400);
    all->addLayout(hbox);

    setLayout(all);
}
