#ifndef DOGLIST_H
#define DOGLIST_H

#include <QWidget>

#include "Dog/container.h"


class DogList : public QWidget
{
    Q_OBJECT
private:
    Container c;

public:

    explicit DogList(Container c,QWidget *parent = nullptr);


signals:

};

#endif // DOGLIST_H
