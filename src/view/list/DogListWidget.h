#ifndef DOGLISTWIDGET_H
#define DOGLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>

#include "Dog/container.h"
#include "./view/visitor/DogVisitorCard.h"
#include "./view/buttons/ButtonsWidget.h"

class DogListWidget : public QWidget
{
    Q_OBJECT
private:
    Container c;
    ButtonsWidget* buttns;


public:
    explicit DogListWidget(Container& c,QWidget *parent = nullptr);

    void show();

signals:

    void signalDelete(Dog* d);

public slots:
    void receiveDelete(Dog* d);

};

#endif // DOGLISTWIDGET_H
