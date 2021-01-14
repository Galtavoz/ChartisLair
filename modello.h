#ifndef MODELLO_H
#define MODELLO_H
#include "gerarchia.h"
#include "container.h"


#include<QFile>
#include<QSaveFile>
#include<QXmlStreamReader>
#include<QDebug>
#include<iostream>

class Modello{
private:
        std::string path;
        lista<catalogo*>* Catalogo;
        bool salvaModifiche;
public:
        Modello(std::string=":/SALVATAGGIO/listaCatalogo.xml");
        ~Modello();

        std::string getPath() const;
        bool getSalvaModifiche() const;
        lista<catalogo*>* getListaCatalogo() const;
        void setSalvaModifiche(bool);
        void setPath(std::string = "");

        lista<catalogo*>::iteratore inizioIter() const;
        lista<catalogo*>::iteratore fineIter() const;
        lista<catalogo*>::iteratoreConst inizioCIter() const;
        lista<catalogo*>::iteratoreConst fineCIter() const;

        void Salva();
        void Carica();

        //std::string toString(char);

        void inserisci(catalogo*);
        void rimuovi(catalogo*);
};
#endif // MODELLO_H

