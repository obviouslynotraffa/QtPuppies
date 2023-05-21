#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "Dog/dog.h"


class ButtonsWidget : public QWidget
{
    Q_OBJECT
public:
    Dog* dog;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

    explicit ButtonsWidget(Dog* dog, QWidget *parent = nullptr);

public slots:
    void createInfoPanel();

};

#endif // BUTTONSWIDGET_H
