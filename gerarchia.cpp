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
//METODI
std::string catalogo::visualizzaInfo() const {
    std::string frase;
    return frase.append("\n Nome: "+getNome())
           .append("\n Confezione regalo: ").append((getConfezioneRegalo() ? "Si" : "No"));
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
//METODI
std::string consumabile::visualizzaInfo() const {
    std::string frase = catalogo::visualizzaInfo();
    std::string ingredienti="";
    std::vector<std::string> vettore=getIngredienti();
    std::stringstream Peso;
    Peso<<std::fixed<<std::setprecision(3)<<getPeso();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) ingredienti.append(*cit+",");
        else ingredienti.append(*cit);
    }
    return frase.append("\n Ingredienti: "+ingredienti)
           .append("\n Peso(in Kg): ")+Peso.str().append("Kg")
           .append("\n Tipologia di erba: ").append(getErba() ? "Indica" : "Sativa")
           .append("\n Produzione :").append(getProduzione() ? "Indoor" : "Outdoor");
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
    double prezzo=100*getPeso();
    if(tipoFarina==1) prezzo+=getPeso()*0.99;
    else if (tipoFarina==2)prezzo+=getPeso()*5;
    else if (tipoFarina==3)prezzo+=getPeso()*20;
    else if (tipoFarina==4)prezzo+=getPeso()*24;
    else prezzo+=getPeso()*9;

    if(gocceCioccolata==1) prezzo+=6.20;
    else if (gocceCioccolata==2)prezzo+=5.99;
    else if (gocceCioccolata==3)prezzo+=5.50;

    return prezzo;
}

std::string biscotti::visualizzaInfo() const {
    std::string frase = consumabile::visualizzaInfo();
    std::string farina;
    std::string gocce;
    std::stringstream Ricavo;
    Ricavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::stringstream Prezzo;
    Prezzo<<std::fixed<<std::setprecision(2)<<prezzo();
    if(getTipoFarina()==1) farina="Grano";
    else if(getTipoFarina()==2) farina="Riso";
    else if(getTipoFarina()==3) farina="Mandorle";
    else if(getTipoFarina()==4) farina="Castagne";
    else farina="Amaranto";
    if(getGocceCioccolata()==1) gocce="Latte";
    else if(getGocceCioccolata()==2) gocce="Fondente";
    else if(getGocceCioccolata()==3) gocce="Bianco";
    else gocce="No gocce";
    return frase.append("\n Tipo di farina: "+farina)
           .append("\n Gocce: "+gocce)
           .append("\n Prezzo al pubblico: "+Prezzo.str()+("€"))
           .append("\n Ricavo: "+Ricavo.str()+("€"));

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
    double prezzo=30*getPeso();
    if(livelloFondenza ==1) prezzo+=(getPeso()*9);
    else if (livelloFondenza ==2) prezzo+=(getPeso()*7);
    else if (livelloFondenza ==3) prezzo+=(getPeso()*7.50);
    else prezzo+=(getPeso()*8);

    if(tipoGranella == 1) prezzo+=(getPeso()/2)*0.30;
    else if(tipoGranella == 2) prezzo+=(getPeso()/2)*0.40;
    else if(tipoGranella == 3)prezzo+=(getPeso()/2)*0.60;
    else if(tipoGranella == 4) prezzo+=(getPeso()/2)*0.80;

    return prezzo;
}

std::string cioccolata::visualizzaInfo() const {
    std::string frase = consumabile::visualizzaInfo();
    std::string fondenza;
    std::string granella;
    std::stringstream Ricavo;
    Ricavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::stringstream Prezzo;
    Prezzo<<std::fixed<<std::setprecision(2)<<prezzo();
    if(getLivelloFondenza()==1) fondenza="0%";
    else if(getLivelloFondenza()==2) fondenza="50%";
    else if(getLivelloFondenza()==3) fondenza="75%";
    else fondenza="90%";
    if(getTipoGranella()==1) granella="Cocco";
    else if(getTipoGranella()==2) granella="Noce";
    else if(getTipoGranella()==3) granella="Mandorla";
    else granella="Nocciola";
    return frase.append("\n Percentuale di fondenza: "+fondenza)
           .append("\n Tipo di granella: "+granella)
           .append("\n Forma :").append(getForma() ? "Stecche" : "Praline")
           .append("\n Prezzo al pubblico: "+Prezzo.str()+("€"))
           .append("\n Ricavo: "+Ricavo.str()+("€"));

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
    double prezzo=10*getPeso();
    if(sfuso) prezzo+=getPeso()*39.85;
    else prezzo+=getPeso()*29.98;
    if(aroma.size()==1) return prezzo;
    else return prezzo+3;
}

