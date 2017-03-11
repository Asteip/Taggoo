#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <string>
#include "observer.h"

/**
 * @brief This class represents an observable object, or "data" in the observer pattern.
 * It can be subclassed to represent an object that the application wants to have observed.
 * @author Alexis, Sitraka.
 */
class Subject : public QObject{

Q_OBJECT

public:
    /**
     * @brief Create an instance of a subject.
     */
    Subject();

    /**
     * @brief Delete a subject.
     */
    virtual ~Subject();

    // PURE VIRTUAL METHODS

    /**
     * @brief Add an observer in the observer's list.
     * @details The observer added in the list is listening to this controller.
     * When an event occur, each observer are notifed of the possible changes of
     * tags lists.
     * @param o The observer added in the observer's list. This parameter
     * is passed by reference.
     */
    virtual void addObserver(Observer &o) = 0;

    /**
     * @brief Delete an observer from the observer's list.
     * @details The observer is not listening ot this controller anymore. So, it
     * will not be notified when future event occur.
     * @param o The observer deleted from the observer's list.
     */
    virtual void removeObserver(Observer &o) = 0;

    /**
     * @brief Notify each observer belonging to the observer's list.
     * @details Call the method refresh of all observer listening to this controller.
     */
    virtual void notify() = 0;

    // TODO comments these methods :

    virtual void readXml() = 0;
    virtual void writeXml() = 0;


public slots:
    // METHODS FOR EACH EVENTS...

};

#endif // SUBJECT_H
