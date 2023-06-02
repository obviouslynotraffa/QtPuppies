#ifndef GENERALPANEL_H
#define GENERALPANEL_H

#include "GeneralFilterWidget.h"
#include "Dog/container.h"
#include "doglist.h"

class GeneralPanel: public QWidget
{
    Q_OBJECT

private:

    Container c;
    GeneralFilterWidget* filter;
    DogList* list;

public:

    explicit GeneralPanel(Container c,QWidget *parent = nullptr);


public slots:
    void search(QString s);

};

#endif // GENERALPANEL_H
