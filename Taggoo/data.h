#ifndef DATA_H
#define DATA_H

#include <vector>
#include <algorithm>
#include <QString>
#include "tag.h"

/**
 * @brief The Data class is a structure of persistent data.
 * @author Alexis
 */
class Data{
public:

    /**
     * @brief Create a Data instance.
     */
    Data();

    /**
     * @brief Returns the tag at the specified index.
     * @pre If the index is over than the max range of the list,
     * NULL will be returned.
     * @param index The position of the tag in the list.
     * @return A tag object.
     */
    Tag * getTag(unsigned int index);

    /**
     * @brief Add a tag into the tag list.
     * @param tag The tag added at the end of the list.
     */
    void addTag(Tag *tag);

    /**
     * @brief Remove a tag from the tag list.
     * @param tag The tag removed from the list.
     */
    void removeTag(Tag *tag);

    /**
     * @brief Check if a tag belong to the tag list.
     * @param tag The tag which have to be tested.
     * @return True if the tag is in the list, false otherwise.
     */
    bool containsTag(Tag *tag);

    /**
     * @brief Returns the number of item in the tag list.
     * @return The number of item.
     */
    int countTag();

    /**
     * @brief Returns the home path defined by the user.
     * @details The home path can be any directory defined by user.
     * @return A string which represents a path of the home directory.
     */
    QString getHomePath();

    /**
     * @brief Set the home path.
     * @param homePath The new home path.
     */
    void setHomePath(QString homePath);

private:
    std::vector <Tag*> tags_;
    QString homePath_;
};

#endif // DATA_H
