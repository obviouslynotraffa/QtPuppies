#ifndef BOARDINGPANEL_H
#define BOARDINGPANEL_H

#include <QRadioButton>

#include "BoardingFilterWidget.h"
#include "Dog/container.h"
#include "DogList.h"

class BoardingPanel : public QWidget
{
    Q_OBJECT
private:
    BoardingFilterWidget* filter;
    Container c;
    DogList* list;


public:
    explicit BoardingPanel(Container c,QWidget *parent = nullptr);
    void setContainer(Container w);
    void refresh() const;

public slots:
    void search(QString s,QRadioButton* size, QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training);
    void receiveDelete(Dog* d);

signals:
    void signalDelete(Dog* d);

};

#endif // BOARDINGPANEL_H
