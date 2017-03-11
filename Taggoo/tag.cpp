#include "tag.h"

Tag::Tag(QString name) : name_(name){}

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

int Tag::countFile(){
    return fileList_.size();
}

QString Tag::getName(){
    return name_;
}

void Tag::setName(QString name){
    name_ = name;
}