std::string infusi::visualizzaInfo() const {
    std::string frase = consumabile::visualizzaInfo();
    std::string aroma="";
    std::stringstream Ricavo;
    Ricavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::stringstream Prezzo;
    Prezzo<<std::fixed<<std::setprecision(2)<<prezzo();
    std::vector<std::string> vettore=getAroma();
    for(std::vector<std::string>::const_iterator cit=vettore.cbegin();cit!=vettore.cend();++cit) {
        if(cit!=vettore.cend()-1) aroma.append(*cit+",");
        else aroma.append(*cit);
    }
    return frase.append("\n Aroma: "+aroma)
           .append("\n Sfuso :").append(getSfuso() ? "Si" : "No")
           .append("\n Prezzo al pubblico: "+Prezzo.str()+("€"))
           .append("\n Ricavo: "+Ricavo.str()+("€"));
}

double infusi::ricavo() const{
    return (prezzo()/100)*20;
}
std::string  infusi::tipoElemento() const{
    return "infusi";
}





//NONCONSUMABILE
nonConsumabile::nonConsumabile(std::string n,bool cr,std::string c):
    catalogo(n,cr),colori(c){}
//GET
std::string nonConsumabile::getColori() const{
    return colori;
}
//SET
void nonConsumabile::setColori(std::string c){
    colori=c;
    return;
}
//METODI
std::string nonConsumabile::visualizzaInfo() const {
    std::string frase = catalogo::visualizzaInfo();
    std::string colori=getColori();
    return frase.append("\n Colori: "+colori);
}




//BONG
bong::bong(std::string n,bool cr,std::string c,bool frm,int alt,double largh):
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

std::string bong::visualizzaInfo() const {
    std::string frase = nonConsumabile::visualizzaInfo();
    std::string altezza;
    std::stringstream Ricavo;
    Ricavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::stringstream Prezzo;
    Prezzo<<std::fixed<<std::setprecision(2)<<prezzo();
    std::stringstream Larghezza;
    Larghezza<<std::fixed<<std::setprecision(1)<<getLarghezza();
    if(getAltezza()==1) altezza="24";
    else if(getAltezza()==2) altezza="32";
    else if(getAltezza()==3) altezza="37";
    else if(getAltezza()==4) altezza="46";
    else if(getAltezza()==5) altezza="33";
    else altezza="45";
    return frase.append("\n Forma :").append(getForma() ? "Beaker" : "Dritto")
           .append("\n Dimensioni(HxL): "+altezza+(" X "))+Larghezza.str().append("cm")
           .append("\n Prezzo al pubblico: "+Prezzo.str()+("€"))
           .append("\n Ricavo: "+Ricavo.str()+("€"));
}

double bong::ricavo() const{
    return (prezzo()/100)*18;
}

std::string  bong::tipoElemento() const{
    return "bong";
}



//VAPORIZZATORE
vaporizzatore::vaporizzatore(std::string n,bool cr,std::string c,int ve,double cap,bool scher):
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

std::string vaporizzatore::visualizzaInfo() const {
    std::string frase = nonConsumabile::visualizzaInfo();
    std::string velocita;
    std::stringstream Ricavo;
    Ricavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::stringstream Prezzo;
    Prezzo<<std::fixed<<std::setprecision(2)<<prezzo();
    if(getVelocitaEvaporazione()==1) velocita="Lv 1";
    else if(getVelocitaEvaporazione()==2) velocita="Lv 2";
    else velocita="Lv 3";
    return frase.append("\n Velocità evaporazione: "+velocita)
            .append("\n Capienza sportello (in grammi): ")+std::to_string(getCapienza())
            .append("\n Schermo :").append(getSchermo() ? "Si" : "No")
            .append("\n Prezzo al pubblico: "+Prezzo.str()+("€"))
            .append("\n Ricavo: "+Ricavo.str()+("€"));
}

double vaporizzatore::ricavo() const{
    return (prezzo()/100)*12;
}
std::string  vaporizzatore::tipoElemento() const{
    return "vaporizzatore";
}




//GRINDER
grinder::grinder(std::string n,bool cr,std::string c,int nd,bool racp):
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
std::string grinder::visualizzaInfo() const {
    std::string frase = nonConsumabile::visualizzaInfo();
    std::stringstream Ricavo;
    Ricavo<<std::fixed<<std::setprecision(2)<<ricavo();
    std::stringstream Prezzo;
    Prezzo<<std::fixed<<std::setprecision(2)<<prezzo();
    return frase.append("\n Numero di denti: ")+std::to_string(getNdenti())
            .append("\n Raccogli Polline :").append(getRaccogliPolline() ? "Si" : "No")
            .append("\n Prezzo al pubblico: "+Prezzo.str()+("€"))
            .append("\n Ricavo: "+Ricavo.str()+("€"));
}
double grinder::ricavo() const{
    return (prezzo()/100)*15;
}
std::string  grinder::tipoElemento() const{
    return "grinder";
}
