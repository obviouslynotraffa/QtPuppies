#ifndef GENERALPANEL_H
#define GENERALPANEL_H

#include "GeneralFilterWidget.h"
#include "Dog/container.h"
#include "doglist.h"
#include "ButtonsWidget.h"

class GeneralPanel: public QWidget
{
    Q_OBJECT

private:

    Container c;
    GeneralFilterWidget* filter;
    DogList* list;


public:

    explicit GeneralPanel(Container c,QWidget *parent = nullptr);
    void setContainer(Container w);

signals:
    void signalDelete(Dog* d);


public slots:
    void search(QString s);
    void receiveDelete(Dog* d);

};

#endif // GENERALPANEL_H
