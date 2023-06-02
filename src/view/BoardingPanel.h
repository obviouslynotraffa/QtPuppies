#ifndef BOARDINGPANEL_H
#define BOARDINGPANEL_H

#include <QRadioButton>

#include "BoardingFilterWidget.h"
#include "Dog/container.h"
#include "doglist.h"

class BoardingPanel : public QWidget
{
    Q_OBJECT
private:
    BoardingFilterWidget* filter;
    Container c;
    DogList* list;


public:
    explicit BoardingPanel(Container c,QWidget *parent = nullptr);

public slots:
    void search(QString s,QRadioButton* size, QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training);

};

#endif // BOARDINGPANEL_H
