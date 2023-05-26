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

   QDialog* dialog =  new QDialog;
   dialog->setLayout(visitor.getInfoPanel());
   dialog->setModal(true);
   dialog->setMinimumHeight(250);
   dialog->setMinimumWidth(650);
   dialog->setWindowTitle(QString::fromStdString(dog->getName()));
   dialog->setWindowIcon(QIcon(":/assets/icons8-info-48.png"));
   dialog->show();
}



void ButtonsWidget::createEditPanel(){

    DogVisitorEditPanel visitor;
    dog->accept(visitor);

    QDialog* dialog =  new QDialog;
    dialog->setLayout(visitor.getEditPanel());
    dialog->setModal(true);
    dialog->setMinimumHeight(250);
    dialog->setMinimumWidth(650);
    dialog->setWindowTitle("Editing "+QString::fromStdString(dog->getName()));
    dialog->setWindowIcon(QIcon(":/assets/icons8-edit-48.png"));
    dialog->show();

}



void ButtonsWidget::createDeleteMessage(){


    QMessageBox msgBox;

    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Warning");

    msgBox.setText("Are you sure to delete "+ QString::fromStdString(dog->getName())+ " ?\t\t");
    msgBox.setInformativeText("This action can not be undone later.");

    msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);



    int ret = msgBox.exec();

    if(ret == QMessageBox::Yes){

    }


}
