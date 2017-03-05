#ifndef FILE_H
#define FILE_H

#define TYPE_DIRECTORY 0
#define TYPE_FILE 1

#include <string>

/**
 * @brief The File class
 */
class File{

public:
    /**
     * @brief File
     * @param path
     * @param type
     */
    File(std::string path, int type);

    /**
     * @brief getPath
     * @return
     */
    std::string getPath();

    /**
     * @brief setPath
     * @param Path
     */
    void setPath(std::string Path);

    /**
     * @brief getType
     * @return
     */
    int getType();

    /**
     * @brief setType
     * @param type
     */
    void setType(int type);

private:
    std::string path_;
    int type_;
};

#endif // FILE_H
