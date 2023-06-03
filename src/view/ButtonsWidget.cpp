#include <QDialog>
#include <QHBoxLayout>
#include <QStyle>
#include <QMessageBox>


#include "ButtonsWidget.h"
#include "DogVisitorInfoPanel.h"
#include "DogVisitorEditPanel.h"

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
    connect(edit_button, &QPushButton::released, this, &ButtonsWidget::createEditPanel);
    connect(delete_button, &QPushButton::released, this, &ButtonsWidget::createDeleteMessage);



    setLayout(buttons);

}


void ButtonsWidget::createInfoPanel(){

   DogVisitorInfoPanel visitor;
   dog->accept(visitor);

   QDialog* dialogInfo =  new QDialog;
   dialogInfo->setLayout(visitor.getInfoPanel());
   dialogInfo->setModal(true);
   dialogInfo->setMinimumHeight(250);
   dialogInfo->setMinimumWidth(650);
   dialogInfo->setWindowTitle(QString::fromStdString(dog->getName()));
   dialogInfo->setWindowIcon(QIcon(":/assets/icons8-info-48.png"));
   dialogInfo->show();
}



void ButtonsWidget::createEditPanel(){

    DogVisitorEditPanel visitor;
    dog->accept(visitor);

    dialogEdit =  new QDialog;
    dialogEdit->setLayout(visitor.getEditPanel());
    dialogEdit->setModal(true);
    dialogEdit->setMinimumHeight(250);
    dialogEdit->setMinimumWidth(650);
    dialogEdit->setWindowTitle("Editing "+QString::fromStdString(dog->getName()));
    dialogEdit->setWindowIcon(QIcon(":/assets/icons8-edit-48.png"));
    dialogEdit->show();

}




void ButtonsWidget::createDeleteMessage(){


    QMessageBox msgBox;

    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Warning");

    msgBox.setText("Are you sure to delete "+ QString::fromStdString(dog->getName())+ " ?\t\t");
    msgBox.setInformativeText("This action can not be undone later.");

    msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);


    int ret = msgBox.exec();

    if(ret == QMessageBox::Yes){

    }


}


