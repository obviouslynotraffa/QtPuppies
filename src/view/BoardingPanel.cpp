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


    list= new DogList();

    //right scroll area with only boarding dogs
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


    //panel
    QVBoxLayout* all= new QVBoxLayout;

    all->addLayout(vbox);
    all->addSpacing(-400);
    all->addLayout(hbox);

    //connect
    connect(filter, &BoardingFilterWidget::searchEvent, this, &BoardingPanel::search);
    connect(list, &DogList::signalDelete, this, &BoardingPanel::receiveDelete);

    setLayout(all);
}



void BoardingPanel::search(QString s, QRadioButton *size, QCheckBox *bath, QCheckBox *walks, QCheckBox *diet, QCheckBox *training){

    Container aux=c;

    if(size->text()=="All")
    {
        if(bath->isChecked())c=c.filterBath();
        if(diet->isChecked())c=c.filterDiet();
        if(training->isChecked())c=c.filterTraining();
        if(walks->isChecked())c=c.filterWalks();

        list->refresh(c.searchDog(s.toStdString()));
    }

    if(size->text()=="Large")
    {
        if(bath->isChecked())c=c.filterBath();
        if(diet->isChecked())c=c.filterDiet();
        if(training->isChecked())c=c.filterTraining();
        if(walks->isChecked())c=c.filterWalks();

        Large large;

        list->refresh(c.searchDog(s.toStdString()).filterSize(&large));

    }

    if(size->text()=="Small")
    {
        if(bath->isChecked())c=c.filterBath();
        if(diet->isChecked())c=c.filterDiet();
        if(training->isChecked())c=c.filterTraining();
        if(walks->isChecked())c=c.filterWalks();

        Small small;

        list->refresh(c.searchDog(s.toStdString()).filterSize(&small));

    }

    if(size->text()=="Medium")
    {
        if(bath->isChecked())c=c.filterBath();
        if(diet->isChecked())c=c.filterDiet();
        if(training->isChecked())c=c.filterTraining();
        if(walks->isChecked())c=c.filterWalks();

        Medium medium;

        list->refresh(c.searchDog(s.toStdString()).filterSize(&medium));

    }

    c=aux;
}


void BoardingPanel::setContainer(Container w){
    c=w;
}


void BoardingPanel::receiveDelete(Dog *d){
    emit signalDelete(d);
}
