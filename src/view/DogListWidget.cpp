#include "DogListWidget.h"
#include "ButtonsWidget.h"

DogListWidget::DogListWidget(Container& c, QWidget *parent)
    : QWidget{parent}, c(c)
{

}

void DogListWidget::show(){

    DogVisitorCard visitor;
    QVBoxLayout* box= new QVBoxLayout;



    if(c.getSize()==0)
    {
        /*

        QLabel* imageLabel = new QLabel;
        QPixmap image(":/assets/icons8-pug-under-96.png");

        imageLabel->setPixmap(QPixmap(image));
        imageLabel->setAlignment(Qt::AlignCenter);

        box->addWidget(imageLabel);
        box->setAlignment(Qt::AlignCenter);

        QLabel* text= new QLabel();
        text->setText("Nothing found");
        text->setAlignment(Qt::AlignCenter);

        text->setStyleSheet(QString("QLabel {font-weight: bold;}"));
        box->addWidget(text);*/


    }

    else
    {
        Container::Node* node=c.getHead();

        for(unsigned int i=0;i<c.getSize();i++){

            c.getDog(node)->accept(visitor);

            QHBoxLayout* hbox= new QHBoxLayout;
            buttns= new ButtonsWidget(c.getDog(node),c);

            box->addLayout(hbox);

            hbox->addLayout(visitor.getCard());
            hbox->addWidget(buttns);

            QFrame* line= new QFrame;
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);

            box->addWidget(line);


            node=c.getNextNode(node);


            connect(buttns, &ButtonsWidget::deletePressed, this, &DogListWidget::receiveDelete);

        }
    }




    setLayout(box);

}



void DogListWidget::receiveDelete(Dog *d){
    emit signalDelete(d);
}
