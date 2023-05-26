#ifndef DOGCARD_H
#define DOGCARD_H

#include <QWidget>
#include "Dog/container.h"

class DogCard : public QWidget
{
    Q_OBJECT
private:
    Dog* dog;

public:
    explicit DogCard(Dog* dog, QWidget *parent = nullptr);

signals:

};

#endif // DOGCARD_H
