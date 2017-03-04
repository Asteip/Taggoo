#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <vector>
#include "observer.h"

/**
 * @brief The Subject class.
 * @details
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
     * @brief Add an observer in the observer's list that have to be notify.
     * @param o The observer added in the observer's list.
     */
    virtual void addObserver(Observer &o) = 0;

    /**
     * @brief Delete an observer from the observer's list.
     * @param o The observer deleted from the observer's list.
     */
    virtual void removeObserver(Observer &o) = 0;

    /**
     * @brief Call the method refresh of each observer of the observer's list.
     */
    virtual void notify() = 0;

public slots:
    // METHODS FOR EACH EVENTS...

protected:
    std::vector<Observer*>* observers_;
};

#endif // SUBJECT_H
