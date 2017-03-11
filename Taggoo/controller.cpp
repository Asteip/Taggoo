#include "controller.h"

Controller::Controller(){
    currentDir_ = "/home"; // a prendre dans le fichier...
    dataFile_ = "../data/data.xml";
}

Controller::~Controller(){

}

void Controller::addObserver(Observer &o){
    observers_.push_back(&o);
}

void Controller::removeObserver(Observer &o){
    observers_.erase(std::remove(observers_.begin(), observers_.end(), &o), observers_.end());
}

void Controller::notify(){
    for(unsigned int i = 0 ; i < observers_.size() ; ++i){
        observers_[i]->refresh();
    }
}

void Controller::readXml(){
    QFile file(dataFile_);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file" << file.errorString();
        return;
    }

    /*XmlDataReader xmlReader(existTags_);

    if (!xmlReader.read(&file))
        qDebug() << "Parse error in file " << xmlReader.errorString();*/
}

void Controller::writeXml(){

}
