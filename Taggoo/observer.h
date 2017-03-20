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

protected slots:

    /**
     * @brief Add a new tag on the gui. Call the method createTag of controller
     */
    virtual void createTag() = 0;

    /**
     * @brief Remove a tag on the gui. Call the method removeTag of controller
     */
    virtual void removeTag() = 0;

    /**
     * @brief Modify a tag on the gui. Call the method setTag of controller
     */
    virtual void setTag() = 0;

    /**
      @brief Add a tag in the list of assigned tag for a file. Call the method assignTag of controller
     */
    virtual void assignTagOne() = 0;

    /**
     * @brief Add a tag int the list of assigned tag for a list of file. Call the method assignTag of controller
     */
    virtual void assignTagAll() = 0;

    /**
     * @brief Remove a tag in the list of assigned tag for a file. Call the method unassignTag of controller
     */
    virtual void unassignTagOne() = 0;

    /**
     * @brief Remove a tag int the list of assigned tag for a list of file. Call the method unassignTag of controller
     */
    virtual void unassignTagAll() = 0;

    /**
     * @brief Display the result search interface with the list of file that correspond to the research. Call searchByTag in the controller
     */
    virtual void searchByTag() = 0;

};

#endif // OBSERVER_H
