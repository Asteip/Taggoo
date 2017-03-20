#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <QString>
#include <vector>
#include "observer.h"
#include "data.h"

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

    /**
     * @brief Returns a data object that contains the list of current tag and the current directory
     * @return A tag object
     */
    virtual Data * getData() = 0;

    /**
     * @brief Treats the action of create a tag : it creates a new tag in the current list in the data
     * @param name The name of the new tag
     */
    virtual void createTag(QString name) = 0;

    /**
     * @brief Treats the action of remove a tag : it removes a tag from the current list in the data
     * @param name The tag which have to be removed
     */
    virtual void removeTag(QString name) = 0;

    /**
     * @brief Treats the action of modify a tag in the current list in the data
     * @param name The tag which have to be modified
     */
    virtual void setTag(QString name) = 0;

    /**
     * @brief Treats the action of assign a tag to a file : a file is added in the list of file for the concerned tag
     * @param name The name of the tag which is assigned to the file
     * @param file The file we want to be assigned by the tag
     */
    virtual void assignTag(QString name, QString file) = 0;

    /**
     * @brief Treats the action of assign a tag to a list of file : all file selected are added in the list of file for the concerned tag
     * @param name The name of the tag which is assigned to the list of file
     * @param files A vector that contains all file we want to be assigned by the tag
     */
    virtual void assignTag(QString name, std::vector<QString> files) = 0;

    /**
     * @brief Treats the action of unassign a tag from a file : the file is no longer affected to the tag
     * @param name The name of the tag we want to unassign
     * @param file The file we want to be unassigned by the tag
     */
    virtual void unassignTag(QString name, QString file) = 0;

    /**
     * @brief Treats the action of unassign a tag from a list of file : all file selected are removed in the list of file for the concerned tag
     * @param name The name of the tag which is unassigned to the list of file
     * @param files A vector that contains all file we want to be unassigned by the tag
     */
    virtual void unassignTag(QString name, std::vector<QString> files) = 0;

    /**
     * @brief Treats the action of searching the files affected by the list of tag gave in parameters
     * @param tags A vector that contains all tag selected by the user
     */
    virtual void searchByTag(std::vector<QString> tags) = 0;

};

#endif // SUBJECT_H
