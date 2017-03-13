#ifndef MAINVIEW_H
#define MAINVIEW_H

// QT LIBRARY
#include <QWidget>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QLayout>
#include <QSplitter>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include <QList>
#include <QFileSystemModel>
#include <QTreeView>

#include "observer.h"
#include "controller.h"

class controller;

/**
 * @brief The MainView class is the main window of the application.
 * @details Represent the main window of the application. This is the
 * first window print to the screen when the application is run. All
 * features of Taggoo can be access by this window.
 * @author Alexis, Sitraka.
 */
class MainView : public Observer, public QMainWindow{

public:
    /**
     * @brief Create a new instance of a MainView.
     * @param subject The subject bound to the view instance.
     */
    MainView(Subject* subject);

    /**
     * @brief Delete the MainView.
     */
    ~MainView();

    // VIRTUAL METHODS

    /**
     * @brief Update all elements of the view.
     */
    virtual void refresh();

private:
    /*
     * Creation of the main widget.
     */
    void createCentralWidget();

    /*
     * Connect signals with controller's slots.
     */
    void createUserEvent();

private:
    Subject* controller_;

    // QT OBJECTS : Central widget

    //main part
    QWidget *mainWidget_;
    QWidget *leftWidget_;
    QWidget *centerWidget_;
    QHBoxLayout *mainLayout_;
    QVBoxLayout *leftLayout_;
    QVBoxLayout *centerLayout_;

    //left part
    QWidget *leftTopWidget_;
    QWidget *leftCenterWidget_;
    QVBoxLayout *leftTopLayout_;
    QVBoxLayout *leftCenterLayout_;

    QLineEdit *researchLineEdit_;
    QPushButton *createTagButton_;
    QList<QPushButton*> listTagButtons_;

    //center part
    QWidget *navigationBarWidget_;
    QScrollArea *selectTagWidget_;
    QWidget *fileSystemWidget_;
    QHBoxLayout *navigationBarLayout_;
    QHBoxLayout *selectTagLayout_;

    QLineEdit *pathLineEdit_;
    QPushButton *currentPathButton_;
    QPushButton *allFilesButton_;
    QPushButton *returnButton_;
    QPushButton *refreshButton_;

    QLabel *labelTags_;

    QFileSystemModel *fileSystemModel_;
    QTreeView *fileSystemTree_;

};

#endif // MAINVIEW_H
