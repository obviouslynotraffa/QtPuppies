#ifndef DOGVISITORINFOPANEL_H
#define DOGVISITORINFOPANEL_H

#include <QVBoxLayout>
#include <QPushButton>

#include "Dog/dogvisitor.h"
#include "Dog/boarding.h"
#include "Dog/breeding.h"

class DogVisitorInfoPanel: public DogVisitor
{
    Q_OBJECT
private:
    QVBoxLayout* InfoPanel;


public:
    QVBoxLayout* getInfoPanel() const;
    virtual void visitBoarding(Boarding& boarding);
    virtual void visitBreeding(Breeding& breeding);

};

#endif // DOGVISITORINFOPANEL_H
