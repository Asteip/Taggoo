#include "tag.h"

Tag::Tag(std::string name) : name_(name){

}

std::string Tag::getFile(unsigned int index){
    if(index < fileList_.size()){
        return fileList_[index];
    }
    else{
        return NULL;
    }
}

void Tag::addFile(std::string path){

}

void Tag::removeFile(std::string path){

}

std::string Tag::getName(){
    return name_;
}

void Tag::setName(std::string name){
    name_ = name;
}
