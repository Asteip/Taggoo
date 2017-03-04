#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "subject.h"

/**
 * @brief The controller class is the entry point of the application.
 * @details Every user event go through this class. For example, when
 * a button is clicked from a view, a signal is sent to the controller
 * which perform the process associate to this button.
 * @author Alexis, Sitraka.
 */
class Controller : public Subject{

Q_OBJECT

public:
    /**
     * @brief Create an instance of a subject.
     */
    Controller();

    /**
     * @brief Delete a subject.
     */
    ~Controller();

    // VIRTUAL METHODS

    /**
     * @brief Add an observer in the observer's list that have to be notify.
     * @param o The observer added in the observer's list.
     */
    virtual void addObserver(Observer &o);

    /**
     * @brief Delete an observer from the observer's list.
     * @param o The observer deleted from the observer's list.
     */
    virtual void removeObserver(Observer &o);

    /**
     * @brief Call the method refresh of each observer of the observer's list.
     */
    virtual void notify();

public slots:
    // METHODS FOR EACH EVENTS...

private:

};

#endif // CONTROLLER_H
