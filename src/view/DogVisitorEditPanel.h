#ifndef DOGVISITOREDITPANEL_H
#define DOGVISITOREDITPANEL_H

#include <QWidget>
#include <QVBoxLayout>

#include "Dog/container.h"
#include "Dog/dogvisitor.h"
#include "Dog/boarding.h"
#include "Dog/breeding.h"

class DogVisitorEditPanel: public DogVisitor
{
    Q_OBJECT
private:
    QVBoxLayout* editPanel;
    Container c;

public:
    QVBoxLayout* getEditPanel() const;
    void setContainer(Container contn);
    virtual void visitBoarding(Boarding& boarding);
    virtual void visitBreeding(Breeding& breeding);

public slots:



signals:





};

#endif // DOGVISITOREDITPANEL_H
