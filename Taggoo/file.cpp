#include "file.h"

File::File(std::string path, int type){
    if(type == TYPE_DIRECTORY || type == TYPE_FILE){
        path_ = path;
        type_ = type;
    }
    else{
        // TODO Use exception...
    }
}

std::string File::getPath(){
    return path_;
}

void File::setPath(std::string path){
    path_ = path;
}

int File::getType(){
    return type_;
}

void File::setType(int type){
    if(type == TYPE_DIRECTORY || type == TYPE_FILE){
        type_ = type;
    }
    else{
        // TODO Use exception...
    }
}
