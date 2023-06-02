#ifndef DOGLISTWIDGET_H
#define DOGLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

#include "Dog/container.h"
#include "DogVisitorCard.h"

class DogListWidget : public QWidget
{
    Q_OBJECT
private:
    Container c;

public:
    explicit DogListWidget(Container c,QWidget *parent = nullptr);

    void show();

signals:

};

#endif // DOGLISTWIDGET_H
