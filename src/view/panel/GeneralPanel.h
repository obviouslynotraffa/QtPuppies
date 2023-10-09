#ifndef GENERALPANEL_H
#define GENERALPANEL_H

#include "./view/filter/GeneralFilterWidget.h"
#include "Dog/container.h"
#include "./view/list/DogList.h"
#include "./view/buttons/ButtonsWidget.h"


class GeneralPanel: public QWidget
{
    Q_OBJECT

private:

    Container c;
    GeneralFilterWidget* filter;
    DogList* list;


public:

    explicit GeneralPanel(Container c, QWidget *parent = nullptr);
    void setContainer(Container w);
    void refresh() const;

signals:
    void signalDelete(Dog* d);


public slots:
    void search(QString s);
    void receiveDelete(Dog* d);

};

#endif // GENERALPANEL_H
