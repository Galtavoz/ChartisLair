#ifndef GERARCHIA_H
#define GERARCHIA_H

#include<iostream>
#include<vector>

enum fondenza{niente=1,bassa=2,media=3,alta=4};//1=0%, 2=50%, 3=75%, 4=90%
enum granella{cocco=1,noce=2,mandorla=3,nocciola=4};//1=0%, 2=50%, 3=75%, 4=90%

class catalogo{
private:
    std::string nome;
    bool confezioneRegalo;
public:
    catalogo(std::string);
    virtual ~catalogo() = default;
    //GET
    std::string getnome() const;
    bool getConfezioneRegalo() const;
    //SET
    std::string setnome(std::string);
    bool setConfezioneRegalo() const;
    //METODI
    virtual double prezzo() const = 0;
};

class consumabile: public catalogo{
private:
     std::vector<std::string> ingredienti;
     double peso;
     bool erba;//True Indica ; False Sativa
     bool produzione;//True Indoor ; False Outdoor
public:
     consumabile(std::string,bool,std::vector<std::string>,double,bool,bool);
     virtual ~consumabile() = default;
     //GET
     std::vector<std::string> getIngredienti() const;
     std::string getPeso() const;
     bool getErba() const;
     bool getProduzione() const;
     //SET
     std::string setIngredienti(std::string);
     std::string setPeso(double);
     bool setErba(bool);
     bool setProduzione(bool);
     //METODI
     virtual double prezzo() const = 0;
};

class biscotti: public consumabile{
private:
public:
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
    virtual double prezzo() const = 0;

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
    std::string setAroma(std::string);
    bool setSfuso(bool);
};





class nonConsumabile: public catalogo{
private:
    std::vector<std::string> colori;
public:
    nonConsumabile(std::string,bool,std::vector<std::string>);
    virtual ~nonConsumabile() = default;
    //GET
    std::vector<std::string> getColori() const;
    //SET
    std::string setColori(std::string);
    //METODI
    virtual double prezzo() const = 0;
};

class bong: public nonConsumabile{
private:
public:
};

class vaporizzatore: public nonConsumabile{
private:
public:
};

class grinder: public nonConsumabile{
private:
public:
};
#endif // GERARCHIA_H
