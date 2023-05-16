#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

#include "doglist.h"
#include "dogcard.h"

DogList::DogList(Container c,QWidget *parent)
    :   QWidget(parent), c(c)
{

    QVBoxLayout* box= new QVBoxLayout;


    if(c.getSize()>0){ //Show all dog that rispect the filter
        Container::Node* n=c.getHead();

        for(unsigned int i=0;i<c.getSize();i++){
            DogCard* g= new DogCard(c.getDog(n));
            box->addWidget(g);
            n=c.getNextNode(n);
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

