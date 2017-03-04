#include "subject.h"

Subject::Subject(){
    observers_ = new std::vector<Observer*>();
}

Subject::~Subject(){}

