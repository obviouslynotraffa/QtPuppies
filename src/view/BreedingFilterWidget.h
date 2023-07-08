#ifndef BREEDINGFILTERWIDGET_H
#define BREEDINGFILTERWIDGET_H


#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class BreedingFilterWidget: public QWidget
{
    Q_OBJECT
private:
    QLineEdit* filterString;

    QRadioButton* all;
    QRadioButton* bull;
    QRadioButton* ams;
    QRadioButton* breedChose;

    QPushButton* opt;

    QCheckBox* vax;
    QCheckBox* booked;
    QCheckBox* purch;
public:
    explicit BreedingFilterWidget(QWidget *parent = nullptr);

signals:
    void searchEvent(QString s,QRadioButton* r, QCheckBox* v, QCheckBox* b, QCheckBox* p);

public slots:
    void searchPressed();
    void searchAll();
    void searchBulldog();
    void searchAmstaff();

    void untoggleOptions();


};

#endif // BREEDINGFILTERWIDGET_H
