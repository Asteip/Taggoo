#ifndef TAG_H
#define TAG_H

#include <string>
#include <vector>

class Tag{

public:
    Tag(std::string name);

    std::string getFile(unsigned int index);
    void addFile(std::string path);
    void removeFile(std::string path);

    std::string getName();
    void setName(std::string name);

private:
    std::string name_;
    std::vector<std::string> fileList_;
};

#endif // TAG_H
