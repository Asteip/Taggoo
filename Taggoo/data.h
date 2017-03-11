#ifndef DATA_H
#define DATA_H

#include <vector>
#include <algorithm>
#include <QString>
#include "tag.h"

/**
 * @brief The Data class is a structure of persistent data.
 */
class Data{
public:

    /**
     * @brief Create a Data instance.
     */
    Data();

    /**
     * @brief getTag
     * @param index
     * @return
     */
    Tag * getTag(unsigned int index);

    /**
     * @brief addTag
     * @param tag
     */
    void addTag(Tag *tag);

    /**
     * @brief removeTag
     * @param tag
     */
    void removeTag(Tag *tag);

    /**
     * @brief containsTag
     * @param tag
     * @return
     */
    bool containsTag(Tag *tag);

    /**
     * @brief countTag
     * @return
     */
    int countTag();

    /**
     * @brief getHomePath
     * @return
     */
    QString getHomePath();

    /**
     * @brief setHomePath
     * @param homePath
     */
    void setHomePath(QString homePath);

private:
    std::vector <Tag*> tags_;
    QString homePath_;
};

#endif // DATA_H
