#include "file.h"

const int File::TYPE_DIRECTORY = 0;
const int File::TYPE_FILE = 1;

File::File(QString path, int type){
    if(type == File::TYPE_DIRECTORY || type == File::TYPE_FILE){
        path_ = path;
        type_ = type;
    }
    else{
        // TODO Use exception...
    }
}

QString File::getPath(){
    return path_;
}

void File::setPath(QString path){
    path_ = path;
}

int File::getType(){
    return type_;
}

void File::setType(int type){
    if(type == File::TYPE_DIRECTORY || type == File::TYPE_FILE){
        type_ = type;
    }
    else{
        // TODO Use exception...
    }
}
