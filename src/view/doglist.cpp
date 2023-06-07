#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QDialog>

#include "doglist.h"
#include "dogcard.h"
#include "DogVisitorCard.h"


DogList::DogList(QWidget *parent)
    :   QWidget(parent)
{
    box= new QVBoxLayout;

    imageLabel = new QLabel;
    QPixmap image(":/assets/icons8-pug-under-96.png");

    imageLabel->setPixmap(QPixmap(image));
    imageLabel->setAlignment(Qt::AlignCenter);

    box->addWidget(imageLabel);
    box->setAlignment(Qt::AlignCenter);

    text= new QLabel();
    text->setText("Nothing found");
    text->setAlignment(Qt::AlignCenter);

    text->setStyleSheet(QString("QLabel {font-weight: bold;}"));
    box->addWidget(text);


    list=nullptr;



    setLayout(box);

}

void DogList::refresh(Container c){

    deletePreviousList();

    //Show all dog that rispect the filter

    list= new DogListWidget(c);
    box->addWidget(list);


    if(c.getSize()>0){

        hideEmptyList();
        list->show();
        box->setAlignment(Qt::AlignTop);

    } else{ //Display something if not found any

        imageLabel->setVisible(true);
        text->setVisible(true);
        box->setAlignment(Qt::AlignCenter);

    }

    setLayout(box);

}


void DogList::hideEmptyList(){

    imageLabel->setVisible(false);
    text->setVisible(false);

}

void DogList::deletePreviousList(){

    if(list){
        box->removeWidget(list);
        delete list;
    }

}



