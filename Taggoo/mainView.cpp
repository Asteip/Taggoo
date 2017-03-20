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

    QSplitter *splitter = new QSplitter();

    //MAIN PART
    mainWidget_ = new QWidget;
    leftWidget_ = new QWidget;
    centerWidget_ = new QWidget;
    mainLayout_ = new QHBoxLayout;
    leftLayout_ = new QVBoxLayout;
    centerLayout_ = new QVBoxLayout;

    mainWidget_->setLayout(mainLayout_);
    leftWidget_->setLayout(leftLayout_);
    centerWidget_->setLayout(centerLayout_);

    splitter->addWidget(leftWidget_);
    splitter->addWidget(centerWidget_);

    mainLayout_->addWidget(splitter);
    setCentralWidget(mainWidget_);

    //LEFT PART
    leftTopWidget_ = new QWidget;
    leftCenterWidget_ = new QWidget;
    leftTopLayout_ = new QVBoxLayout;
    leftCenterLayout_ = new QVBoxLayout;

    leftTopWidget_->setLayout(leftTopLayout_);
    leftCenterWidget_->setLayout(leftCenterLayout_);

    researchLineEdit_ = new QLineEdit;
    researchLineEdit_->setPlaceholderText("Rechercher un tag...");
    createTagButton_ = new QPushButton(QIcon("../img/add.png")," Créer un tag");

    leftTopLayout_->addWidget(researchLineEdit_);
    leftTopLayout_->addWidget(createTagButton_);

    scrollTagArea_ = new QScrollArea;
    scrollTagArea_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollTagArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollTagArea_->setWidgetResizable(true);

    for (int i = 0 ; i < controller_->getData()->countTag() ; ++i){
        QHBoxLayout *tagLayout = new QHBoxLayout;
        QWidget *tagWidget = new QWidget;

        QPushButton *tagButton = new QPushButton(controller_->getData()->getTag(i)->getName());
        QPushButton *editButton = new QPushButton(QIcon("../img/edit.png"),"");
        QPushButton *deleteButton = new QPushButton(QIcon("../img/delete.png"),"");
        QPushButton *addTagButton = new QPushButton(QIcon("../img/add.png"), "");
        addTagButton->setDisabled(true);

        tagLayout->addWidget(tagButton);
        tagLayout->addWidget(addTagButton);
        tagLayout->addWidget(editButton);
        tagLayout->addWidget(deleteButton);

        tagWidget->setLayout(tagLayout);

        listTagWidget_.push_back(tagWidget);
        listTagButtons_.push_back(tagButton);
        listEditButtons_.push_back(editButton);
        listDeleteButtons_.push_back(deleteButton);
        listAddTagButtons_.push_back(addTagButton);

        leftCenterLayout_->addWidget(tagWidget);
    }

    scrollTagArea_->setWidget(leftCenterWidget_);
    leftLayout_->addWidget(leftTopWidget_);
    leftLayout_->addWidget(scrollTagArea_);

    //CENTER PART
    navigationBarWidget_ = new QWidget;
    selectTagWidget_ = new QScrollArea;
    fileSystemWidget_ = new QWidget;
    navigationBarLayout_ = new QHBoxLayout;
    selectTagLayout_ = new QHBoxLayout;

    navigationBarWidget_->setLayout(navigationBarLayout_);
    selectTagWidget_->setLayout(selectTagLayout_);

    //navigationBarWidget
    pathLineEdit_ = new QLineEdit;
    pathLineEdit_->setText("/home");
    currentPathButton_ = new QPushButton("home");
    allFilesButton_ = new QPushButton("All Files");
    returnButton_ = new QPushButton(QIcon("../img/61449.png"),"");
    refreshButton_ = new QPushButton(QIcon("../img/refresh.png"),"");

    navigationBarLayout_->addWidget(pathLineEdit_);
    navigationBarLayout_->addWidget(currentPathButton_);
    navigationBarLayout_->addWidget(allFilesButton_);
    navigationBarLayout_->addWidget(returnButton_);
    navigationBarLayout_->addWidget(refreshButton_);

    //selectTagWidget
    labelTags_ = new QLabel("Tag du (des) fichier(s) sélectioné(s) :") ;
    selectTagLayout_->addWidget(labelTags_);

    //fileSystemWidget
    fileSystemModel_ = new QFileSystemModel;
    fileSystemModel_->setRootPath(QDir::currentPath());

    fileSystemTree_ = new QTreeView(fileSystemWidget_);
    fileSystemTree_->setModel(fileSystemModel_);

    centerLayout_->addWidget(navigationBarWidget_);
    centerLayout_->addWidget(selectTagWidget_);
    centerLayout_->addWidget(fileSystemTree_);
}

