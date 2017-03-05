#ifndef OBSERVER_H
#define OBSERVER_H

class Subject; // fix cyclic dependencies

/**
 * @brief The Observer class is the base class of the different view of the application.
 * @details A class can implement the Observer interface when it wants to be informed
 * of changes in observable objects (classes derived from Subject).
 * @author Alexis, Sitraka.
 */
class Observer{

public:
    /**
     * @brief Create a new instance of an observer.
     */
    Observer();

    /**
     * @brief Delete an observer.
     */
    virtual ~Observer();

    // PURE VIRTUAL METHODS

    /**
     * @brief Update all elements of an observer.
     * @details In the case of a view, update all elements display by the window.
     */
    virtual void refresh() = 0;

};

#endif // OBSERVER_H
