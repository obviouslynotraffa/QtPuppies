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


public slots:


};

#endif // GENERALFILTERWIDGET_H
