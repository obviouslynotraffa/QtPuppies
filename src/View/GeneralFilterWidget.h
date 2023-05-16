#ifndef GENERALFILTERWIDGET_H
#define GENERALFILTERWIDGET_H

#include <QLineEdit>

class GeneralFilterWidget : public QWidget
{
    Q_OBJECT

private:
    QLineEdit* filterString;

public:
    explicit GeneralFilterWidget(QWidget *parent = nullptr);

signals:
    void searchEvent();

public slots:
    //void search();

};

#endif // GENERALFILTERWIDGET_H
