#ifndef GENERALPANEL_H
#define GENERALPANEL_H

#include "GeneralFilterWidget.h"
#include "Dog/container.h"

class GeneralPanel: public QWidget
{
    Q_OBJECT

private:

    Container c;
    GeneralFilterWidget* filter;

public:

    explicit GeneralPanel(Container c,QWidget *parent = nullptr);

};

#endif // GENERALPANEL_H
