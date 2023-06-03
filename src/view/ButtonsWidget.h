#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "FinalButtonWidget.h"

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
    Container* c;

    QDialog* dialogEdit;

    explicit ButtonsWidget(Dog* dog, QWidget *parent = nullptr);


public slots:
    void createInfoPanel();
    void createEditPanel();
    void createDeleteMessage();

signals:
    void deleteDog(Dog* dog);


};

#endif // BUTTONSWIDGET_H
