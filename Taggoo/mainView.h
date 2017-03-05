#ifndef MAINVIEW_H
#define MAINVIEW_H

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
    Subject* controller_;
};

#endif // MAINVIEW_H
