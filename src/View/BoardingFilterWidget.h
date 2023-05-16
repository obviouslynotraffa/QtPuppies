#ifndef BOARDINGFILTERWIDGET_H
#define BOARDINGFILTERWIDGET_H


#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>



class BoardingFilterWidget: public QWidget
{
    Q_OBJECT
private:
    QLineEdit* filterString;

    QRadioButton* M;
    QRadioButton* L;
    QRadioButton* S;
    QRadioButton* all;

    QCheckBox* bath;
    QCheckBox* walks;
    QCheckBox* diet;
    QCheckBox* training;

public:
    explicit BoardingFilterWidget(QWidget *parent = nullptr);

signals:


private slots:


};

#endif // BOARDINGFILTERWIDGET_H
