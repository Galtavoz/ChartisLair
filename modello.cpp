#include "modello.h"

Modello::Modello(std::string p): path(p), Catalogo(new lista<catalogo*>), salvaModifiche(true){}

Modello::~Modello() {
    delete  Catalogo;
}

std::string Modello::getPath() const {
    return path;
}

void Modello::setPath(std::string s) {
    path = s;
    delete Catalogo;
    salvaModifiche = false;
    Catalogo = new lista<catalogo*>();
}

bool Modello::getSalvaModifiche() const {
    return salvaModifiche;
}

lista<catalogo*>* Modello::getListaCatalogo() const {
    return Catalogo;
}

void Modello::setSalvaModifiche(bool s) {
    salvaModifiche = s;
}

lista<catalogo*>::iteratore Modello::inizioIter() const {
    return Catalogo->inizio();
}

lista<catalogo*>::iteratore Modello::fineIter() const {
    return Catalogo->fine();
}

lista<catalogo*>::iteratoreConst Modello::inizioCIter() const {
    return Catalogo->inizioC();
}

lista<catalogo*>::iteratoreConst Modello::fineCIter() const {
    return Catalogo->fineC();
}
