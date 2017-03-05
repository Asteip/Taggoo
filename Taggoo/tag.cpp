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
        if(freeIndexes_.empty()){
            fileList_.push_back(file);
        }
        else{
            fileList_[freeIndexes_.back()] = file;
            freeIndexes_.pop_back();
        }

    }
}

void Tag::removeFile(File *file){
    bool find = false;
    unsigned int i = 0;

    while(i < fileList_.size() && !find){
        if(fileList_[i]->getPath() == file->getPath() && fileList_[i]->getType() == file->getType()){
            find = true;
            fileList_[i] = NULL;
            freeIndexes_.push_back(i);
        }

        ++i;
    }
}

bool Tag::containsFile(File *file){
    bool find = false;
    unsigned int i = 0;

    while(i < fileList_.size() && !find){
        if(fileList_[i]->getPath() == file->getPath() && fileList_[i]->getType() == file->getType())
            find = true;

        ++i;
    }

    return find;
}

std::string Tag::getName(){
    return name_;
}

void Tag::setName(std::string name){
    name_ = name;
}
