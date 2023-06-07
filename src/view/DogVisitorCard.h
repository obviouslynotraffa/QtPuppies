#ifndef DOGVISITORCARD_H
#define DOGVISITORCARD_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>


#include "Dog/dogvisitor.h"
#include "Dog/boarding.h"
#include "Dog/breeding.h"
#include "ButtonsWidget.h"

class DogVisitorCard: public DogVisitor
{

private:
    QVBoxLayout* cardLayout;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

    ButtonsWidget* buttons;

    Dog* dog=nullptr;

public:
    QVBoxLayout* getCard() const;
    virtual void visitBoarding(Boarding& boarding);
    virtual void visitBreeding(Breeding& breeding);



signals:



public slots:



};

#endif // DOGVISITORCARD_H
