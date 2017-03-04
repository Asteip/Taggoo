#ifndef OBSERVER_H
#define OBSERVER_H

#include <QMainWindow>

class Subject; // fix cyclic dependencies

/**
 * @brief The Observer class is the base class of the different view of the application.
 * @details
 * @author Alexis, Sitraka.
 */
class Observer{

public:
    /**
     * @brief Create a new instance of an observer.
     * @param subject The subject bound to the observer instance.
     */
    Observer(Subject* subject);

    /**
     * @brief Delete an observer.
     */
    virtual ~Observer();

    // PURE VIRTUAL METHODS

    /**
     * @brief Update all elements of an observer.
     * @details In the case of a view, update all elements display by
     * the window.
     */
    virtual void refresh() = 0;

protected :
    Subject* controller_;
};

#endif // OBSERVER_H
