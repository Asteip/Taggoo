#include "mainView.h"

MainView::MainView(Subject* subject) : controller_(subject){
    setWindowTitle("Taggoo");
    setMinimumWidth(800);

    /* Centralize the window on the screen */
    QDesktopWidget desktop;
    QRect desktopArea = desktop.screenGeometry();
    int x = desktopArea.width()/2 - width()/2;
    int y = desktopArea.height()/2 - height()/2;
    move(x,y);

    createCentralWidget();
    createUserEvent();
    show();
}

MainView::~MainView(){}

void MainView::refresh(){

}

void MainView::createCentralWidget(){
    mainWidget_ = new QWidget;
    leftWidget_ = new QWidget;
    centerWidget_ = new QWidget;


    mainLayout = new QHBoxLayout;
    leftLayout = new QVBoxLayout;
    centerLayout = new QVBoxLayout;

    leftWidget_->setLayout(leftLayout);
    centerWidget_->setLayout(centerLayout);

    QSplitter *splitter = new QSplitter();
    splitter->addWidget(leftWidget_);
    splitter->addWidget(centerWidget_);





    //left part
    QLineEdit *researchLineEdit = new QLineEdit;
    researchLineEdit->setPlaceholderText("Rechercher un tag...");
    QPushButton *bouton = new QPushButton(QIcon("../img/add.png"),"Créer un tag");
    leftLayout->addWidget(researchLineEdit);
    leftLayout->addWidget(bouton);

    //center part

    QHBoxLayout *navigationLayout = new QHBoxLayout;
    centerLayout->addLayout(navigationLayout);
    QLineEdit *pathLineEdit = new QLineEdit;
    pathLineEdit->setPlaceholderText("/home");
    QPushButton *currentPathButton = new QPushButton("home");
    QPushButton *allFilesButton = new QPushButton("All Files");
    QPushButton *returnButton = new QPushButton(QIcon("../img/61449.png"),"");
    QPushButton *refreshButton = new QPushButton(QIcon("../img/refresh.png"),"");
    navigationLayout->addWidget(pathLineEdit);
    navigationLayout->addWidget(currentPathButton);
    navigationLayout->addWidget(allFilesButton);
    navigationLayout->addWidget(returnButton);
    navigationLayout->addWidget(refreshButton);

    QLabel *labelTags = new QLabel("Tag du (des) fichier(s) sélectioné(s) :") ;
    centerLayout->addWidget(labelTags);

    QWidget *fileTags = new QScrollArea();
    centerLayout->addWidget(fileTags);






    /*

    QWidget *wnd = new QWidget;

    QTextEdit *editor1 = new QTextEdit;
    QTextEdit *editor2 = new QTextEdit;
    QTextEdit *editor3 = new QTextEdit;

    QSplitter *split1 = new QSplitter;
    QSplitter *split2 = new QSplitter;

    QVBoxLayout *layout = new QVBoxLayout;

    QWidget *container = new QWidget;
    QVBoxLayout *container_layout = new QVBoxLayout;

    split1->addWidget(editor1);
    split1->addWidget(editor2);

    container_layout->addWidget(split1);
    container->setLayout(container_layout);

    split2->setOrientation(Qt::Vertical);
    split2->addWidget(container);
    split2->addWidget(editor3);

    layout->addWidget(split2);

    wnd->setLayout(layout);*/

    /*mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(centerLayout);
    */
    mainLayout->addWidget(splitter);
    mainWidget_->setLayout(mainLayout);
    setCentralWidget(mainWidget_);
}

void MainView::createUserEvent(){

}
