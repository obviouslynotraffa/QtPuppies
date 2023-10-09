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
    void searchEvent(QString s);

public slots:
    void searchPressed();


};

#endif // GENERALFILTERWIDGET_H
