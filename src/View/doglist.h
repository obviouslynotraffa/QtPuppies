#ifndef DOGLIST_H
#define DOGLIST_H

#include <QWidget>

#include "Dog/container.h"


class DogList : public QWidget
{
    Q_OBJECT
private:
    Container NoFilter;

public:

    explicit DogList(Container c,QWidget *parent = nullptr);


public slots:


};

#endif // DOGLIST_H
