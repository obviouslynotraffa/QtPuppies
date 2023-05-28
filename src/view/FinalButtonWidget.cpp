#include "FinalButtonWidget.h"

FinalButtonWidget::FinalButtonWidget(Boarding* boarding, QLineEdit* name, QLineEdit* date, QLineEdit* breed, QComboBox* size,
                                     QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training,
                                     QLineEdit* owName, QLineEdit* owSurname, QLineEdit* owDate, QLineEdit* owPhone, QLineEdit* owAddress, QLineEdit* owHn,
                                     QWidget *parent)
    : QWidget{parent}, boarding(boarding), name(name), date(date), breed(breed), size(size),
      bath(bath), walks(walks), diet(diet), training(training),
      owName(owName), owSurname(owSurname), owDate(owDate), owPhone(owPhone), owAddress(owAddress), owHn(owHn)
{

    QHBoxLayout* hbox= new QHBoxLayout;
    button= new QPushButton;
    hbox->addStretch();
    hbox->addWidget(button);
    button->setMinimumSize(80,40);

    button->setText("Save Changes");
    button->setFocusPolicy(Qt::NoFocus);


    //connect signals
    connect(button, &QPushButton::released, this, &FinalButtonWidget::setChangesBoarding);
    connect(button, &QPushButton::released, this, &FinalButtonWidget::checkChanges);



    setLayout(hbox);

}


void FinalButtonWidget::setChangesBoarding(){

    boarding->setName(name->text().toStdString())
            ->setDate(Date::toDate(date->text().toStdString()));

    boarding->setBreed(breed->text().toStdString())
            ->setBath(bath->isChecked())
            ->setDiet(diet->isChecked())
            ->setTraining(training->isChecked())
            ->setWalking(walks->isChecked());

    Owner* ow= boarding->getOwner();

    ow->setName(owName->text().toStdString())
            ->setSurname(owSurname->text().toStdString())
            ->setBirthday(Date::toDate(owDate->text().toStdString()))
            ->setAddress(owAddress->text().toStdString())
            ->setPhone(owPhone->text().toStdString())
            ->setHouseNumber(owHn->text().toStdString());


    if(size->currentText()=="Large"){

        Large* large= new Large;
        boarding->setSize(large);
    }

    if(size->currentText()=="Medium"){

        Medium* medium= new Medium;
        boarding->setSize(medium);
    }

    if(size->currentText()=="Small"){

        Small* small= new Small;
        boarding->setSize(small);
    }


}


FinalButtonWidget::FinalButtonWidget(Breeding *breeding, QLineEdit *name, QLineEdit *date, QComboBox *breed,
                                     QCheckBox *vax, QCheckBox *purch, QCheckBox *booked, QWidget *parent):
                    QWidget{parent}, breeding(breeding), name(name), date(date), breeds(breed),
                    vax(vax), purch(purch), booked(booked)
{

    QHBoxLayout* hbox= new QHBoxLayout;
    button= new QPushButton;
    hbox->addStretch();
    hbox->addWidget(button);
    button->setMinimumSize(80,40);

    button->setText("Save Changes");
    button->setFocusPolicy(Qt::NoFocus);


    //connect signals
    connect(button, &QPushButton::released, this, &FinalButtonWidget::setChangesBreeding);
    connect(button, &QPushButton::released, this, &FinalButtonWidget::checkChanges);


    setLayout(hbox);

}


void FinalButtonWidget::setChangesBreeding(){

    breeding->setName(name->text().toStdString())
            ->setDate(Date::toDate(date->text().toStdString()));

    breeding->setBooked(booked->isChecked())
            ->setPurch(purch->isChecked())
            ->setVax(vax->isChecked());


    if(breeds->currentText()=="AmStaff"){
        AmStaff* amstaff= new AmStaff;
        breeding->setBreed(amstaff);
    }

    if(breeds->currentText()=="Bulldog"){
        Bulldog* bulldog= new Bulldog;
        breeding->setBreed(bulldog);
    }

}


void FinalButtonWidget::checkChanges(){

    QMessageBox msgBox;

    msgBox.setIconPixmap(QPixmap(":/assets/icons8-done-48.png"));
    msgBox.setWindowTitle("Status");

    msgBox.setText("Changes set correctly");

    msgBox.setStandardButtons(QMessageBox::Close);

    msgBox.exec();

}
