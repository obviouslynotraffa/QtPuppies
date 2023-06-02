#ifndef DOGLIST_H
#define DOGLIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "Dog/container.h"
#include "DogListWidget.h"



class DogList : public QWidget
{
    Q_OBJECT
private:
    Container main;
    QVBoxLayout* box;
    QLabel* imageLabel;
    QLabel* text;
    DogListWidget* list;
    DogListWidget* newList;


public:

    explicit DogList(Container c,QWidget *parent = nullptr);
    void deletePreviousList();

    void hideEmptyList();


public slots:
    void refresh(Container c);



};

#endif // DOGLIST_H
