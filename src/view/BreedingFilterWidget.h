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
    QRadioButton* bulld;
    QRadioButton* amstff;

    QCheckBox* vax;
    QCheckBox* booked;
    QCheckBox* purch;
public:
    explicit BreedingFilterWidget(QWidget *parent = nullptr);


};

#endif // BREEDINGFILTERWIDGET_H
