#include "controller.h"

Controller::Controller(){
    dataFile_ = "../data/data.xml";
    data_ = new Data;

    readXml();

    if(data_->getHomePath() != NULL && data_->getHomePath() != "")
        currentDir_ = data_->getHomePath();
    else
        currentDir_ = "/"; // TODO Check for operating system...
}

Controller::~Controller(){
    delete data_;
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

Data * Controller::getData(){

    return NULL;
}

void Controller::createTag(QString name){

}

void Controller::removeTag(QString name){

}

void Controller::setTag(QString name){

}

void Controller::assignTag(QString name, QString file){

}

void Controller::assignTag(QString name, std::vector<QString> files){

}

void Controller::unassignTag(QString name, QString file){

}

void Controller::unassignTag(QString name, std::vector<QString> files){

}

void Controller::searchByTag(std::vector<QString> tags){

}

void Controller::openDirectory(QString name){

}

void Controller::readXml(){
    QFile file(dataFile_);
    XmlDataReader xmlReader(data_);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file " << file.errorString();
        return;
    }

    if (!xmlReader.read(&file))
        qDebug() << "Parse error in file " << xmlReader.errorString();

    file.close();
}

void Controller::writeXml(){
    QFile oldFile(dataFile_);
    QFile newFile(dataFile_ + "~");
    XmlDataWriter xmlWriter(data_);

    if(!newFile.open(QFile::WriteOnly)){
        qDebug() << "Cannot write file " << newFile.errorString();
        return;
    }

    xmlWriter.write(&newFile);

    // In case of crash during the writing operation, the old file and the new file
    // are saved. The old file will be open at the next session.

    oldFile.remove();
    newFile.rename(dataFile_);

    oldFile.close();
    newFile.close();
}













