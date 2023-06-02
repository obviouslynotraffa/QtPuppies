#ifndef BREEDINGFILTERWIDGET_H
#define BREEDINGFILTERWIDGET_H


#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>

class BreedingFilterWidget: public QWidget
{
    Q_OBJECT
private:
    QLineEdit* filterString;

    QRadioButton* all;
    QRadioButton* bull;
    QRadioButton* ams;
    QRadioButton* breedChose;

    QCheckBox* vax;
    QCheckBox* booked;
    QCheckBox* purch;
public:
    explicit BreedingFilterWidget(QWidget *parent = nullptr);

signals:
    searchEvent(QString s,QRadioButton* r, QCheckBox* v, QCheckBox* b, QCheckBox* p);

public slots:
    void searchPressed();
    void searchAll();
    void searchBulldog();
    void searchAmstaff();

    void untoggleOptions();


};

#endif // BREEDINGFILTERWIDGET_H
