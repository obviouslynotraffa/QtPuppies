#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>
#include <QDialog>

#include "GeneralFilterWidget.h"


GeneralFilterWidget::GeneralFilterWidget(QWidget *parent)
    : QWidget{parent}
{

    QVBoxLayout* vbox= new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);



    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    //General dog search bar
    QLabel* searchbar= new QLabel();
    searchbar->setText("Search Bar");
    vbox->addWidget(searchbar);
    QHBoxLayout *hbox= new QHBoxLayout();

    filterString= new QLineEdit();
    filterString->setPlaceholderText("Dog's name");
    QPushButton* search_input = new QPushButton(QPixmap((":/assets/icons8-search-48.png")),"");
    search_input->setIconSize(QSize(25,25));


    hbox->addWidget(filterString);
    hbox->addWidget(search_input);

    vbox->addLayout(hbox);


    //connect signals
    connect(search_input, &QPushButton::released, this, &GeneralFilterWidget::searchPressed);

}


void GeneralFilterWidget::searchPressed(){
    emit searchEvent(filterString->text());
}


