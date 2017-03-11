#ifndef FILE_H
#define FILE_H

#include <QString>
/**
 * @brief This class represents a file.
 */
class File{

public:
    /**
     * @brief The file is a directory.
     */
    static const int TYPE_DIRECTORY;

    /**
     * @brief The file is any type of file excepts a directory.
     */
    static const int TYPE_FILE;

    /**
     * @brief Create an instance of File.
     * @param path The path of the file.
     * @param type The type of the file. It must be one of these two types :
     *      -File::TYPE_DIRECTORY
     *      -File::TYPE_FILE
     */
    File(QString path, int type);

    /**
     * @brief Returns the path of the file.
     * @return The string path of the file.
     */
    QString getPath();

    /**
     * @brief Set the path of the file.
     * @param The new path of the file.
     */
    void setPath(QString Path);

    /**
     * @brief Returns the type of the file (Directory or file).
     * @return The type of the file.
     */
    int getType();

    /**
     * @brief Set the type of the file (must be Directory or file).
     * @param The new type of the file.
     */
    void setType(int type);

private:
    QString path_;
    int type_;
};

#endif // FILE_H
