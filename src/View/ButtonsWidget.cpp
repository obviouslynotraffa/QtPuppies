#include <QDialog>
#include <QHBoxLayout>
#include <QStyle>


#include "ButtonsWidget.h"
#include "DogVisitorInfoPanel.h"

ButtonsWidget::ButtonsWidget(Dog* dog, QWidget *parent)
    : QWidget{parent}, dog(dog)
{

    //Buttons
    QHBoxLayout* buttons= new QHBoxLayout();
    buttons->setAlignment(Qt::AlignBottom|Qt::AlignCenter);

    view_button= new QPushButton(QIcon(QPixmap(":/assets/info-icon.png")), "");
    view_button->setIconSize(QSize(18,18));
    buttons->addWidget(view_button);

    edit_button= new QPushButton(QIcon(QPixmap(":/assets/edit-icon.png")), "");
    edit_button->setIconSize(QSize(18,18));
    buttons->addWidget(edit_button);

    delete_button= new QPushButton(QIcon(QPixmap(":/assets/delete-icon.png")), "");
    delete_button->setIconSize(QSize(18,18));
    buttons->addWidget(delete_button);

    //Connect
    connect(view_button, &QPushButton::released, this, &ButtonsWidget::createInfoPanel);

    setLayout(buttons);

}


void ButtonsWidget::createInfoPanel(){

   DogVisitorInfoPanel visitor;
   dog->accept(visitor);

   QDialog* dialog =  new QDialog;
   dialog->setLayout(visitor.getInfoPanel());
   dialog->setModal(true);
   dialog->setMinimumHeight(250);
   dialog->setMaximumHeight(250);
   dialog->setMinimumWidth(650);
   dialog->setMaximumWidth(650);
   dialog->setWindowTitle(QString::fromStdString(dog->getName()));
   dialog->setWindowIcon(QIcon(":/assets/icons8-info-48.png"));
   dialog->show();
}
