#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <QtXml>
#include <QString>
#include <QDebug>
#include "subject.h"
#include "xmldatareader.h"

/**
 * @brief The controller class is the entry point of the application.
 * @details Every user event go through this class. For example, when
 * a button is clicked from a view, a signal is sent to the controller
 * which perform the process associate to this button. This class
 * implements the pattern Observer, it corresponds to the concrete
 * subject of the pattern. It has different tags lists which should be
 * modified following a user event. Each ovserver of the observer's list
 * are listening to this controller and have to adapt their view when an
 * event occur.
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
     * @brief Add an observer in the observer's list.
     * @details The observer added in the list is listening to this controller.
     * When an event occur, each observer are notifed of the possible changes of
     * tags lists.
     * @param o The observer added in the observer's list. This parameter
     * is passed by reference.
     */
    virtual void addObserver(Observer &o);

    /**
     * @brief Delete an observer from the observer's list.
     * @details The observer is not listening ot this controller anymore. So, it
     * will not be notified when future event occur.
     * @param o The observer deleted from the observer's list.
     */
    virtual void removeObserver(Observer &o);

    /**
     * @brief Notify each observer belonging to the observer's list.
     * @details Call the method refresh of all observer listening to this controller.
     */
    virtual void notify();

public slots:
    // METHODS FOR EACH EVENTS...

private:
    /*
     * Reads the data file.
     */
    virtual void readXml();

    /*
     * Write into the data file.
     */
    virtual void writeXml();

private:
    std::vector<Observer*> observers_; // list of observer listening to the subject
    std::vector<Tag*> usingTags_; // list of current tags used by the filter
    QString currentDir_; // current directory if their is no search in progress

    Data * data_; // persistent data (home directory and tags)
    QString dataFile_; // path of the xml data file for persistence

};

#endif // CONTROLLER_H
