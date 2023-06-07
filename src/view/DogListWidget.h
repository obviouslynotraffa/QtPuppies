#ifndef DOGLISTWIDGET_H
#define DOGLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

#include "Dog/container.h"
#include "DogVisitorCard.h"
#include "ButtonsWidget.h"

class DogListWidget : public QWidget
{
    Q_OBJECT
private:
    Container c;
    ButtonsWidget* buttns;


public:
    explicit DogListWidget(Container c,QWidget *parent = nullptr);

    void show();

signals:

    //signalDelete(Dog* d);

public slots:
    //receiveDelete(Dog* d);

};

#endif // DOGLISTWIDGET_H
