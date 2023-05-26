#ifndef BREEDINGPANEL_H
#define BREEDINGPANEL_H

#include "BreedingFilterWidget.h"
#include "Dog/container.h"

class BreedingPanel : public QWidget
{
    Q_OBJECT
private:
    BreedingFilterWidget* filter;
    Container c;

public:
    explicit BreedingPanel(Container c, QWidget *parent = nullptr);

signals:

};

#endif // BREEDINGPANEL_H
