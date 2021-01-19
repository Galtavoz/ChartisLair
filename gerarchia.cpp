#include "gerarchia.h"

//CATALOGO
catalogo::catalogo(std::string n,bool cr):
    nome(n), confezioneRegalo(cr){}
//GET
std::string catalogo::getNome() const{
    return nome;
}
bool catalogo::getConfezioneRegalo() const{
    return confezioneRegalo;
}
//SET
std::string catalogo::setNome(std::string n){
    return nome=n;
}
bool catalogo::setConfezioneRegalo(bool flag){
    return confezioneRegalo=flag;
}






//CONSUMABILI
consumabile::consumabile(std::string n,bool cr,std::vector<std::string> ingr,double p,bool erb,bool prod):
    catalogo(n,cr),ingredienti(ingr), peso(p),erba(erb),produzione(prod){}
//GET
std::vector<std::string> consumabile::getIngredienti() const{
    return ingredienti;
}
double consumabile::getPeso() const{
    return peso;
}
bool consumabile::getErba() const{
    return erba;
}
bool consumabile::getProduzione() const{
    return produzione;
}
//SET
void consumabile::setIngredienti(std::string ing){
    for(unsigned int i=0;i<ingredienti.size();++i){
        if(ing==ingredienti[i]) return;
    }
    ingredienti.push_back(ing);
    return;
}
double consumabile::setPeso(double p){
    return peso=p;
}
bool consumabile::setErba(bool flag){
    return erba=flag;
}
bool consumabile::setProduzione(bool flag){
    return produzione=flag;
}







//BISCOTTI
biscotti::biscotti(std::string n,bool cr,std::vector<std::string> ingr,double p,bool erb,bool prod,int tf,int gc):
  consumabile(n,cr,ingr,p,erb,prod),tipoFarina(tf),gocceCioccolata(gc){}
//GET
int biscotti::getTipoFarina() const{
    return tipoFarina;
}
int biscotti::getGocceCioccolata() const{
    return gocceCioccolata;
}
//SET
int biscotti::setTipoFarina(int tf){
    return tipoFarina=tf;
}
int biscotti::setGocceCioccolata(int gc){
    return gocceCioccolata=gc;
}
//METODI
double biscotti::prezzo() const{
    double conto=100*getPeso();
    if(tipoFarina==1) conto+=getPeso()*0.99;
    else if (tipoFarina==2)conto+=getPeso()*5;
    else if (tipoFarina==3)conto+=getPeso()*20;
    else if (tipoFarina==4)conto+=getPeso()*24;
    else conto+=getPeso()*9;

    if(gocceCioccolata==1) conto+=6.20;
    else if (gocceCioccolata==2)conto+=5.99;
    else if (gocceCioccolata==3)conto+=5.50;

    return conto;
}

double biscotti::ricavo() const{
    return (prezzo()/100)*30;
}

std::string  biscotti::tipoElemento() const{
    return "biscotti";
}








//CIOCCOLATA
cioccolata::cioccolata(std::string n,bool cr,std::vector<std::string> ingr,double p,bool erb,bool prod,int tg,int lvf,bool forma):
    consumabile(n,cr,ingr,p,erb,prod),tipoGranella(tg),livelloFondenza(lvf),forma(forma){}
//GET
int cioccolata::getTipoGranella() const{
    return tipoGranella;
}
int cioccolata::getLivelloFondenza() const{
    return livelloFondenza;
}
bool cioccolata::getForma() const{
    return forma;
}
//SET
int cioccolata::setTipoGranella(int tg){
    return tipoGranella=tg;
}
int cioccolata::setLivelloFondenza(int lvf){
    return livelloFondenza=lvf;
}
bool cioccolata::setForma(bool frm){
    return forma=frm;
}
//METODI
double cioccolata::prezzo() const{
    double conto=30*getPeso();
    if(livelloFondenza ==1) conto=conto+(getPeso()*9);
    else if (livelloFondenza ==2) conto=conto+(getPeso()*7);
    else if (livelloFondenza ==3) conto=conto+(getPeso()*7.50);
    else conto=conto+(getPeso()*8);

    if(tipoGranella == 1) conto+=(getPeso()/2)*0.30;
    else if(tipoGranella == 2) conto+=(getPeso()/2)*0.40;
    else if(tipoGranella == 3)conto+=(getPeso()/2)*0.60;
    else if(tipoGranella == 4) conto+=(getPeso()/2)*0.80;

    return conto;
}

double cioccolata::ricavo() const{
    return (prezzo()/100)*25;
}

std::string  cioccolata::tipoElemento() const{
    return "cioccolata";
}






//INFUSI
infusi::infusi(std::string n,bool cr,std::vector<std::string> ingr,double p,bool erb,bool prod,std::vector<std::string> ar,bool sf):
    consumabile(n,cr,ingr,p,erb,prod),aroma(ar),sfuso(sf){}
