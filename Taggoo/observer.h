#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>
#include <QMainWindow>

class Subject; // allows to fix cyclic dependencies

/**
 * @brief The Observer class is the base class of the different view of the application.
 * @details A class can implement the Observer interface when it wants to be informed
 * of changes in observable objects (classes derived from Subject).
 * @author Alexis, Sitraka.
 */
class Observer : public QMainWindow{

Q_OBJECT

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

protected:
    virtual void createTag() = 0;
    virtual void removeTag() = 0;
    virtual void setTag() = 0;
    virtual void assignTagOne() = 0;
    virtual void assignTagAll() = 0;
    virtual void unassignTagOne() = 0;
    virtual void unassignTagAll() = 0;
    virtual void searchByTag() = 0;
    virtual void openDirectory() = 0;

};

#endif // OBSERVER_H
