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
    mainLayout = new QHBoxLayout;
    leftLayout = new QVBoxLayout;

    mainWidget_ = new QWidget;
    leftWidget_ = new QWidget;
    centerWidget_ = new QWidget;



    /*QWidget *wnd = new QWidget;

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

    wnd->setLayout(layout);

    setCentralWidget(wnd);*/
}

void MainView::createUserEvent(){

}
