#include "controller.h"

Controller::Controller(){

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
