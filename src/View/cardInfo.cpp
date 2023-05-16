#include "cardInfo.h"
#include <QHBoxLayout>

CardInfo::CardInfo(QWidget *parent, Dog& dog)
    : QWidget(parent), dog(dog)
{/*
    QHBoxLayout* box= new QHBoxLayout();
    DogInfoVisitor visitor;
    dog.accept(visitor);
    box->addWidget(visitor.getWidget());
*/

}
