#include "controller.h"

//POUR LES TESTS
#include <iostream>

Controller::Controller(){
    currentDir_ = "/home";
    xmlTagLink_ = "../data/svg_tag.xml";
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
    QDomDocument *dom = new QDomDocument("svg_tag");

    QFile xml_doc(xmlTagLink_);

    if(!xml_doc.open(QIODevice::ReadOnly)){

        //QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return;
    }
    if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
    {
            xml_doc.close();
            QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
            return;
    }
    xml_doc.close(); // Dans tous les cas, on doit fermer le document XML : on n'en a plus besoin, tout est compris dans l'objet DOM.

}

void Controller::writeXml(){

}