void MainView::createUserEvent(){
    connect(createTagButton_, SIGNAL(clicked()), this, SLOT(createTag()));

    for(int i = 0 ; i < listTagButtons_.size() ; ++i){
        connect(listTagButtons_.at(i), SIGNAL(clicked()), this, SLOT(searchByTag()));
        connect(listEditButtons_.at(i), SIGNAL(clicked()), this, SLOT(setTag()));
        connect(listDeleteButtons_.at(i), SIGNAL(clicked()), this, SLOT(removeTag()));
        connect(listAddTagButtons_.at(i), SIGNAL(clicked()), this, SLOT(assignTagOne()));
    }
}

void MainView::createTag(){
    bool ok = false;
    QString tagName = QInputDialog::getText(this, "Nouveau tag", "Nom : ", QLineEdit::Normal, QString(), &ok);

    if(ok){
        if(!tagName.isEmpty())
            controller_->createTag(tagName);
        else
            QMessageBox::critical(this, "Nouveau tag", "Erreur nom incorrect.");
    }

    QHBoxLayout *tagLayout = new QHBoxLayout;
    QWidget *tagWidget = new QWidget;

    QPushButton *tagButton = new QPushButton(tagName);
    QPushButton *editButton = new QPushButton(QIcon("../img/edit.png"),"");
    QPushButton *deleteButton = new QPushButton(QIcon("../img/delete.png"),"");
    QPushButton *addTagButton = new QPushButton(QIcon("../img/add.png"), "");
    addTagButton->setDisabled(true);

    tagLayout->addWidget(tagButton);
    tagLayout->addWidget(addTagButton);
    tagLayout->addWidget(editButton);
    tagLayout->addWidget(deleteButton);

    tagWidget->setLayout(tagLayout);

    listTagWidget_.push_back(tagWidget);
    listTagButtons_.push_back(tagButton);
    listEditButtons_.push_back(editButton);
    listDeleteButtons_.push_back(deleteButton);
    listAddTagButtons_.push_back(addTagButton);

    leftCenterLayout_->addWidget(tagWidget);

    scrollTagArea_->adjustSize();
    scrollTagArea_->repaint();
}

void MainView::removeTag(){
    QPushButton *sender = (QPushButton*) QObject::sender();
    int index = listDeleteButtons_.lastIndexOf(sender);
    QString name = listTagButtons_.at(index)->text();

    controller_->removeTag(name);

    listTagWidget_.at(index)->setLayout(NULL);
    leftCenterLayout_->removeWidget(listTagWidget_.at(index));

    listTagWidget_.removeAt(index);
    listTagButtons_.removeAt(index);
    listEditButtons_.removeAt(index);
    listDeleteButtons_.removeAt(index);
    listAddTagButtons_.removeAt(index);

    scrollTagArea_->adjustSize();
    scrollTagArea_->repaint();

    this->repaint();
}

void MainView::setTag(){

}

void MainView::assignTagOne(){

}

void MainView::assignTagAll(){

}

void MainView::unassignTagOne(){

}

void MainView::unassignTagAll(){

}

void MainView::searchByTag(){

}


