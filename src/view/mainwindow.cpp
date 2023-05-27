#include <QPushButton>
#include <QToolBar>
#include <QMenuBar>

#include "mainwindow.h"

#include "breeds/amstaff.h"
#include "breeds/bulldog.h"

#include "sizes/large.h"
#include "sizes/medium.h"
#include "sizes/small.h"

#include "Dog/owner.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow{parent}{

    //Actions
    QAction *newfile = new QAction(QIcon(QPixmap((":/assets/icons8-add-file-48.png"))),"New file");
    QAction *openfile = new QAction(QIcon(QPixmap((":/assets/icons8-folder-48.png"))),"Open file");
    QAction *save = new QAction(QIcon(QPixmap((":/assets/icons8-save-48.png"))),"Save");
    QAction *saveAs = new QAction(QIcon(QPixmap((":/assets/icons8-save-as-48.png"))),"Save as");
    QAction *board = new QAction(QIcon(QPixmap((":/assets/icons8-doge-48.png"))),"Add boarding dog");
    QAction *breed = new QAction(QIcon(QPixmap((":/assets/icons8-puppy-48.png"))),"Add breeding dog");
    QAction *toolb = new QAction(QIcon(QPixmap((":/assets/icons8-invisible-48.png"))),"Toggled toolbar");


    //Menubar
    QMenu *file = menuBar()->addMenu("&File");
    QMenu *addDog = menuBar()->addMenu("&New Dog");
    QMenu *options = menuBar()->addMenu("&View");

    file->addAction(newfile);
    file->addAction(openfile);
    file->addAction(save);
    file->addAction(saveAs);

    addDog->addAction(board);
    addDog->addAction(breed);

    options->addAction(toolb);



    //set up container
    Large* large= new Large();
    Medium* medium= new Medium();
    Small* small= new Small();

    AmStaff* amsatff= new AmStaff();
    Bulldog* bulldog= new Bulldog();

    Owner* ow1= new Owner("Pino", "Daniele", "+39 65165132", 18, 5, 1999, "Piazza Garibaldi", "18");
    Owner* ow2= new Owner("Gennaro", "Bullo", "+39 3698547215", 11, 2, 1984, "Via Falcone Borsellino", "2");
    Owner* ow3= new Owner("Annalisa", "Di Maggio", "+39 3365214895", 31, 1, 1990, "Via XV Luglio", "30");
    Owner* ow4= new Owner("Pino", "Daniele", "+39 65165132", 1, 7, 1996, "Via Brombeis", "1");


    Boarding* guest1= new Boarding(20,4,2023,"Jack",medium,ow1,"Boxer",true, false, true, false);
    Boarding* guest2= new Boarding(20,4,2023,"Pablo",small,ow2,"Pinchir",false, true, false, true);
    Boarding* guest3= new Boarding(20,4,2023,"Zoe",large,ow3,"Cane-lupo cecoslovacco",false, false, false, false);
    Boarding* guest4= new Boarding(20,4,2023,"Maya",small,ow4,"Bassotto",true, true, false, true);


    Breeding* BulFather= new Breeding(19,11,2015, "Pepe", bulldog,true, false, false);
    Breeding* BulMother= new Breeding(5,8,2016, "Vik", bulldog,true, false, false);

    Breeding* Bulpuppie1= new Breeding(20,12,2022, "Bink", bulldog, true, false, true, BulMother, BulFather);
    Breeding* Bulpuppie2= new Breeding(20,12,2022, "Sip", bulldog, true, false, true, BulMother, BulFather);
    Breeding* Bulpuppie3= new Breeding(20,12,2022, "Zip", bulldog, true, true, true, BulMother, BulFather);
    Breeding* Bulpuppie4= new Breeding(20,12,2022, "Ettore", bulldog, true, false, true, BulMother, BulFather);


    Breeding* AmSFather= new Breeding(19,11,2015, "Orio",amsatff, true, false, false);
    Breeding* AmSMother= new Breeding(5,8,2016, "Nida", amsatff, true, false, false);

    Breeding* AmSpuppie1= new Breeding(13,2,2023, "Zil", amsatff, true, true, true ,AmSMother, AmSFather);
    Breeding* AmSpuppie2= new Breeding(13,2,2023, "Paky",amsatff, true, false, true,AmSMother, AmSFather);
    Breeding* AmSpuppie3= new Breeding(13,2,2023, "Chuck", amsatff, true, true, true, AmSMother, AmSFather);
    Breeding* AmSpuppie4= new Breeding(13,2,2023, "Bone", amsatff, true, false, true,AmSMother, AmSFather);



    c.push_back(guest1);
    c.push_back(guest2);
    c.push_back(guest3);
    c.push_back(guest4);

    c.push_back(Bulpuppie1);
    c.push_back(Bulpuppie2);
    c.push_back(Bulpuppie3);
    c.push_back(Bulpuppie4);

    c.push_back(AmSpuppie1);
    c.push_back(AmSpuppie2);
    c.push_back(AmSpuppie3);
    c.push_back(AmSpuppie4);

    c.push_back(BulFather);
    c.push_back(BulMother);
    c.push_back(AmSFather);
    c.push_back(AmSMother);


    //Toolbar
    toolbar = addToolBar("File Toolbar");
    toolbar->addAction(newfile);
    toolbar->addAction(openfile);
    toolbar->addAction(save);
    toolbar->addAction(saveAs);
    toolbar->addAction(breed);
    toolbar->addAction(board);
    toolbar->setIconSize(QSize(32,32));


    //Panel
    general= new GeneralPanel(c);
    breeding= new BreedingPanel(c);
    boarding= new BoardingPanel(c);


    //Tab
    tab_widget= new QTabWidget();
    tab_widget->addTab(general,"General");
    tab_widget->addTab(breeding,"Breeding");
    tab_widget->addTab(boarding,"Boarding");
    setCentralWidget(tab_widget);


}


MainWindow::~MainWindow(){}
