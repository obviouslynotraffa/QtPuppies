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

    L= new QRadioButton();
    M= new QRadioButton();
    S= new QRadioButton();
    all= new QRadioButton();

    all->setText("All");
    L->setText("Large");
    M->setText("Medium");
    S->setText("Small");
    all->setChecked(true);

    sizeChose=all;
    sizeChose->setText("All");


    hbox1->addWidget(all);
    hbox1->addWidget(L);
    hbox1->addWidget(M);
    hbox1->addWidget(S);
    vbox->addLayout(hbox1);

    //set up optional services
    QPushButton* opt= new QPushButton();
    opt->setFlat(true);
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
    connect(all, &QRadioButton::pressed, this, &BoardingFilterWidget::searchAll);
    connect(L, &QRadioButton::pressed, this, &BoardingFilterWidget::searchL);
    connect(M, &QRadioButton::pressed, this, &BoardingFilterWidget::searchM);
    connect(S, &QRadioButton::pressed, this, &BoardingFilterWidget::searchS);
    connect(opt, &QPushButton::released, this, &BoardingFilterWidget::untoggleOptions);
    connect(search_button, &QPushButton::released, this, &BoardingFilterWidget::searchPressed);


    setLayout(vbox);

}



void BoardingFilterWidget::searchAll(){
    sizeChose=all;
    sizeChose->setText("All");
}

void BoardingFilterWidget::searchM(){
    sizeChose=M;
    sizeChose->setText("Medium");
}

void BoardingFilterWidget::searchL(){
    sizeChose=L;
    sizeChose->setText("Large");
}

void BoardingFilterWidget::searchS(){
    sizeChose=S;
    sizeChose->setText("Small");
}

void BoardingFilterWidget::untoggleOptions(){
    diet->setVisible(!diet->isVisible());
    bath->setVisible(!bath->isVisible());
    training->setVisible(!training->isVisible());
    walks->setVisible(!walks->isVisible());

    if(!walks->isVisible())walks->setChecked(false);
    if(!bath->isVisible())bath->setChecked(false);
    if(!diet->isVisible())diet->setChecked(false);
    if(!training->isVisible())training->setChecked(false);
}


void BoardingFilterWidget::searchPressed(){
    emit searchEvent(filterString->text(), sizeChose, bath, walks, diet, training);
}

