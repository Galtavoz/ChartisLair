#include"GUI/controller.h"

Controller::Controller(Modello* m,QWidget* p):
    parent(p),
    modello(m),
    menu(new Menu(this)),
    ricerca(new Ricerca(this)),
    inserisci(new Inserisci(this)),
    catCompleto(new catalogoCompleto(this)),
    file(QFileDialog::getOpenFileName(this,tr("Scegli file"),"../ChartisLair/SALVATAGGIO","File XML(*.xml)")),
    layoutModifica(new Modifica(this))
{


    QVBoxLayout* controller = new QVBoxLayout(this);

    setMinimumSize(700,500);
    setWindowTitle("Chartis'Lair");
    setWindowIcon(QIcon("../ChartisLair/IMMAGINI/logo.png"));

    QRect screenGeometry = QGuiApplication::screens()[0]->geometry();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), screenGeometry));

    controller->setMenuBar(menu);
    controller->addWidget(catCompleto);
    controller->addWidget(ricerca);
    controller->addWidget(inserisci);
    caricaDati();

    menu->show();
    catCompleto->show();
    ricerca->hide();
    inserisci->hide();

    connect(menu->getEsci(),SIGNAL(triggered()),this,SLOT(esci()));
    connect(menu->getCarica(),SIGNAL(triggered()),this,SLOT(carica()));
    connect(menu->getHome(),SIGNAL(triggered()),this,SLOT(tornaHome()));
    connect(menu->getRicerca(),SIGNAL(triggered()),this,SLOT(vediRicerca()));
    connect(menu->getInserisci(),SIGNAL(triggered()),this,SLOT(vediInserisci()));

    connect(catCompleto->getModifica(),SIGNAL(clicked()),this,SLOT(modifica()));
    connect(catCompleto->getRimuovi(),SIGNAL(clicked()),this,SLOT(rimuoviProdotto()));

    connect(ricerca->getCercaBut(),SIGNAL(clicked()),this,SLOT(ricercaProdotti()));
    connect(ricerca->getRimuoviRicerca(),SIGNAL(clicked()),this,SLOT(rimuoviProdottoRicerca()));
    connect(ricerca->getModificaRicerca(),SIGNAL(clicked()),this,SLOT(modificaRicerca()));

    connect(inserisci->getInserisciBut(),SIGNAL(clicked()),this,SLOT(inserisciNuovoProdotto()));

    connect(layoutModifica->getSalvaMod(),SIGNAL(clicked()),this,SLOT(salvaModifiche()));
}
void Controller::caricaDati() {
    if(file!="") {
        modello->setPath(file.toStdString());
        modello->Carica();
        abilita();
        if(modello->contaCatalogo()==0) {
            popup* avvisoCarica = new popup("Warning","Attenzione,non sono presenti prodotti.");
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

Controller::~Controller() {}

Modello* Controller::getModello() const {
    return modello;
}
void Controller::disabilita() {

    catCompleto->hide();
    menu->getSalva()->setEnabled(false);
    menu->getRicerca()->setEnabled(false);

}

void Controller::abilita() {

    catCompleto->show();
    menu->getSalva()->setEnabled(true);
    menu->getRicerca()->setEnabled(true);

}
bool Controller::controlloDoppione(catalogo* p) const {
    bool controlloDoppio=false;
    lista<catalogo*>* listaCatalogo = modello->getListaCatalogo();
    for(lista<catalogo*>::iteratore cit=listaCatalogo->inizio();cit!=listaCatalogo->fine();++cit) {
        if(*p==(**cit)) {
            controlloDoppio=true;
            return controlloDoppio;
        }
        else controlloDoppio=false;
    }
    return controlloDoppio;
}

void Controller::ricercaProdotti(){
    ricerca->getListaRicerca()->clear();
    //qDebug()<<QString::fromUtf8(ricerca->getTipoProdotto().c_str());
    if(ricerca->getTipoProdotto()=="Seleziona prodotto...") {
        popup* avvisoRicerca = new popup("Critical","Seleziona una tipologia di prodotto da cercare");
        avvisoRicerca->exec();
        ricerca->getListaRicerca()->clear();
        return;
    }
    lista<catalogo*>::iteratoreConst inizio = modello->inizioCIter();
    lista<catalogo*>::iteratoreConst fine = modello->fineCIter();


    if(ricerca->getTipoProdotto()=="Biscotti"){
        for(;inizio!=fine;++inizio) {
           if(dynamic_cast<biscotti*>(*inizio) && (dynamic_cast<biscotti*>(*inizio))->getTipoFarina()==ricerca->getTipoFarina() && (dynamic_cast<biscotti*>(*inizio))->getGocceCioccolata()==ricerca->getTipoGocce()){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<biscotti*>(*inizio) && ricerca->getTipoFarina()==0 && (dynamic_cast<biscotti*>(*inizio))->getGocceCioccolata()==ricerca->getTipoGocce()){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<biscotti*>(*inizio) && ricerca->getTipoGocce()==0 && (dynamic_cast<biscotti*>(*inizio))->getTipoFarina()==ricerca->getTipoFarina()){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<biscotti*>(*inizio) && ricerca->getTipoFarina()==0 && ricerca->getTipoGocce()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
        }
    }
    if(ricerca->getTipoProdotto()=="Cioccolata"){
        for(;inizio!=fine;++inizio) {
           //TUTTI SELEZIONATI
           if(dynamic_cast<cioccolata*>(*inizio) && (dynamic_cast<cioccolata*>(*inizio))->getLivelloFondenza()==ricerca->getLvFondenza() && (dynamic_cast<cioccolata*>(*inizio))->getTipoGranella()==ricerca->getTipoGranella() && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==true && ricerca->getFormaC()==1)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<cioccolata*>(*inizio) && (dynamic_cast<cioccolata*>(*inizio))->getLivelloFondenza()==ricerca->getLvFondenza() && (dynamic_cast<cioccolata*>(*inizio))->getTipoGranella()==ricerca->getTipoGranella() && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==false && ricerca->getFormaC()==2)){
               (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           //SELEZIONATO GRANELLA, SELEZIONATO FONDENZA
           else if(dynamic_cast<cioccolata*>(*inizio) && (dynamic_cast<cioccolata*>(*inizio))->getLivelloFondenza()==ricerca->getLvFondenza() && (dynamic_cast<cioccolata*>(*inizio))->getTipoGranella()==ricerca->getTipoGranella() ){
               (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<cioccolata*>(*inizio) && (dynamic_cast<cioccolata*>(*inizio))->getLivelloFondenza()==ricerca->getLvFondenza() && (dynamic_cast<cioccolata*>(*inizio))->getTipoGranella()==ricerca->getTipoGranella() ){
               (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           //SELEZIONATO GRANELLA, SELEZIONATO FORMA
           else if(dynamic_cast<cioccolata*>(*inizio) && ricerca->getLvFondenza()==0 && (dynamic_cast<cioccolata*>(*inizio))->getTipoGranella()==ricerca->getTipoGranella() && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==true && ricerca->getFormaC()==1)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<cioccolata*>(*inizio) && ricerca->getLvFondenza()==0 && (dynamic_cast<cioccolata*>(*inizio))->getTipoGranella()==ricerca->getTipoGranella() && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==false && ricerca->getFormaC()==2)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }

           //SELEZIONATO FONDENZA, SELEZIONATO FORMA
           else if(dynamic_cast<cioccolata*>(*inizio) && ricerca->getTipoGranella()==0 && dynamic_cast<cioccolata*>(*inizio)->getLivelloFondenza()==ricerca->getLvFondenza() && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==true && ricerca->getFormaC()==1)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<cioccolata*>(*inizio) && ricerca->getTipoGranella()==0 && dynamic_cast<cioccolata*>(*inizio)->getLivelloFondenza()==ricerca->getLvFondenza() && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==false && ricerca->getFormaC()==2)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           //SELEZIONATO SOLO GRANELLA
           else if(dynamic_cast<cioccolata*>(*inizio) && (dynamic_cast<cioccolata*>(*inizio))->getTipoGranella()==ricerca->getTipoGranella() && ricerca->getLvFondenza()==0 && ricerca->getFormaC()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           //SELEZIONATO SOLO FONDENZA
           else if(dynamic_cast<cioccolata*>(*inizio) && (dynamic_cast<cioccolata*>(*inizio))->getLivelloFondenza()==ricerca->getLvFondenza() && ricerca->getTipoGranella()==0 && ricerca->getFormaC()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           //SELEZIONATO SOLO FORMA
           else if(dynamic_cast<cioccolata*>(*inizio) && ricerca->getLvFondenza()==0 && ricerca->getTipoGranella()==0 && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==true && ricerca->getFormaC()==1)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<cioccolata*>(*inizio) && ricerca->getLvFondenza()==0 && ricerca->getTipoGranella()==0 && ((dynamic_cast<cioccolata*>(*inizio))->getForma()==false && ricerca->getFormaC()==2)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           //NESSUN SELEZIONATO
           else if(dynamic_cast<cioccolata*>(*inizio) && ricerca->getTipoGranella()==0 && ricerca->getLvFondenza()==0 && ricerca->getFormaC()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
        }
    }

    if(ricerca->getTipoProdotto()=="Infusi"){
        for(;inizio!=fine;++inizio) {
            //SELEZIONATO SOLO SFUSO
            if(dynamic_cast<infusi*>(*inizio) && ricerca->getAroma()[0]=="0" && ((dynamic_cast<infusi*>(*inizio))->getSfuso()==true && ricerca->getSfuso()==1)){
                 (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            else if(dynamic_cast<infusi*>(*inizio) && ricerca->getAroma()[0]=="0" && ((dynamic_cast<infusi*>(*inizio))->getSfuso()==false && ricerca->getSfuso()==2)){
                 (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }


           //NESSUN SELEZIONATO
           else if(dynamic_cast<infusi*>(*inizio) && ricerca->getAroma()[0]=="0" && ricerca->getSfuso()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
            //TUTTI SELEZIONATI
            else  if(dynamic_cast<infusi*>(*inizio) && ((dynamic_cast<infusi*>(*inizio))->getSfuso()==true && ricerca->getSfuso()==1)){
                std::vector<std::string> stringAroma= ((dynamic_cast<infusi*>(*inizio))->getAroma());
                std::vector<std::string> stringRicerca= ricerca->getAroma();
                for (unsigned int i=0;i<stringAroma.size();++i) {
                     for (unsigned int j=0;j<stringRicerca.size();++j) {
                         if(stringAroma[i]==stringRicerca[j]){
                             (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
                         }
                     }
                }
            }
            else if(dynamic_cast<infusi*>(*inizio) && ((dynamic_cast<infusi*>(*inizio))->getSfuso()==false && ricerca->getSfuso()==2)){
                std::vector<std::string> stringAroma= ((dynamic_cast<infusi*>(*inizio))->getAroma());
                std::vector<std::string> stringRicerca= ricerca->getAroma();
                for (unsigned int i=0;i<stringAroma.size();++i) {
                     for (unsigned int j=0;j<stringRicerca.size();++j) {
                         if(stringAroma[i]==stringRicerca[j]){
                             (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
                         }
                     }
                }
            }
           //SELEZIONATO PRIMO AROMA, SELEZIONATO SECONDO AROMA
           else if(dynamic_cast<infusi*>(*inizio) && ricerca->getSfuso()==0){
               std::vector<std::string> stringAroma= ((dynamic_cast<infusi*>(*inizio))->getAroma());
               std::vector<std::string> stringRicerca= ricerca->getAroma();
               for (unsigned int i=0;i<stringAroma.size();++i) {
                   if(stringRicerca.size()<=1){
                       if(stringAroma.size()==stringRicerca.size()){
                           for (unsigned int j=0;j<stringRicerca.size();++j)
                                if(stringAroma[i]==stringRicerca[j])
                                    (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
                       }
                   }
                   else{
                       if(stringAroma.size()==stringRicerca.size()){
                           for (unsigned int j=0;j<stringRicerca.size()-1;++j)
                                if(stringAroma[i]==stringRicerca[j])
                                    (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
                       }
                   }
               }
           }
        }
    }
    if(ricerca->getTipoProdotto()=="Bong"){
        for(;inizio!=fine;++inizio) {
            //SELEZIONATO QUALSIASI
            if(dynamic_cast<bong*>(*inizio) && ricerca->getFormaB()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO BACKER E QUALSIASI DIMENSIONE
            else if(dynamic_cast<bong*>(*inizio) && ((dynamic_cast<bong*>(*inizio))->getForma()==true && ricerca->getFormaB()==1) && ricerca->getAltezza()==0 && ricerca->getLarghezza()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO DRITTO E QUALSIASI DIMENSIONE
            else if(dynamic_cast<bong*>(*inizio) && ((dynamic_cast<bong*>(*inizio))->getForma()==false && ricerca->getFormaB()==2) && ricerca->getAltezza()==0 && ricerca->getLarghezza()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO BACKER E DIMENSIONE
            else if(dynamic_cast<bong*>(*inizio) && ((dynamic_cast<bong*>(*inizio))->getForma()==true && ricerca->getFormaB()==1) && (dynamic_cast<bong*>(*inizio))->getAltezza()==ricerca->getAltezza() && ricerca->getAltezza()!=0 && ricerca->getLarghezza()!=0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }

            //SELEZIONATO DRITTO E DIMENSIONE
            else if(dynamic_cast<bong*>(*inizio) && ((dynamic_cast<bong*>(*inizio))->getForma()==false && ricerca->getFormaB()==2) && (dynamic_cast<bong*>(*inizio))->getAltezza()==ricerca->getAltezza() && ricerca->getAltezza()!=0 && ricerca->getLarghezza()!=0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
        }
    }
    if(ricerca->getTipoProdotto()=="Vaporizzatore"){
        for(;inizio!=fine;++inizio) {
            //SE SELEZIONATO SOLO SCHERMO
            if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==true && ricerca->getSchermo()==1) && ricerca->getCapienza()==0 && ricerca->getVelocita()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==false && ricerca->getSchermo()==2) && ricerca->getCapienza()==0 && ricerca->getVelocita()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO SCHERMO E QUANTITA
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==true && ricerca->getSchermo()==1) && (dynamic_cast<vaporizzatore*>(*inizio))->getCapienza()==ricerca->getCapienza() && ricerca->getVelocita()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==false && ricerca->getSchermo()==2) && (dynamic_cast<vaporizzatore*>(*inizio))->getCapienza()==ricerca->getCapienza() && ricerca->getVelocita()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO SCHERMO E VELOCITA
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==true && ricerca->getSchermo()==1) && (dynamic_cast<vaporizzatore*>(*inizio))->getVelocitaEvaporazione() && ricerca->getCapienza()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==false && ricerca->getSchermo()==2) && (dynamic_cast<vaporizzatore*>(*inizio))->getVelocitaEvaporazione() && ricerca->getCapienza()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO SOLO QUANTITA
            else if(dynamic_cast<vaporizzatore*>(*inizio) && (dynamic_cast<vaporizzatore*>(*inizio))->getCapienza()==ricerca->getCapienza() && ricerca->getSchermo()==0 && ricerca->getVelocita()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO QUANTITA E VELOCITA
            else if(dynamic_cast<vaporizzatore*>(*inizio) && (dynamic_cast<vaporizzatore*>(*inizio))->getCapienza()==ricerca->getCapienza() && (dynamic_cast<vaporizzatore*>(*inizio))->getVelocitaEvaporazione()==ricerca->getVelocita() && ricerca->getSchermo()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATO SOLO VELOCITA
            else if(dynamic_cast<vaporizzatore*>(*inizio) && (dynamic_cast<vaporizzatore*>(*inizio))->getVelocitaEvaporazione()==ricerca->getVelocita() && ricerca->getSchermo()==0 && ricerca->getCapienza()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //SELEZIONATI TUTTI
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==true && ricerca->getSchermo()==1) && (dynamic_cast<vaporizzatore*>(*inizio))->getCapienza()==ricerca->getCapienza() && (dynamic_cast<vaporizzatore*>(*inizio))->getVelocitaEvaporazione()==ricerca->getVelocita()){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ((dynamic_cast<vaporizzatore*>(*inizio))->getSchermo()==false && ricerca->getSchermo()==2) && (dynamic_cast<vaporizzatore*>(*inizio))->getCapienza()==ricerca->getCapienza() && (dynamic_cast<vaporizzatore*>(*inizio))->getVelocitaEvaporazione()==ricerca->getVelocita()){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
            //NESSUN SELEZIONATO
            else if(dynamic_cast<vaporizzatore*>(*inizio) && ricerca->getVelocita()==0 && ricerca->getSchermo()==0 && ricerca->getCapienza()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
            }
        }
    }
    if(ricerca->getTipoProdotto()=="Grinder"){
        for(;inizio!=fine;++inizio) {
           if(dynamic_cast<grinder*>(*inizio) && (dynamic_cast<grinder*>(*inizio))->getNdenti()==ricerca->getNDenti() && ((dynamic_cast<grinder*>(*inizio))->getRaccogliPolline()==true && ricerca->getRaccogliP()==1)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<grinder*>(*inizio) && (dynamic_cast<grinder*>(*inizio))->getNdenti()==ricerca->getNDenti() && ((dynamic_cast<grinder*>(*inizio))->getRaccogliPolline()==false && ricerca->getRaccogliP()==2)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<grinder*>(*inizio) && ricerca->getNDenti() ==0 && ((dynamic_cast<grinder*>(*inizio))->getRaccogliPolline()==true && ricerca->getRaccogliP()==1)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<grinder*>(*inizio) && ricerca->getNDenti() ==0 && ((dynamic_cast<grinder*>(*inizio))->getRaccogliPolline()==false && ricerca->getRaccogliP()==2)){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<grinder*>(*inizio) && (dynamic_cast<grinder*>(*inizio))->getNdenti()==ricerca->getNDenti() && ricerca->getRaccogliP()==0){
               (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
           else if(dynamic_cast<grinder*>(*inizio) && ricerca->getRaccogliP() ==0 && ricerca->getNDenti()==0){
                (ricerca->getListaRicerca())->aggiungiElemento(*inizio);
           }
        }
    }
    if(ricerca->getListaRicerca()->count()==0){
        popup* avvisoNonTrovato = new popup("Warning","Prodotto cercato non presente in catalogo");
        avvisoNonTrovato->exec();
        return;
    }
}

void Controller::modifica(){
    if(catCompleto->getLista()->currentItem()==nullptr){
        popup* nessunProdottoSelezionato= new popup("Warning","Nessun prodotto selezioanto, seleziona un prodotto da modificare");
        nessunProdottoSelezionato->exec();
    }
    else{
        layoutModifica->setProdotto(catCompleto->getLista()->currentItem()->getSelezionato());
        layoutModifica->compilaModifica();
        layoutModifica->exec();
    }
}
void Controller::modificaRicerca() {
    if(ricerca->getListaRicerca()->currentItem()==nullptr) {
        popup* nessunProdottoSelezionato = new popup("Warning","Nessun prodotto selezionato, seleziona un prodotto da modificare!");
        nessunProdottoSelezionato->exec();
    }
    else {
        layoutModifica->setProdotto(ricerca->getListaRicerca()->currentItem()->getSelezionato());
        layoutModifica->compilaModifica();
        layoutModifica->exec();
    }
}
//SLOTS
void Controller::esci() {
    close();
}
void Controller::carica() {
    caricaDatiXML();
}
void Controller::tornaHome(){
    ricerca->getListaRicerca()->clear();
    ricerca->hide();
    catCompleto->show();
    inserisci->hide();
    ricerca->resetRicerca();
    inserisci->resetInserisci();
}
void Controller::vediRicerca(){
    ricerca->getListaRicerca()->clear();
    catCompleto->hide();
    ricerca->show();
    inserisci->hide();
    inserisci->resetInserisci();
}
void Controller::vediInserisci(){
    ricerca->getListaRicerca()->clear();
    catCompleto->hide();
    ricerca->hide();
    inserisci->resetInserisci();
    inserisci->show();
    ricerca->resetRicerca();
}
void Controller::vediInfoSviluppatore() {
    popup* informazioni = new popup("Informazione","Progetto realizzato da: Galtarossa Marco. Numero di matricola 1096393.\n Per qualsiasi necessità"
                                                     " contattare tramite email: \n marco.galtarossa.2@studenti.unipd.it");
    informazioni->exec();
}

void Controller::vediInfoCatalogo() {
    int totale = modello->contaCatalogo();
    int biscotti = modello->contaBiscotti();
    int cioccolata = modello->contaCioccolata();
    int infusi = modello->contaInfusi();
    int bong = modello->contaBong();
    int vapo = modello->contaVapo();
    int grinder = modello->contaGrinder();
    QString info = "Il numero totale dei prodotti in magazzino è ";
    info.append(QString::number(totale));
    info.append("\n Il numero di confezioni di biscotti disponibili è ");
    info.append(QString::number(biscotti));
    info.append("\n Il numero di confezioni di cioccolata disponibili è ");
    info.append(QString::number(cioccolata));
    info.append("\n Il numero di confezioni di infuso disponibili è ");
    info.append(QString::number(infusi));
    info.append("\n Il numero di bong disponibili è ");
    info.append(QString::number(bong));
    info.append("\n Il numero di vaporizzatori disponibili è ");
    info.append(QString::number(vapo));
    info.append("\n Il numero di grinder disponibili è ");
    info.append(QString::number(grinder));
    popup* informazioni = new popup("Informazione",info);
    informazioni->exec();
}
void Controller::inserisciNuovoProdotto(){
    catalogo* daInserire = inserisci->nuovoProdotto();
    if (controlloDoppione(daInserire)) {
            popup* prodottoDoppione = new popup("Warning","Prodotto doppione,hai già creato un prodotto così!");
            prodottoDoppione->exec();
    }
    else{
        modello->inserisci(daInserire);
        modello->Salva();
        catCompleto->getLista()->clear();
        caricaDati();
        inserisci->hide();
        catCompleto->show();
    }
}
void Controller::salvaModifiche(){
    layoutModifica->setNuoviCampi();
    modello->Salva();
    catCompleto->getLista()->clear();
    caricaDati();
    catCompleto->show();
    ricerca->hide();
    inserisci->hide();
    layoutModifica->close();
    popup* avvisoModifica= new popup("Informazione","Modifica avvenuta con successo");
    avvisoModifica->exec();
}
void Controller::rimuoviProdotto(){
    if(catCompleto->getLista()->currentItem()==nullptr) {
            popup* nessunProdottoSelezionatoElimina = new popup("Warning","Nessun prodotto selezionato, seleziona un prodotto da eliminare!");
            nessunProdottoSelezionatoElimina->exec();
     }
     else {
        modello->rimuovi(catCompleto->getLista()->currentItem()->getSelezionato());
        modello->Salva();
        catCompleto->getLista()->clear();
        caricaDati();
        vediInfoCatalogo();
        if(modello->contaCatalogo()!=0) {
        popup* eliminatoCorrettamente = new popup("Informazione","Prodotto eliminato correttamente!");
        eliminatoCorrettamente->exec();
        }
        else {
           menu->show();
           catCompleto->hide();
        }
     }
}
void Controller::rimuoviProdottoRicerca() {
    if(ricerca->getListaRicerca()->currentItem()==nullptr) {
        popup* nessunProdottoSelezionatoElimina = new popup("Warning","Nessun prodotto selezionato, seleziona un prodotto da eliminare!");
        nessunProdottoSelezionatoElimina->exec();
    }
    else {
        modello->rimuovi(ricerca->getListaRicerca()->currentItem()->getSelezionato());
        modello->Salva();
        ricerca->resetRicerca();
        catCompleto->getLista()->clear();
        caricaDati();
        tornaHome();
        if(modello->contaCatalogo()!=0) {
        popup* eliminatoCorrettamente = new popup("Informazione","Prodotto eliminato correttamente!");
        eliminatoCorrettamente->exec();
        }
        else {
            ricerca->show();
            catCompleto->hide();
        }
    }
}

