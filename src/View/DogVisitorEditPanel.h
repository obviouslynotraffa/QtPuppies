#ifndef DOGVISITOREDITPANEL_H
#define DOGVISITOREDITPANEL_H


#include <QVBoxLayout>


#include "Dog/dogvisitor.h"
#include "Dog/boarding.h"
#include "Dog/breeding.h"

class DogVisitorEditPanel: public DogVisitor
{
    Q_OBJECT
private:
    QVBoxLayout* editPanel;

public:
    QVBoxLayout* getEditPanel() const;
    virtual void visitBoarding(Boarding& boarding);
    virtual void visitBreeding(Breeding& breeding);

};

#endif // DOGVISITOREDITPANEL_H
