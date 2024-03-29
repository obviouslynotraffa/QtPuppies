#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "Dog/dog.h"
#include "Dog/container.h"


class ButtonsWidget : public QWidget
{
    Q_OBJECT
public:
    Dog* dog;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;
    Container c;

    QDialog* dialogEdit;

    explicit ButtonsWidget(Dog* dog, Container& c, QWidget *parent = nullptr);


public slots:
    void createInfoPanel();
    void createEditPanel();
    void createDeleteMessage();



signals:
    void deletePressed(Dog* dog);


};

#endif // BUTTONSWIDGET_H
