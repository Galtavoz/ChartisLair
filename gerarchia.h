#ifndef GERARCHIA_H
#define GERARCHIA_H

#include<iostream>
#include<vector>
#include<sstream>
#include<iomanip>

enum fondenza   {niente=1,bassa=2,media=3,alta=4};//1=0%, 2=50%, 3=75%, 4=90%
enum granella   {cocco=1,noce=2,mandorla=3,nocciola=4};
enum farina     {grano=1,riso=2,mandorle=3,castagne=4,amaranto=5};
enum gocce      {latte=1,fondente=2,bianco=3,senza=4};
enum altezze    {cm24=1,cm32=2,cm37=3,cm46=4,cm33=5,cm45=6};
enum lvVelocitaEvaporazione {lv1=1,lv2=2,lv3=3};

class catalogo{
private:
    std::string nome;
    bool confezioneRegalo;
public:
    catalogo(std::string,bool);
    virtual ~catalogo() = default;
    //GET
    std::string getNome() const;
    bool getConfezioneRegalo() const;
    //SET
    std::string setNome(std::string);
    bool setConfezioneRegalo(bool);
    //METODI
    virtual double prezzo() const = 0;
    virtual double ricavo() const = 0;
    virtual std::string  tipoElemento() const =0;
    virtual std::string visualizzaInfo() const;
    //OPERATORI
    virtual bool operator==(const catalogo&) const;
};

class consumabile: public catalogo{
private:
     std::vector<std::string> ingredienti;
     double peso;//prezzo al Kg
     bool erba;//True Indica ; False Sativa
     bool produzione;//True Indoor ; False Outdoor
public:
     consumabile(std::string,bool,std::vector<std::string>,double,bool,bool);
     virtual ~consumabile() = default;
     //GET
     std::vector<std::string> getIngredienti() const;
     double getPeso() const;
     bool getErba() const;
     bool getProduzione() const;
     //SET
     void setIngredienti(std::string);
     double setPeso(double);
     bool setErba(bool);
     bool setProduzione(bool);
     //METODI
     virtual double prezzo() const = 0;
     virtual double ricavo() const = 0;
     virtual std::string  tipoElemento() const =0;
     virtual std::string visualizzaInfo() const;
     //OPERATORI
     virtual bool operator==(const catalogo&) const;
};

class biscotti: public consumabile{
private:
    int  tipoFarina = farina{};
    int  gocceCioccolata = gocce{};
public:
    biscotti(std::string,bool,std::vector<std::string>,double,bool,bool,int,int);
    virtual ~biscotti() = default;
    //GET
    int   getTipoFarina() const;
    int   getGocceCioccolata() const;
    //SET
    int   setTipoFarina(int);
    int   setGocceCioccolata(int);
    //METODI
    virtual double prezzo() const override;
    virtual double ricavo() const override;
    virtual std::string  tipoElemento() const override;
    virtual std::string visualizzaInfo() const override;
    //OPERATORI
    virtual bool operator==(const catalogo&) const override;
};

class cioccolata: public consumabile{
private:
    int  tipoGranella = granella{}; //{fondenza riga 8};
    int  livelloFondenza = fondenza{}; //{fondenza riga 7};
    bool forma;//True Stecca ; False Pallina
public:
    cioccolata(std::string,bool,std::vector<std::string>,double,bool,bool,int,int,bool);
    virtual ~cioccolata() = default;
    //GET
    int   getTipoGranella() const;
    int   getLivelloFondenza() const;
    bool  getForma() const;
    //SET
    int   setTipoGranella(int);
    int   setLivelloFondenza(int);
    bool  setForma(bool);
    bool  setProduzione(bool);
    //METODI
    virtual double prezzo() const override;
    virtual double ricavo() const override;
    virtual std::string  tipoElemento() const override;
    virtual std::string visualizzaInfo() const override;
    //OPERATORI
    virtual bool operator==(const catalogo&) const override;

};

class infusi: public consumabile{
private:
    std::vector<std::string> aroma;
    bool sfuso;//True sfuso ; False in bustina
public:
    infusi(std::string,bool,std::vector<std::string>,double,bool,bool,std::vector<std::string>,bool);
    virtual ~infusi() = default;
    //GET
    std::vector<std::string> getAroma() const;
    bool getSfuso() const;
    //SET
    void setAroma(std::string);
    bool setSfuso(bool);
    //METODI
    virtual double prezzo() const override;
    virtual double ricavo() const override;
    virtual std::string  tipoElemento() const override;
    virtual std::string visualizzaInfo() const override;
    //OPERATORI
    virtual bool operator==(const catalogo&) const override;
};




//NONCONSUMABILE
class nonConsumabile: public catalogo{
private:
    std::string colori;
public:
    nonConsumabile(std::string,bool,std::string);
    virtual ~nonConsumabile() = default;
    //GET
    std::string getColori() const;
    //SET
    void setColori(std::string);
    //METODI
    virtual double prezzo() const = 0;
    virtual double ricavo() const = 0;
    virtual std::string  tipoElemento() const =0;
    virtual std::string visualizzaInfo() const;
    //OPERATORI
    virtual bool operator==(const catalogo&) const;
};

//BONG
class bong: public nonConsumabile{
private:
    bool forma;//True backer, False dritto
    int altezza = altezze{};
    double larghezza;
public:
    bong(std::string,bool,std::string,bool,int,double);
    virtual ~bong() = default;
    //GET
    bool  getForma() const;
    int   getAltezza() const;
    double  getLarghezza() const;
    //SET
    bool setForma(bool);
    int  setAltezza(int);
    double setLarghezza(double);
    //METODI
    virtual double prezzo() const override;
    virtual double ricavo() const override;
    virtual std::string  tipoElemento() const override;
    virtual std::string visualizzaInfo() const override;
    //OPERATORI
    virtual bool operator==(const catalogo&) const override;
};

//VAPORIZZATORE
class vaporizzatore: public nonConsumabile{
private:
    int  velocitaEvaporazione = lvVelocitaEvaporazione{};//più è alta la velocita piu velocemnte vaporizza
    int  capienza;//capienza dello sportello portaerba espressa in grammi
    bool schermo;
public:
    vaporizzatore(std::string,bool,std::string,int,double,bool);
    virtual ~vaporizzatore() = default;
    //GET
    int  getVelocitaEvaporazione() const;
    int   getCapienza() const;
    bool  getSchermo() const;
    //SET
    int  setVelocitaEvaporazione(int);
    int  setCapienza(int);
    bool setSchermo(bool);
    //METODI
    virtual double prezzo() const override;
    virtual double ricavo() const override;
    virtual std::string  tipoElemento() const override;
    virtual std::string visualizzaInfo() const override;
    //OPERATORI
    virtual bool operator==(const catalogo&) const override;
};

//GRINDER
class grinder: public nonConsumabile{
private:
    int  ndenti;
    bool raccoglipolline;
public:
    grinder(std::string,bool,std::string,int,bool);
    virtual ~grinder() = default;
    //GET
    int   getNdenti() const;
    bool  getRaccogliPolline() const;
    //SET
    int  setNdenti(int);
    bool setRaccogliPolline(bool);
    //METODI
    virtual double prezzo() const override;
    virtual double ricavo() const override;
    virtual std::string  tipoElemento() const override;
     virtual std::string visualizzaInfo() const override;
    //OPERATORI
    virtual bool operator==(const catalogo&) const override;
};
#endif // GERARCHIA_H
