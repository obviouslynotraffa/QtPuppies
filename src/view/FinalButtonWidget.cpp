#include <QDate>

#include "FinalButtonWidget.h"
#include "Dog/date.h"

FinalButtonWidget::FinalButtonWidget(Boarding* boarding, QLineEdit* name, QLineEdit* date, QLineEdit* breed, QComboBox* size,
                                     QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training,
                                     QLineEdit* owName, QLineEdit* owSurname, QLineEdit* owDate, QLineEdit* owPhone, QLineEdit* owAddress, QLineEdit* owHn,
                                     QWidget *parent)
    : QWidget{parent}, boarding(boarding), name(name), date(date), breed(breed), size(size),
      bath(bath), walks(walks), diet(diet), training(training),
      owName(owName), owSurname(owSurname), owDate(owDate), owPhone(owPhone), owAddress(owAddress), owHn(owHn)
{

    //create button
    QHBoxLayout* hbox= new QHBoxLayout;
    button= new QPushButton;
    hbox->addStretch();
    hbox->addWidget(button);
    button->setMinimumSize(80,40);

    button->setText("Save Changes");
    button->setFocusPolicy(Qt::NoFocus);


    //connect signals
    connect(button, &QPushButton::released, this, &FinalButtonWidget::setChangesBoarding);

    setLayout(hbox);

}


void FinalButtonWidget::setChangesBoarding(){

    QMessageBox msgBox;


    //check if date is valid
    Date input=Date::toDate(date->text().toStdString());
    QDate tryDate(input.getYear(), input.getMonth(), input.getDay());


    //check if owner date is valid
    Owner* ow= boarding->getOwner();
    Date inputOwner=Date::toDate(owDate->text().toStdString());
    QDate tryDateOw(inputOwner.getYear(), inputOwner.getMonth(), inputOwner.getDay());


    //show message if miss something
    if(name->text().isEmpty()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Name missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
     else if(!tryDate.isValid()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Invalid dog date");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

    }else if(breed->text().isEmpty()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Breed missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owName->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner name missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

    }
    else if(owSurname->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner surname missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(!tryDateOw.isValid()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner date not valid");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owPhone->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner phone missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owAddress->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner address missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owHn->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner house's number missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else{ // if all ok
        msgBox.setWindowTitle("Status");
        msgBox.setText("Changes set correctly");
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-done-48.png"));
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

        //set all
        boarding->setName(name->text().toStdString())
                ->setDate(input);

        boarding->setBreed(breed->text().toStdString())
                ->setBath(bath->isChecked())
                ->setDiet(diet->isChecked())
                ->setTraining(training->isChecked())
                ->setWalking(walks->isChecked());

        ow->setName(owName->text().toStdString())
                ->setSurname(owSurname->text().toStdString())
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


    setLayout(hbox);

}


void FinalButtonWidget::setChangesBreeding(){

    QMessageBox  msgBox;

    Date input=Date::toDate(date->text().toStdString());
    QDate tryDate(input.getYear(), input.getMonth(), input.getDay());


    if(name->text().isEmpty()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Name missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
     else if(!tryDate.isValid()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Invalid dog date");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

    }else{
        // if all ok
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-done-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Changes set correctly");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();


        //set all changes
        breeding->setName(name->text().toStdString())
                ->setDate(input);

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

}


FinalButtonWidget::FinalButtonWidget(QLineEdit* name, QLineEdit* date, QLineEdit* breed, QComboBox* size,
                                     QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training,
                                    QLineEdit* owName, QLineEdit* owSurname, QLineEdit* owDate, QLineEdit* owPhone,
                                     QLineEdit* owAddress, QLineEdit* owHn, QWidget *parent)
: QWidget{parent}, name(name), date(date), breed(breed), size(size),
bath(bath), walks(walks), diet(diet), training(training),
  owName(owName), owSurname(owSurname), owDate(owDate), owPhone(owPhone), owAddress(owAddress), owHn(owHn)
{

    QHBoxLayout* hbox= new QHBoxLayout;
    button= new QPushButton;
    hbox->addStretch();
    hbox->addWidget(button);
    button->setMinimumSize(80,40);

    button->setText("Add dog");
    button->setFocusPolicy(Qt::NoFocus);


    //connect signals
    connect(button, &QPushButton::released, this, &FinalButtonWidget::createBoarding);

    setLayout(hbox);


}



void FinalButtonWidget::createBoarding(){

    QMessageBox msgBox;
    //check dog date
    Date input=Date::toDate(date->text().toStdString());
    QDate tryDate(input.getYear(), input.getMonth(), input.getDay());


    //check owner date
    Date inputOwner=Date::toDate(owDate->text().toStdString());
    QDate tryDateOw(inputOwner.getYear(), inputOwner.getMonth(), inputOwner.getDay());

    //show error if miss something
    if(name->text().isEmpty()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Name missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
     else if(!tryDate.isValid()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Invalid dog date");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

    }else if(breed->text().isEmpty()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Breed missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owName->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner name missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

    }
    else if(owSurname->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner surname missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(!tryDateOw.isValid()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner date not valid");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owPhone->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner phone missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owAddress->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner address missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else if(owHn->text().isEmpty()){
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Owner house's number missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
    else{
        //all ok

        msgBox.setWindowTitle("Status");
        msgBox.setText("Dog added correctly");
        msgBox.setIconPixmap(QPixmap(":/assets/icons8-done-48.png"));
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

        //To do: create dog

    }

}


FinalButtonWidget::FinalButtonWidget(QLineEdit *name, QLineEdit *date, QComboBox *breed,
                                     QCheckBox *vax, QCheckBox *purch, QCheckBox *booked, QWidget *parent):
                    QWidget{parent},  name(name), date(date), breeds(breed),
                    vax(vax), purch(purch), booked(booked)
{
    //button
    QHBoxLayout* hbox= new QHBoxLayout;
    button= new QPushButton;
    hbox->addStretch();
    hbox->addWidget(button);
    button->setMinimumSize(80,40);
    button->setText("Add dog");
    button->setFocusPolicy(Qt::NoFocus);


    //connect signals
    connect(button, &QPushButton::released, this, &FinalButtonWidget::createBreeding);

    setLayout(hbox);


}


void FinalButtonWidget::createBreeding(){

    Date input=Date::toDate(date->text().toStdString());
    QDate tryDate(input.getYear(), input.getMonth(), input.getDay());
    QMessageBox msgBox;


    //show error if something wrong
    if(name->text().isEmpty()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Name missing");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();
    }
     else if(!tryDate.isValid()){

        msgBox.setIconPixmap(QPixmap(":/assets/icons8-close-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Invalid dog date");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

    }else{
        //all ok


        msgBox.setIconPixmap(QPixmap(":/assets/icons8-done-48.png"));
        msgBox.setWindowTitle("Status");
        msgBox.setText("Dog add correctly");
        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.exec();

        //To do: -add dog -parents
    }

}
