#ifndef RICERCA_H
#define RICERCA_H
#include<QWidget>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QCheckBox>
#include<QListWidget>
#include<QLabel>
#include<QScrollBar>
#include<QComboBox>
#include<vector>



#include"GUI/elementoWidget.h"
class Ricerca: public QWidget {
    Q_OBJECT
private:
    QWidget*        parent;


    //CONSUMABILI
    QLabel*         lableTipoProdotto;
    QComboBox*      tipoProdotto;

    QLabel*         lableTipoFarine;
    QCheckBox*      grano;
    QCheckBox*      riso;
    QCheckBox*      mandorle;
    QCheckBox*      castagne;
    QCheckBox*      amaranto;

    QLabel*         lableTipoGocce;
    QCheckBox*      senza;
    QCheckBox*      latte;
    QCheckBox*      fondente;
    QCheckBox*      bianco;

    QLabel*         lableLvFondenza;
    QCheckBox*      nessuna;
    QCheckBox*      bassa;
    QCheckBox*      media;
    QCheckBox*      alta;

    QLabel*         lableTipoGranella;
    QCheckBox*      cocco;
    QCheckBox*      noce;
    QCheckBox*      mandorla;
    QCheckBox*      nocciola;

    QLabel*         lableFormaC;
    QCheckBox*      stecche;
    //QCheckBox*      praline;

    QLabel*         lableTipoAroma;
    QComboBox*      aroma1;
    QComboBox*      aroma2;
    QCheckBox*      sfuso;

    //NON CONSUMABILI
    QLabel*         lableTipoBong;
    QCheckBox*      backer;
    QCheckBox*      dritto;
    QCheckBox*      qualsiasi;
    QLabel*         lableTipoDimensioni;
    QComboBox*      dimBacker;
    QComboBox*      dimDritto;

    QLabel*         lableTipoVapo;
    QCheckBox*      schermo;
    QComboBox*      capienza;
    QComboBox*      velocita;

    QLabel*         lableTipoGrinder;
    QComboBox*      ndenti;
    QCheckBox*      raccoglipoll;


    QPushButton*    cerca;
    elementoWidget* catalogo;
    QPushButton*    modifica;
    QPushButton*    rimuovi;
public:
    Ricerca(QWidget* = nullptr);
    QPushButton* getCercaBut() const;
    //QPushButton* getModificaRic() const;
    //QPushButton* getRimuoviRic() const;
    std::string getTipoProdotto() const;
    int getTipoFarina() const;
    int getTipoGocce() const;
    int getLvFondenza() const;
    int getTipoGranella() const;
    bool getFormaC() const;
    std::vector<std::string> getAroma() const;
    bool getSfuso() const;
    int getFormaB() const;
    int getAltezza() const;
    double getLarghezza() const;
    int getVelocita() const;
    int getCapienza() const;
    bool getSchermo() const;
    int getNDenti() const;
    bool getRaccogliP() const;

    elementoWidget* getListaRicerca() const;
public slots:
    void scelteBiscotti();
    void scelteCioccolato();
    void scelteInfusi();

    void scelteFormaBong();
    void scelteDimensioniB(bool);
    void scelteDimensioniD(bool);
    void scelteVapo();
    void scelteGrinder();

    void resetDim();


    //CHECKFARINE
    void checkGrano(bool);
    void checkRiso(bool);
    void checkMandorle(bool);
    void checkCastagne(bool);
    void checkAmaranto(bool);
    //CHECKGOCCE
    void checkSenza(bool);
    void checkLatte(bool);
    void checkFondente(bool);
    void checkBianco(bool);
    //CHECKFONDENZA
    void checkNessuna(bool);
    void checkBassa(bool);
    void checkMedia(bool);
    void checkAlta(bool);
    //CHECKGRANELLA
    void checkCocco(bool);
    void checkNoce(bool);
    void checkMandorla(bool);
    void checkNocciola(bool);
    //CHECKQUALSIASI
    void checkQualsiasi(bool);
/*    //CHECKFORMAC
    void checkStecche(bool);
    void checkPraline(bool);*/

};
#endif // RICERCA_H