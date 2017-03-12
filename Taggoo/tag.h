#ifndef TAG_H
#define TAG_H

#include <vector>
#include <algorithm>
#include <QString>
#include "file.h"

/**
 * @brief This class represents a tag.
 * @details A tag is represented by its name and a list of file
 * that are bound to this tag.
 * @author Alexis
 */
class Tag{

public:
    /**
     * @brief Create a tag.
     * @param name The name of the tag. Each name is unique.
     */
    Tag(QString name);

    /**
     * @brief Returns the file at the specified position.
     * @param index The position of the file in the list of files.
     * @return An object file. Null if the file is not found.
     */
    File * getFile(unsigned int index);

    /**
     * @brief Add a file in the list of files if it not already exists.
     * @param file The file object passed by pointer.
     */
    void addFile(File *file);

    /**
     * @brief Remove a file from the list of files. If the file does not exists,
     * nothing happen.
     * @param file The file object passed by pointer.
     */
    void removeFile(File *file);

    /**
     * @brief Check if the list of files contains the file.
     * @param file The file object passed by pointer.
     * @return True if the file exists, false otherwise.
     */
    bool containsFile(File *file);

    /**
     * @brief Returns the number of file.
     * @return The size of the list of files.
     */
    int countFile();

    /**
     * @brief Returns the name of the tag.
     * @return The name of the tag.
     */
    QString getName();

    /**
     * @brief Modify the name of the tag.
     * @param name The new name of the tag.
     */
    void setName(QString name);

private:
    QString name_;
    std::vector<File*> files_;
};

#endif // TAG_H
