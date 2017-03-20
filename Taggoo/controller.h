#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <QtXml>
#include <QString>
#include <QDebug>
#include "subject.h"
#include "xmldatareader.h"
#include "xmldatawriter.h"

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

    /**
     * @brief Returns a data object that contains the list of current tag and the current directory
     * @return A tag object
     */
    virtual Data * getData();

    /**
     * @brief Treats the action of create a tag : it creates a new tag in the current list in the data
     * @param name The name of the new tag
     */
    virtual void createTag(QString name);

    /**
     * @brief Treats the action of remove a tag : it removes a tag from the current list in the data
     * @param name The tag which have to be removed
     */
    virtual void removeTag(QString name);

    /**
     * @brief Treats the action of modify a tag in the current list in the data
     * @param name The tag which have to be modified
     */
    virtual void setTag(QString name);

    /**
     * @brief Treats the action of assign a tag to a file : a file is added in the list of file for the concerned tag
     * @param name The name of the tag which is assigned to the file
     * @param file The file we want to be assigned by the tag
     */
    virtual void assignTag(QString name, QString file);

    /**
     * @brief Treats the action of assign a tag to a list of file : all file selected are added in the list of file for the concerned tag
     * @param name The name of the tag which is assigned to the list of file
     * @param files A vector that contains all file we want to be assigned by the tag
     */
    virtual void assignTag(QString name, std::vector<QString> files);

    /**
     * @brief Treats the action of unassign a tag from a file : the file is no longer affected to the tag
     * @param name The name of the tag we want to unassign
     * @param file The file we want to be unassigned by the tag
     */
    virtual void unassignTag(QString name, QString file);

    /**
     * @brief Treats the action of unassign a tag from a list of file : all file selected are removed in the list of file for the concerned tag
     * @param name The name of the tag which is unassigned to the list of file
     * @param files A vector that contains all file we want to be unassigned by the tag
     */
    virtual void unassignTag(QString name, std::vector<QString> files);

    /**
     * @brief Treats the action of searching the files affected by the list of tag gave in parameters
     * @param tags A vector that contains all tag selected by the user
     */
    virtual void searchByTag(std::vector<QString> tags);

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
