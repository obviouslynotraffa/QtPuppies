#ifndef BOARDINGFILTERWIDGET_H
#define BOARDINGFILTERWIDGET_H


#include <QRadioButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>


class BoardingFilterWidget: public QWidget
{
    Q_OBJECT
private:
    QLineEdit* filterString;

    QRadioButton* M;
    QRadioButton* L;
    QRadioButton* S;
    QRadioButton* all;
    QRadioButton* sizeChose;

    QPushButton* opt;

    QCheckBox* bath;
    QCheckBox* walks;
    QCheckBox* diet;
    QCheckBox* training;

public:
    explicit BoardingFilterWidget(QWidget *parent = nullptr);

signals:
    void searchEvent(QString s,QRadioButton* size, QCheckBox* bath, QCheckBox* walks, QCheckBox* diet, QCheckBox* training);

public slots:
    void searchPressed();
    void searchAll();
    void searchM();
    void searchL();
    void searchS();

    void untoggleOptions();

};

#endif // BOARDINGFILTERWIDGET_H
