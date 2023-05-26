#ifndef BOARDINGPANEL_H
#define BOARDINGPANEL_H

#include "BoardingFilterWidget.h"
#include "Dog/container.h"

class BoardingPanel : public QWidget
{
    Q_OBJECT
private:
    BoardingFilterWidget* filter;
    Container c;

public:
    explicit BoardingPanel(Container c,QWidget *parent = nullptr);

signals:

};

#endif // BOARDINGPANEL_H
