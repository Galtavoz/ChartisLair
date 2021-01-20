#include"GUI/controller.h"

Controller::Controller(Modello* m,QWidget* p):
    parent(p),
    modello(m),
    catCompleto(new catalogoCompleto(this)),
    file(QFileDialog::getOpenFileName(this,tr("Scegli file"),"../ChartisLair/SALVATAGGIO","File XML(*.xml)")){

    QVBoxLayout* controller = new QVBoxLayout(this);

    setMinimumSize(500,500);
    setWindowTitle("Chartis'Lair");
    setWindowIcon(QIcon("../ChartisLair/IMMAGINI/logo.png"));

    QRect screenGeometry = QGuiApplication::screens()[0]->geometry();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), screenGeometry));

    controller->addWidget(catCompleto);
    caricaDati();
}
void Controller::caricaDati() {
    if(file!="") {
        modello->setPath(file.toStdString());
        modello->Carica();
        abilita();
        if(modello->contaCatalogo()==0) {
            popup* avvisoCarica = new popup("Warning","Attenzione,non sono presenti piatti.");
            avvisoCarica->exec();
        } else {
            lista<catalogo*>::iteratoreConst inizioLista = modello->inizioCIter();
            lista<catalogo*>::iteratoreConst fineLista = modello->fineCIter();

            for(;inizioLista!=fineLista;++inizioLista) {
                catCompleto->getLista()->aggiungiElemento(*inizioLista);
            }
            modello->setSalvaModifiche(true);
        }
    } else {
        disabilita();
        modello->setPath(file.toStdString());
    }
}
void Controller::caricaDatiXML() {
    QString caricaAncora = QFileDialog::getOpenFileName(this,tr("Scegli file"),"../ProgettoP2/SALVATAGGIO","File XML(*.xml)");
    if(caricaAncora!="") {
        modello->setPath(caricaAncora.toStdString());
        modello->Carica();
        abilita();
        if(modello->contaCatalogo()==0) {
            disabilita();
            popup* avvisoCarica = new popup("Warning","Attenzione,non sono presenti piatti. Prova a caricare un altro file!");
            avvisoCarica->exec();
        } else {
            lista<catalogo*>::iteratoreConst inizioLista = modello->inizioCIter();
            lista<catalogo*>::iteratoreConst fineLista = modello->fineCIter();

            /*if(menuSelezionato=="Menu Completo") {
                for(;inizioLista!=fineLista;++inizioLista) {
                    catCompleto->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Sushi") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<sushi*>(const_cast<catalogo*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Udon") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<udon*>(const_cast<catalogo*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Ramen") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<ramen*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else if(menuSelezionato=="Riso Condito") {
                for(;inizioLista!=fineLista;++inizioLista) {
                   if(dynamic_cast<risoCondito*>(const_cast<piatto*>(*inizioLista))) menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            } else {
                for(;inizioLista!=fineLista;++inizioLista) {
                    menuComp->getLista()->aggiungiPiatto(*inizioLista);
                }
            }*/
            for(;inizioLista!=fineLista;++inizioLista) {
                catCompleto->getLista()->aggiungiElemento(*inizioLista);
            }
            modello->setSalvaModifiche(true);
        }
    } else {
        modello->setPath(file.toStdString());
    }
}

Controller::~Controller() {}

Modello* Controller::getModello() const {
    return modello;
}
void Controller::disabilita() {

    catCompleto->hide();

}

void Controller::abilita() {

    catCompleto->show();

}
