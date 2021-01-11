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

//NONCONSUMABILE
