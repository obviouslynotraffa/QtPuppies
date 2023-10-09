#include "DogListWidget.h"
#include "./view/buttons/ButtonsWidget.h"

DogListWidget::DogListWidget(Container& c, QWidget *parent)
    : QWidget{parent}, c(c)
{

}

void DogListWidget::show(){

    DogVisitorCard visitor;
    QVBoxLayout* box= new QVBoxLayout;

        Container::Node* node=c.getHead();


        while(node!=nullptr){

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


    setLayout(box);

}



void DogListWidget::receiveDelete(Dog *d){
    emit signalDelete(d);
}
