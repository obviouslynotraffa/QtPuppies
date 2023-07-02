#ifndef BREEDINGPANEL_H
#define BREEDINGPANEL_H

#include "BreedingFilterWidget.h"
#include "Dog/container.h"
#include "DogList.h"

class BreedingPanel : public QWidget
{
    Q_OBJECT
private:
    BreedingFilterWidget* filter;
    Container c;
    DogList* list;

public:
    explicit BreedingPanel(Container c, QWidget *parent = nullptr);
    void setContainer(Container w);

public slots:
    void search(QString s, QRadioButton* r, QCheckBox* vax, QCheckBox* booked, QCheckBox* purch);
    void receiveDelete(Dog* d);

signals:
    void signalDelete(Dog* d);

};

#endif // BREEDINGPANEL_H