//GET
std::vector<std::string> infusi::getAroma() const{
    return aroma;
}
bool infusi::getSfuso() const{
    return sfuso;
}
//SET
void infusi::setAroma(std::string arm){
    for(unsigned int i=0;i<aroma.size();++i){
        if(arm==aroma[i]) return;
    }
    aroma.push_back(arm);
    return;
}
bool infusi::setSfuso(bool sf){
    return sfuso=sf;
}
//METODI
double infusi::prezzo() const{
    double conto=10*getPeso();
    if(sfuso) conto=conto+(getPeso()*39.85);
    else conto=conto+(getPeso()*29.98);
    if(aroma.size()==1) return conto;
    else return conto+3;
}
double infusi::ricavo() const{
    return (prezzo()/100)*20;
}
std::string  infusi::tipoElemento() const{
    return "infusi";
}





//NONCONSUMABILE
nonConsumabile::nonConsumabile(std::string n,bool cr,std::vector<std::string> c):
    catalogo(n,cr),colori(c){}
//GET
std::vector<std::string> nonConsumabile::getColori() const{
    return colori;
}
//SET
void nonConsumabile::setColori(std::string c){
    for(unsigned int i=0;i<colori.size();++i){
        if(c==colori[i]) return;
    }
    colori.push_back(c);
    return;
}




//BONG
bong::bong(std::string n,bool cr,std::vector<std::string> c,bool frm,int alt,double largh):
    nonConsumabile(n,cr,c),forma(frm),altezza(alt),larghezza(largh){}
//GET
bool bong::getForma() const{
    return forma;
}
int bong::getAltezza() const{
    return altezza;
}
double bong::getLarghezza() const{
    return larghezza;
}
//SET
bool bong::setForma(bool frm){
    return forma=frm;
}
int bong::setAltezza(int alt){
    return altezza=alt;
}
double bong::setLarghezza(double largh){
    return larghezza=largh;
}
//METODI
double  bong::prezzo() const{
    double prezzo=0;
    if(forma){
       if(altezza == 5) prezzo+=119;
       else if(altezza == 6) prezzo+=139;
    }
    else {
        if(altezza == 1) prezzo+=54.90;
        else if(altezza == 2) prezzo+=74.90;
        else if(altezza == 3) prezzo+=94.90;
        else  prezzo+=119;
    };

    return  prezzo;
}
double bong::ricavo() const{
    return (prezzo()/100)*18;
}
std::string  bong::tipoElemento() const{
    return "bong";
}



//VAPORIZZATORE
vaporizzatore::vaporizzatore(std::string n,bool cr,std::vector<std::string> c,int ve,double cap,bool scher):
    nonConsumabile(n,cr,c),velocitaEvaporazione(ve),capienza(cap),schermo(scher){}
//GET
int vaporizzatore::getVelocitaEvaporazione() const{
    return velocitaEvaporazione;
}
int vaporizzatore::getCapienza() const{
    return capienza;
}
bool vaporizzatore::getSchermo() const{
    return schermo;
}

//SET
int vaporizzatore::setVelocitaEvaporazione(int ve){
    return velocitaEvaporazione=ve;
}
double vaporizzatore::setCapienza(double cap){
    return capienza=cap;
}
bool vaporizzatore::setSchermo(bool sch){
    return schermo=sch;
}
//METODI
double vaporizzatore::prezzo() const{
    double prezzo=0;
    if(schermo) prezzo+=450;
    else prezzo+=350;
    if(velocitaEvaporazione == 1) prezzo+=50;
    else if(velocitaEvaporazione == 2) prezzo+=75;
    else prezzo+=100;
    return prezzo+=getCapienza()*0.25;
}
double vaporizzatore::ricavo() const{
    return (prezzo()/100)*12;
}
std::string  vaporizzatore::tipoElemento() const{
    return "vaporizzatore";
}




//GRINDER
grinder::grinder(std::string n,bool cr,std::vector<std::string> c,int nd,bool racp):
    nonConsumabile(n,cr,c),ndenti(nd),raccoglipolline(racp){}
//GET
int grinder::getNdenti() const{
    return ndenti;
}
bool grinder::getRaccogliPolline() const{
    return raccoglipolline;
}
//SET
int grinder::setNdenti(int ndent){
    return ndenti=ndent;
}
bool grinder::setRaccogliPolline(bool racp){
    return raccoglipolline=racp;
}
//METODI
double grinder::prezzo() const{
    double prezzo=0;
    if(raccoglipolline) prezzo+=12;
    else prezzo+=10;
    return prezzo;
}
double grinder::ricavo() const{
    return (prezzo()/100)*15;
}
std::string  grinder::tipoElemento() const{
    return "grinder";
}
