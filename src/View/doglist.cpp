#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QDialog>

#include "doglist.h"
#include "dogcard.h"
#include "DogVisitorCard.h"

DogList::DogList(Container c,QWidget *parent)
    :   QWidget(parent), NoFilter(c)
{

    QVBoxLayout* box= new QVBoxLayout;
    DogVisitorCard visitor;

    //Show all dog that rispect the filter

    if(c.getSize()>0){

        Container::Node* node=c.getHead();

        for(unsigned int i=0;i<c.getSize();i++){

            c.getDog(node)->accept(visitor);
            box->addLayout(visitor.getCard());
            node=c.getNextNode(node);

        }

    } else{ //Display something if not found any

        QLabel *imageLabel = new QLabel;
        QPixmap image(":/assets/icons8-pug-under-96.png");

        imageLabel->setPixmap(QPixmap(image));

        box->addWidget(imageLabel);
        box->setAlignment(Qt::AlignCenter|Qt::AlignHCenter|Qt::AlignVCenter);

        QLabel* text= new QLabel();
        text->setText("Nothing found");

        text->setStyleSheet(QString("QLabel {font-weight: bold;}"));
        box->addWidget(text);

    }



    setLayout(box);

}


