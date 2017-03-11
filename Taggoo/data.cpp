#include "data.h"

Data::Data(){
    homePath_ = "";
}

Tag * Data::getTag(unsigned int index){
    if(index < tags_.size())
        return tags_[index];
    else
        return NULL;
}

void Data::addTag(Tag *tag){
    if(!containsTag(tag))
        tags_.push_back(tag);
}

void Data::removeTag(Tag *tag){
    tags_.erase(std::remove(tags_.begin(), tags_.end(), tag), tags_.end());
}

bool Data::containsTag(Tag *tag){
    return std::find(tags_.begin(), tags_.end(), tag) != tags_.end();
}

int Data::countTag(){
    return tags_.size();
}

QString Data::getHomePath(){
    return homePath_;
}

void Data::setHomePath(QString homePath){
    homePath_ = homePath;
}
