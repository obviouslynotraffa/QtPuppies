#include "DogListWidget.h"

DogListWidget::DogListWidget(Container c, QWidget *parent)
    : QWidget{parent}, c(c)
{

}

void DogListWidget::show(){

    DogVisitorCard visitor;
    QVBoxLayout* box= new QVBoxLayout;
    box->setAlignment(Qt::AlignTop);

    Container::Node* node=c.getHead();

    for(unsigned int i=0;i<c.getSize();i++){

        c.getDog(node)->accept(visitor);
        box->addLayout(visitor.getCard());
        node=c.getNextNode(node);

    }

    setLayout(box);

}
