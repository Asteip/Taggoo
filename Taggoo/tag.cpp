#include "tag.h"

Tag::Tag(std::string name) : name_(name){}

File * Tag::getFile(unsigned int index){
    if(index < fileList_.size()){
        return fileList_[index];
    }
    else{
        return NULL;
    }
}

void Tag::addFile(File *file){
    if(!containsFile(file)){
        fileList_.push_back(file);
    }
}

void Tag::removeFile(File *file){
    fileList_.erase(std::remove(fileList_.begin(), fileList_.end(), file), fileList_.end());
}

bool Tag::containsFile(File *file){
    return std::find(fileList_.begin(), fileList_.end(), file) != fileList_.end();;
}

std::string Tag::getName(){
    return name_;
}

void Tag::setName(std::string name){
    name_ = name;
}
