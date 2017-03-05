#ifndef MAINVIEW_H
#define MAINVIEW_H

// QT LIBRARY
#include <QWidget>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QLayout>
#include <QSplitter>

#include "observer.h"

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

    // QT OBJECT : Central widget
    QWidget *mainWidget_;
    QWidget *leftWidget_;
    QWidget *centerWidget_;

    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *centerLayout;
};

#endif // MAINVIEW_H
