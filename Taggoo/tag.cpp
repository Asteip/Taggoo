#include "tag.h"

Tag::Tag(QString name) : name_(name){}

File * Tag::getFile(unsigned int index){
    if(index < files_.size())
        return files_[index];
    else
        return NULL;
}

void Tag::addFile(File *file){
    if(!containsFile(file))
        files_.push_back(file);
}

void Tag::removeFile(File *file){
    files_.erase(std::remove(files_.begin(), files_.end(), file), files_.end());
}

bool Tag::containsFile(File *file){
    return std::find(files_.begin(), files_.end(), file) != files_.end();;
}

int Tag::countFile(){
    return files_.size();
}

QString Tag::getName(){
    return name_;
}

void Tag::setName(QString name){
    name_ = name;
}
