#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>

#include "BoardingFilterWidget.h"


BoardingFilterWidget::BoardingFilterWidget(QWidget *parent)
    : QWidget{parent}
{

    QVBoxLayout* vbox= new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignCenter|Qt::AlignTop);


    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);


    //search bar
    QHBoxLayout* hbox= new QHBoxLayout();
    filterString= new QLineEdit();
    filterString->setPlaceholderText("Dog's name");

    QLabel* searchbar= new QLabel();
    searchbar->setText("Search Bar");
    vbox->addWidget(searchbar);
    QPushButton* search_button = new QPushButton(QPixmap((":/assets/icons8-search-48.png")),"");
    search_button->setIconSize(QSize(25,25));
    hbox->addWidget(filterString);
    hbox->addWidget(search_button);
    vbox->addLayout(hbox);

    vbox->addSpacing(30);

    //filter by sizes
    QHBoxLayout* hbox1= new QHBoxLayout();
    QLabel* size= new QLabel("Size:");
    vbox->addWidget(size);

    QRadioButton* L= new QRadioButton();
    QRadioButton* M= new QRadioButton();
    QRadioButton* S= new QRadioButton();
    QRadioButton* all= new QRadioButton();

    all->setText("All");
    L->setText("Large");
    M->setText("Medium");
    S->setText("Small");
    all->setChecked(true);



    hbox1->addWidget(all);
    hbox1->addWidget(L);
    hbox1->addWidget(M);
    hbox1->addWidget(S);
    vbox->addLayout(hbox1);

    //set up optional services
    QCheckBox* opt= new QCheckBox();
    opt->setText("Options:");

    diet = new  QCheckBox();
    diet->setText("Diet");
    diet->setVisible(false);


    bath = new  QCheckBox();
    bath->setText("Bath");
    bath->setVisible(false);

    walks = new  QCheckBox();
    walks->setText("Walks");
    walks->setVisible(false);

    training = new  QCheckBox();
    training->setText("Training");
    training->setVisible(false);


    vbox->addSpacing(30);
    vbox->addWidget(opt);
    vbox->addWidget(diet);
    vbox->addWidget(bath);
    vbox->addWidget(walks);
    vbox->addWidget(training);


    //connect signals
    connect(opt,SIGNAL(clicked(bool)),bath,SLOT(setVisible(bool)));
    connect(opt,SIGNAL(clicked(bool)),diet,SLOT(setVisible(bool)));
    connect(opt,SIGNAL(clicked(bool)),walks,SLOT(setVisible(bool)));
    connect(opt,SIGNAL(clicked(bool)),training,SLOT(setVisible(bool)));



    setLayout(vbox);

}






