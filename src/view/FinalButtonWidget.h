#ifndef FINALBUTTONWIDGET_H
#define FINALBUTTONWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QMessageBox>

#include "Dog/boarding.h"
#include "Dog/breeding.h"

#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"

#include "ButtonsWidget.h"

class FinalButtonWidget : public QWidget
{
    Q_OBJECT
private:

    QPushButton* button;

    //Dog;
    Boarding* boarding= nullptr;
    Breeding* breeding= nullptr;


    QLineEdit* name= nullptr;
    QLineEdit* date= nullptr;
    QLineEdit* breed= nullptr;
    QComboBox* size= nullptr;
    QCheckBox* bath= nullptr;
    QCheckBox* walks= nullptr;
    QCheckBox* diet= nullptr;
    QCheckBox* training= nullptr;

    //Owner
    QLineEdit* owName= nullptr;
    QLineEdit* owSurname= nullptr;
    QLineEdit* owDate= nullptr;
    QLineEdit* owPhone= nullptr;
    QLineEdit* owAddress= nullptr;
    QLineEdit* owHn= nullptr;

    QComboBox* breeds= nullptr;
    QCheckBox* vax=nullptr;
    QCheckBox* purch= nullptr;
    QCheckBox* booked= nullptr;

    //bool wrongData;





public:

    //edit boarding
    explicit FinalButtonWidget(Boarding* boarding, QLineEdit* name, QLineEdit* date, QLineEdit* breed, QComboBox* size,
                               QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training,
                               QLineEdit* owName, QLineEdit* owSurname, QLineEdit* owDate, QLineEdit* owPhone, QLineEdit* owAddress, QLineEdit* owHn,
                               QWidget *parent = nullptr);

    //edit breeding
    explicit FinalButtonWidget(Breeding* breeding, QLineEdit* name, QLineEdit* date, QComboBox* breed,
                               QCheckBox* vax,QCheckBox* purch, QCheckBox* booked ,QWidget *parent = nullptr);

    //create boarding
    explicit FinalButtonWidget(QLineEdit* name, QLineEdit* date, QLineEdit* breed, QComboBox* size,
                               QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training,
                               QLineEdit* owName, QLineEdit* owSurname, QLineEdit* owDate, QLineEdit* owPhone, QLineEdit* owAddress, QLineEdit* owHn,
                               QWidget *parent = nullptr);


    //create breeding
    explicit FinalButtonWidget(QLineEdit* name, QLineEdit* date, QComboBox* breed,
                               QCheckBox* vax,QCheckBox* purch, QCheckBox* booked ,QWidget *parent = nullptr);





public slots:
    void setChangesBoarding();
    void setChangesBreeding();

    void createBoarding();
    void createBreeding();


signals:

    void addBoarding(Boarding* boarding);
    void addBreeding(Breeding* breeding);


};

#endif // FINALBUTTONWIDGET_H
