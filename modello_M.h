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
        lista<deepPtr<catalogo*>>* Catalogo;
        bool salvaModifiche;
public:
        Modello(std::string=":/SALVATAGGIO/listaCatalogo.xml");
        ~Modello();

        std::string getPath() const;
        bool getSalvaModifiche() const;
        lista<deepPtr<catalogo*>>* getListaCatalogo() const;
        void setSalvaModifiche(bool);
        void setPath(std::string = "");

        lista<deepPtr<catalogo*>>::iteratore inizioIter() const;
        lista<deepPtr<catalogo*>>::iteratore fineIter() const;
        lista<deepPtr<catalogo*>>::iteratoreConst inizioCIter() const;
        lista<deepPtr<catalogo*>>::iteratoreConst fineCIter() const;

        void Salva();
        void Carica();

        std::string toString(char);

        void inserisci(deepPtr<catalogo*>);
        void rimuovi(catalogo*);
        int contaCatalogo();
        int contaBiscotti();
        int contaCioccolata();
        int contaInfusi();
        int contaBong();
        int contaVapo();
        int contaGrinder();
};
#endif // MODELLO_H

