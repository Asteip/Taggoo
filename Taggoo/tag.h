#ifndef TAG_H
#define TAG_H

#include <string>
#include <vector>
#include <algorithm>
#include "file.h"

/**
 * @brief This class represents a tag.
 * @details A tag is represented by its name and a list of file
 * that have this tag. Files are represented by their absolute path.
 */
class Tag{

public:
    /**
     * @brief Create a tag.
     * @param name The name of the tag. Each name are unique, the name is not
     * sensitive to the case.
     */
    Tag(std::string name);

    /**
     * @brief getFile
     * @param index
     * @return
     */
    File * getFile(unsigned int index);

    /**
     * @brief addFile
     * @param file
     */
    void addFile(File *file);

    /**
     * @brief removeFile
     * @param file
     */
    void removeFile(File *file);

    /**
     * @brief containsFile
     * @param file
     * @return
     */
    bool containsFile(File *file);

    /**
     * @brief getName
     * @return
     */
    std::string getName();

    /**
     * @brief setName
     * @param name
     */
    void setName(std::string name);

private:
    std::string name_;
    std::vector<File*> fileList_;
};

#endif // TAG_H
