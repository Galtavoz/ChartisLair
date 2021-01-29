#include"ricerca.h"


Ricerca::Ricerca(QWidget* p):
    QWidget(p),
    lableTipoProdotto(new QLabel(this)),
    tipoProdotto(new QComboBox(this)),
//CONSUMABILI
    lableTipoFarine(new QLabel(this)),
    grano(new QCheckBox(this)),
    riso(new QCheckBox(this)),
    mandorle(new QCheckBox(this)),
    castagne(new QCheckBox(this)),
    amaranto(new QCheckBox(this)),

    lableTipoGocce(new QLabel(this)),
    senza(new QCheckBox(this)),
    latte(new QCheckBox(this)),
    fondente(new QCheckBox(this)),
    bianco(new QCheckBox(this)),

    lableLvFondenza(new QLabel(this)),
    nessuna(new QCheckBox(this)),
    bassa(new QCheckBox(this)),
    media(new QCheckBox(this)),
    alta(new QCheckBox(this)),

    lableTipoGranella(new QLabel(this)),
    cocco(new QCheckBox(this)),
    noce(new QCheckBox(this)),
    mandorla(new QCheckBox(this)),
    nocciola(new QCheckBox(this)),

    lableFormaC(new QLabel(this)),
    stecche(new QCheckBox(this)),
    //praline(new QCheckBox(this)),

    lableTipoAroma(new QLabel(this)),
    aroma1(new QComboBox(this)),
    aroma2(new QComboBox(this)),
    sfuso(new QCheckBox(this)),
//NON CONSUMABILI
    lableTipoBong(new QLabel(this)),
    backer(new QCheckBox(this)),
    dritto(new QCheckBox(this)),
    qualsiasi(new QCheckBox(this)),
    lableTipoDimensioni(new QLabel(this)),
    dimBacker(new QComboBox(this)),
    dimDritto(new QComboBox(this)),

    lableTipoVapo(new QLabel(this)),
    schermo(new QCheckBox(this)),
    capienza(new QComboBox(this)),
    velocita(new QComboBox(this)),

    lableTipoGrinder(new QLabel(this)),
    ndenti(new QComboBox(this)),
    raccoglipoll(new QCheckBox(this)),

    cerca(new QPushButton(this)),
    catalogo(new elementoWidget(this)),
    modifica(new QPushButton(this)),
    rimuovi(new QPushButton(this)){


     QVBoxLayout* layoutRic         = new QVBoxLayout(this);
     QHBoxLayout* layoutFarine      = new QHBoxLayout();
     QHBoxLayout* layoutGocce       = new QHBoxLayout();
     QHBoxLayout* layoutFondenza    = new QHBoxLayout();
     QHBoxLayout* layoutGranella    = new QHBoxLayout();
     QHBoxLayout* layoutFormaC      = new QHBoxLayout();
     QHBoxLayout* layoutAroma       = new QHBoxLayout();
     QHBoxLayout* layoutFormaB      = new QHBoxLayout();
     QHBoxLayout* layoutDimensioni  = new QHBoxLayout();
     QHBoxLayout* layoutVapo        = new QHBoxLayout();
     QHBoxLayout* layoutGrinder     = new QHBoxLayout();
     QHBoxLayout* layoutBottoni     = new QHBoxLayout();

     catalogo->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

     layoutRic->addWidget(lableTipoProdotto);
     layoutRic->addWidget(tipoProdotto);
     layoutRic->addLayout(layoutFarine);
     layoutRic->addLayout(layoutGocce);
     layoutRic->addLayout(layoutFondenza);
     layoutRic->addLayout(layoutGranella);
     layoutRic->addLayout(layoutFormaC);
     layoutRic->addLayout(layoutAroma);
     layoutRic->addLayout(layoutFormaB);
     layoutRic->addLayout(layoutDimensioni);
     layoutRic->addLayout(layoutVapo);
     layoutRic->addLayout(layoutGrinder);
     layoutRic->addWidget(cerca);
     layoutRic->addWidget(catalogo);
     layoutRic->addLayout(layoutBottoni);

     layoutFarine->addWidget(lableTipoFarine);
     layoutFarine->addWidget(grano);
     layoutFarine->addWidget(riso);
     layoutFarine->addWidget(mandorle);
     layoutFarine->addWidget(castagne);
     layoutFarine->addWidget(amaranto);

     layoutGocce->addWidget(lableTipoGocce);
     layoutGocce->addWidget(senza);
     layoutGocce->addWidget(latte);
     layoutGocce->addWidget(fondente);
     layoutGocce->addWidget(bianco);

     layoutFondenza->addWidget(lableLvFondenza);
     layoutFondenza->addWidget(nessuna);
     layoutFondenza->addWidget(bassa);
     layoutFondenza->addWidget(media);
     layoutFondenza->addWidget(alta);

     layoutGranella->addWidget(lableTipoGranella);
     layoutGranella->addWidget(cocco);
     layoutGranella->addWidget(noce);
     layoutGranella->addWidget(mandorla);
     layoutGranella->addWidget(nocciola);

     layoutFormaC->addWidget(lableFormaC);
     layoutFormaC->addWidget(stecche);
     //layoutFormaC->addWidget(praline);

     layoutAroma->addWidget(lableTipoAroma);
     layoutAroma->addWidget(aroma1);
     layoutAroma->addWidget(aroma2);
     layoutAroma->addWidget(sfuso);

     layoutFormaB->addWidget(lableTipoBong);
     layoutFormaB->addWidget(backer);
     layoutFormaB->addWidget(dritto);
     layoutFormaB->addWidget(qualsiasi);

     layoutDimensioni->addWidget(lableTipoDimensioni);
     layoutDimensioni->addWidget(dimBacker);
     layoutDimensioni->addWidget(dimDritto);

     layoutVapo->addWidget(lableTipoVapo);
     layoutVapo->addWidget(schermo);
     layoutVapo->addWidget(capienza);
     layoutVapo->addWidget(velocita);

     layoutGrinder->addWidget(lableTipoGrinder);
     layoutGrinder->addWidget(ndenti);
     layoutGrinder->addWidget(raccoglipoll);

     layoutBottoni->addWidget(modifica);
     layoutBottoni->addWidget(rimuovi);

     catalogo->show();
     modifica->show();
     rimuovi->show();
     lableTipoProdotto->show();
     cerca->show();
     lableTipoProdotto->setText("Seleziona la tipologia di prodotto da ricercare :");
     cerca->setText("Cerca");
     QList<QString> prodotti={"Seleziona prodotto...","Biscotti","Cioccolata","Infusi","Bong","Vaporizzatore","Grinder"};
     for(int i=0;i<prodotti.length();++i)
             tipoProdotto->addItem(prodotti[i]);
      tipoProdotto->setCurrentIndex(0);

      lableTipoFarine->hide();
      grano->hide();
      riso->hide();
      mandorle->hide();
      castagne->hide();
      amaranto->hide();

      lableTipoGocce->hide();
      senza->hide();
      latte->hide();
      fondente->hide();
      bianco->hide();

      lableLvFondenza->hide();
      nessuna->hide();
      bassa->hide();
      media->hide();
      alta->hide();

      lableTipoGranella->hide();
      cocco->hide();
      noce->hide();
      mandorla->hide();
      nocciola->hide();

      lableFormaC->hide();
      stecche->hide();
      //praline->hide();

      lableTipoAroma->hide();
      aroma1->hide();
      aroma2->hide();
      sfuso->hide();

      lableTipoBong->hide();
      backer->hide();
      dritto->hide();
      qualsiasi->hide();
      lableTipoDimensioni->hide();
      dimBacker->hide();
      dimDritto->hide();

      lableTipoVapo->hide();
      schermo->hide();
      capienza->hide();
      velocita->hide();

      lableTipoGrinder->hide();
      ndenti->hide();
      raccoglipoll->hide();


      lableTipoFarine->setText("Seleziona la tipologia di farina:");
      grano->setText("Grano");
      riso->setText("Riso");
      mandorle->setText("Mandorle");
      castagne->setText("Castagne");
      amaranto->setText("Amaranto");

      lableTipoGocce->setText("Seleziona la tipologia di gocce :");
      senza->setText("Senza");
      latte->setText("Latte");
      fondente->setText("Fondente");
      bianco->setText("Bianco");

      lableLvFondenza->setText("Seleziona il livello di fondenza :");
      nessuna->setText("0%");
      bassa->setText("30%");
      media->setText("50%");
      alta->setText("75%");

      lableTipoGranella->setText("Seleziona la tipologia di granella :");
      cocco->setText("Cocco");
      noce->setText("Noce");
      mandorla->setText("Mandorla");
      nocciola->setText("Nocciola");

      lableFormaC->setText("Seleziona la tipologia di forma(se spuntato sono stecche, senno praline) :");
      stecche->setText("Stecche");
      //praline->setText("Praline");

      lableTipoAroma->setText("Seleziona gli aromi(se si vuole solo un aroma , lasciare 'Nessun aroma' sul secondo spazio): ");
      QList<QString> listaaromi={"Albicocca","Limone","Liquirizia","Menta","Zenzero"};
      for(int i=0;i<listaaromi.length();++i)
          aroma1->addItem(listaaromi[i]);
      aroma1->setCurrentIndex(0);
      QList<QString> listaaromi1={"Nessun aroma","Albicocca","Limone","Liquirizia","Menta","Zenzero"};
      for(int i=0;i<listaaromi1.length();++i)
          aroma2->addItem(listaaromi1[i]);
      aroma2->setCurrentIndex(0);
      sfuso->setText("Sfuso?");


      lableTipoBong->setText("Seleziona la forma del bong");
      backer->setText("Backer");
      dritto->setText("Dritto");
      qualsiasi->setText("Qualsiasi");
      lableTipoBong->setText("Seleziona le dimensioni del bong");
      QList<QString> listaDimB={"Qualsiasi","33X4.6 cm","45X4.6 cm"};
      for(int i=0;i<listaDimB.length();++i)
          dimBacker->addItem(listaDimB[i]);
      QList<QString> listaDimD={"Qualsiasi","24X3.1 cm","32X4.1 cm","37X5.3 cm","46X6.7 cm"};
      for(int i=0;i<listaDimD.length();++i)
          dimDritto->addItem(listaDimD[i]);

      lableTipoVapo->setText("Seleziona le caratteristiche del vaporizzatore; primo campo se ha o no lo schermo, secondo campo la capienza della macchina, terzo la velocita di evaporazione");
      schermo->setText("Schermo?");
      QList<QString> listaCapienza={"Qualsiasi","1 gr","2 gr","3 gr","4 gr"};
      for(int i=0;i<listaCapienza.length();++i)
          capienza->addItem(listaCapienza[i]);
      QList<QString> listaVelocita={"Qualsiasi","Lv 1","Lv 2","Lv 3"};
      for(int i=0;i<listaVelocita.length();++i)
          velocita->addItem(listaVelocita[i]);

      lableTipoGrinder->setText("Seleziona le caratteristiche del grinder;primo capo il numero dei denti, il secondo se ha o no il raccogli polline");
      QList<QString> listaDenti={"Qualsiasi","6","12","24","30","36"};
      for(int i=0;i<listaDenti.length();++i)
          ndenti->addItem(listaDenti[i]);
      raccoglipoll->setText("Raccogli polline?");

      modifica->setText("Modifica");
      rimuovi->setText("Rimuovi");


      lableTipoProdotto->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoProdotto->setWordWrap(true);

      lableTipoFarine->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoFarine->setWordWrap(true);

      lableTipoGocce->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoGocce->setWordWrap(true);

      lableLvFondenza->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableLvFondenza->setWordWrap(true);

      lableTipoGranella->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoGranella->setWordWrap(true);

      lableFormaC->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableFormaC->setWordWrap(true);

      lableTipoAroma->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoAroma->setWordWrap(true);

      lableTipoBong->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoBong->setWordWrap(true);

      lableTipoDimensioni->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoDimensioni->setWordWrap(true);

      lableTipoVapo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoVapo->setWordWrap(true);

      lableTipoGrinder->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoGrinder->setWordWrap(true);



      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteBiscotti()));
      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteCioccolato()));
      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteInfusi()));

      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteFormaBong()));
      connect(backer,SIGNAL(toggled(bool)),this,SLOT(scelteDimensioniB(bool)));
      connect(dritto,SIGNAL(toggled(bool)),this,SLOT(scelteDimensioniD(bool)));

      //CONNECT CHECKFARINE
      connect(grano,SIGNAL(toggled(bool)),this,SLOT(checkGrano(bool)));
      connect(riso,SIGNAL(toggled(bool)),this,SLOT(checkRiso(bool)));
      connect(mandorle,SIGNAL(toggled(bool)),this,SLOT(checkMandorle(bool)));
      connect(castagne,SIGNAL(toggled(bool)),this,SLOT(checkCastagne(bool)));
      connect(amaranto,SIGNAL(toggled(bool)),this,SLOT(checkAmaranto(bool)));
      //CONNECT CHECKGOCCE
      connect(senza,SIGNAL(toggled(bool)),this,SLOT(checkSenza(bool)));
      connect(latte,SIGNAL(toggled(bool)),this,SLOT(checkLatte(bool)));
      connect(fondente,SIGNAL(toggled(bool)),this,SLOT(checkFondente(bool)));
      connect(bianco,SIGNAL(toggled(bool)),this,SLOT(checkBianco(bool)));
      //CONNECT CHECKFONDENZA
      connect(nessuna,SIGNAL(toggled(bool)),this,SLOT(checkNessuna(bool)));
      connect(bassa,SIGNAL(toggled(bool)),this,SLOT(checkBassa(bool)));
      connect(media,SIGNAL(toggled(bool)),this,SLOT(checkMedia(bool)));
      connect(alta,SIGNAL(toggled(bool)),this,SLOT(checkAlta(bool)));
      //CONNECT CHECKGRANELLA
      connect(cocco,SIGNAL(toggled(bool)),this,SLOT(checkCocco(bool)));
      connect(noce,SIGNAL(toggled(bool)),this,SLOT(checkNoce(bool)));
      connect(mandorla,SIGNAL(toggled(bool)),this,SLOT(checkMandorla(bool)));
      connect(nocciola,SIGNAL(toggled(bool)),this,SLOT(checkNocciola(bool)));
      //CONNECT CHECKFORMAC
      //connect(stecche,SIGNAL(toggled(bool)),this,SLOT(checkStecche(bool)));
      //connect(praline,SIGNAL(toggled(bool)),this,SLOT(checkPraline(bool)));

      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteVapo()));
      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteGrinder()));

      connect(backer,SIGNAL(stateChanged(int)),this,SLOT(resetDim()));
      connect(dritto,SIGNAL(stateChanged(int)),this,SLOT(resetDim()));
}
void Ricerca::scelteBiscotti(){
    if(tipoProdotto->currentText()=="Biscotti"){
        //FARINE
        lableTipoFarine->show();
        grano->show();
        riso->show();
        mandorle->show();
        castagne->show();
        amaranto->show();
        //GOCCE
        lableTipoGocce->show();
        senza->show();
        latte->show();
        fondente->show();
        bianco->show();

    }
    else{
        lableTipoFarine->hide();
        grano->hide();
        riso->hide();
        mandorle->hide();
        castagne->hide();
        amaranto->hide();

        lableTipoGocce->hide();
        senza->hide();
        latte->hide();
        fondente->hide();
        bianco->hide();
    }
}

void Ricerca::scelteCioccolato(){
    if(tipoProdotto->currentText()=="Cioccolata"){
        lableLvFondenza->show();
        nessuna->show();
        bassa->show();
        media->show();
        alta->show();

        lableTipoGranella->show();
        cocco->show();
        noce->show();
        mandorla->show();
        nocciola->show();

        lableFormaC->show();
        stecche->show();
        //praline->show();
    }
    else{
        lableLvFondenza->hide();
        nessuna->hide();
        bassa->hide();
        media->hide();
        alta->hide();

        lableTipoGranella->hide();
        cocco->hide();
        noce->hide();
        mandorla->hide();
        nocciola->hide();

        lableFormaC->hide();
        stecche->hide();
        //praline->hide();
    }
}

void Ricerca::scelteInfusi(){
    if(tipoProdotto->currentText()=="Infusi"){
        lableTipoAroma->show();
        aroma1->show();
        aroma2->show();
        sfuso->show();
    }
    else{
        lableTipoAroma->hide();
        aroma1->hide();
        aroma2->hide();
        sfuso->hide();
    }
}

void Ricerca::scelteFormaBong(){
    if(tipoProdotto->currentText()=="Bong"){
        lableTipoBong->show();
        backer->show();
        dritto->show();
        qualsiasi->show();
    }
    else{
        lableTipoBong->hide();
        backer->hide();
        dritto->hide();
        qualsiasi->hide();
    }
}

void Ricerca::scelteDimensioniB(bool flag){
    if(flag) dritto->setEnabled(false);
    else dritto->setEnabled(true);
    dimBacker->show();
    dimDritto->hide();
}
void Ricerca::scelteDimensioniD(bool flag){
    if(flag) backer->setEnabled(false);
    else backer->setEnabled(true);
    dimBacker->hide();
    dimDritto->show();
}
void Ricerca::scelteVapo(){
    if(tipoProdotto->currentText()=="Vaporizzatore"){
        lableTipoVapo->show();
        schermo->show();
        capienza->show();
        velocita->show();
    }
    else{
        lableTipoVapo->hide();
        schermo->hide();
        capienza->hide();
        velocita->hide();
    }
}
void Ricerca::scelteGrinder(){
    if(tipoProdotto->currentText()=="Grinder"){
        lableTipoGrinder->show();
        ndenti->show();
        raccoglipoll->show();
    }
    else{
        lableTipoGrinder->hide();
        ndenti->hide();
        raccoglipoll->hide();
    }
}
void Ricerca::resetDim(){
    if(backer->isEnabled()==true && dritto->isEnabled()==true){
        dimBacker->hide();
        dimDritto->hide();
    }
}
//CHECKFARINE
void Ricerca::checkGrano(bool f){
    if(f){
        riso->setEnabled(false);
        mandorle->setEnabled(false);
        castagne->setEnabled(false);
        amaranto->setEnabled(false);
    }
    else{
        riso->setEnabled(true);
        mandorle->setEnabled(true);
        castagne->setEnabled(true);
        amaranto->setEnabled(true);
    }
}
void Ricerca::checkRiso(bool f){
    if(f){
        grano->setEnabled(false);
        mandorle->setEnabled(false);
        castagne->setEnabled(false);
        amaranto->setEnabled(false);
    }
    else{
        grano->setEnabled(true);
        mandorle->setEnabled(true);
        castagne->setEnabled(true);
        amaranto->setEnabled(true);
    }
}
void Ricerca::checkMandorle(bool f){
    if(f){
        grano->setEnabled(false);
        riso->setEnabled(false);
        castagne->setEnabled(false);
        amaranto->setEnabled(false);
    }
    else{
        grano->setEnabled(true);
        riso->setEnabled(true);
        castagne->setEnabled(true);
        amaranto->setEnabled(true);
    }
}
void Ricerca::checkCastagne(bool f){
    if(f){
        grano->setEnabled(false);
        riso->setEnabled(false);
        mandorle->setEnabled(false);
        amaranto->setEnabled(false);
    }
    else{
        grano->setEnabled(true);
        riso->setEnabled(true);
        mandorle->setEnabled(true);
        amaranto->setEnabled(true);
    }
}
void Ricerca::checkAmaranto(bool f){
    if(f){
        grano->setEnabled(false);
        riso->setEnabled(false);
        castagne->setEnabled(false);
        mandorle->setEnabled(false);
    }
    else{
        grano->setEnabled(true);
        riso->setEnabled(true);
        castagne->setEnabled(true);
        mandorle->setEnabled(true);
    }
}
//CHECKGOCCE
void Ricerca::checkSenza(bool f){
    if(f){
        latte->setEnabled(false);
        fondente->setEnabled(false);
        bianco->setEnabled(false);
    }
    else{
        latte->setEnabled(true);
        fondente->setEnabled(true);
        bianco->setEnabled(true);
    }
}
void Ricerca::checkLatte(bool f){
    if(f){
        senza->setEnabled(false);
        fondente->setEnabled(false);
        bianco->setEnabled(false);
    }
    else{
        senza->setEnabled(true);
        fondente->setEnabled(true);
        bianco->setEnabled(true);
    }
}
void Ricerca::checkFondente(bool f){
    if(f){
        senza->setEnabled(false);
        latte->setEnabled(false);
        bianco->setEnabled(false);
    }
    else{
        senza->setEnabled(true);
        latte->setEnabled(true);
        bianco->setEnabled(true);
    }
}
void Ricerca::checkBianco(bool f){
    if(f){
        senza->setEnabled(false);
        latte->setEnabled(false);
        fondente->setEnabled(false);
    }
    else{
        senza->setEnabled(true);
        latte->setEnabled(true);
        fondente->setEnabled(true);
    }
}
//CHECKFONDENZA
void Ricerca::checkNessuna(bool f){
    if(f){
        bassa->setEnabled(false);
        media->setEnabled(false);
        alta->setEnabled(false);
    }
    else{
        bassa->setEnabled(true);
        media->setEnabled(true);
        alta->setEnabled(true);
    }
}
void Ricerca::checkBassa(bool f){
    if(f){
        nessuna->setEnabled(false);
        media->setEnabled(false);
        alta->setEnabled(false);
    }
    else{
        nessuna->setEnabled(true);
        media->setEnabled(true);
        alta->setEnabled(true);
    }
}
void Ricerca::checkMedia(bool f){
    if(f){
        nessuna->setEnabled(false);
        bassa->setEnabled(false);
        alta->setEnabled(false);
    }
    else{
        nessuna->setEnabled(true);
        bassa->setEnabled(true);
        alta->setEnabled(true);
    }
}
void Ricerca::checkAlta(bool f){
    if(f){
        nessuna->setEnabled(false);
        bassa->setEnabled(false);
        media->setEnabled(false);
    }
    else{
        nessuna->setEnabled(true);
        bassa->setEnabled(true);
        media->setEnabled(true);
    }
}
//CHECKGRANELLA
void Ricerca::checkCocco(bool f){
    if(f){
        noce->setEnabled(false);
        mandorla->setEnabled(false);
        nocciola->setEnabled(false);
    }
    else{
        noce->setEnabled(true);
        mandorla->setEnabled(true);
        nocciola->setEnabled(true);
    }
}
void Ricerca::checkNoce(bool f){
    if(f){
        cocco->setEnabled(false);
        mandorla->setEnabled(false);
        nocciola->setEnabled(false);
    }
    else{
        cocco->setEnabled(true);
        mandorla->setEnabled(true);
        nocciola->setEnabled(true);
    }
}
void Ricerca::checkMandorla(bool f){
    if(f){
        cocco->setEnabled(false);
        noce->setEnabled(false);
        nocciola->setEnabled(false);
    }
    else{
        cocco->setEnabled(true);
        noce->setEnabled(true);
        nocciola->setEnabled(true);
    }
}
void Ricerca::checkNocciola(bool f){
    if(f){
        cocco->setEnabled(false);
        noce->setEnabled(false);
        mandorla->setEnabled(false);
    }
    else{
        cocco->setEnabled(true);
        noce->setEnabled(true);
        mandorla->setEnabled(true);
    }
}
void Ricerca::checkQualsiasi(bool f){
    if(f){
        dritto->setEnabled(false);
        backer->setEnabled(false);
    }
    else{
        dritto->setEnabled(true);
        backer->setEnabled(true);
    }
}
/*void Ricerca::checkStecche(bool f){
    if(f) praline->setEnabled(false);
    else praline->setEnabled(true);
}
void Ricerca::checkPraline(bool f){
    if(f) stecche->setEnabled(false);
    else stecche->setEnabled(true);
}*/

//GET
QPushButton* Ricerca::getCercaBut() const {
    return  cerca;
}
std::string Ricerca::getTipoProdotto() const{
    if(tipoProdotto->currentText()=="Biscotti"){
        return "Biscotti";
    }
    else if(tipoProdotto->currentText()=="Cioccolata"){
        return "Cioccolata";
    }
    else if(tipoProdotto->currentText()=="Infusi"){
        return "Infusi";
    }
    else if(tipoProdotto->currentText()=="Bong"){
        return "Bong";
    }
    else if(tipoProdotto->currentText()=="Vaporizzatore"){
        return "Vaporizzatore";
    } else if(tipoProdotto->currentText()=="Grinder"){
        return "Grinder";
    }
    else return "Seleziona prodotto...";
}
int Ricerca::getTipoFarina() const{
    if(grano->isChecked()==true){
        return 1;
    }
    else if(riso->isChecked()==true){
        return 2;
    }
    else if(mandorle->isChecked()==true){
        return 3;
    }
    else if(castagne->isChecked()==true){
        return 4;
    }
    else if(amaranto->isChecked()==true){
        return 5;
    }
    else return 0;
}
int Ricerca::getTipoGocce() const{
    if(senza->isChecked()==true){
        return 1;
    }
    else if(latte->isChecked()==true){
        return 2;
    }
    else if(fondente->isChecked()==true){
        return 3;
    }
    else if(bianco->isChecked()==true){
        return 4;
    }
    else return 0;
}
int Ricerca::getLvFondenza() const{
    if(nessuna->isChecked()==true){
        return 1;
    }
    else if(bassa->isChecked()==true){
        return 2;
    }
    else if(media->isChecked()==true){
        return 3;
    }
    else if(alta->isChecked()==true){
        return 4;
    }
    else return 0;
}
int Ricerca::getTipoGranella() const{
    if(cocco->isChecked()==true){
        return 1;
    }
    else if(noce->isChecked()==true){
        return 2;
    }
    else if(mandorla->isChecked()==true){
        return 3;
    }
    else if(nocciola->isChecked()==true){
        return 4;
    }
    else return 0;
}
bool Ricerca::getFormaC() const{
    if(stecche->isChecked()==true) return true;
    else return false;
}
std::vector<std::string> Ricerca::getAroma() const{
    std::vector<std::string> aromaFinale;
    aromaFinale.push_back(aroma1->currentText().toStdString());
    if(aroma2->currentText().toStdString()!="Nessun aroma")
        aromaFinale.push_back(aroma2->currentText().toStdString());
    return aromaFinale;
}
bool Ricerca::getSfuso() const{
    if(sfuso->isChecked()==true) return true;
    else return false;
}
int Ricerca::getFormaB() const{
    if(backer->isChecked()==true){
        return 1 ;
    }
    else if(dritto->isChecked()==true){
        return 2;
    }
    else return 3;
}
int Ricerca::getAltezza() const{
    if(dimBacker->currentText()=="33X4.6 cm"){
        return 33;
    }
    else if(dimBacker->currentText()=="45X4.6 cm"){
        return 45;
    }
    else if(dimDritto->currentText()=="24X3.1 cm"){
        return 24;
    }
    else if(dimDritto->currentText()=="32X4.1 cm"){
        return 32;
    }
    else if(dimDritto->currentText()=="37X5.3 cm"){
        return 37;
    }
    else if(dimDritto->currentText()=="46X6.7 cm"){
        return 46;
    }
    else return 0;
}
double Ricerca::getLarghezza() const{
    if(dimBacker->currentText()=="33X4.6 cm" || dimBacker->currentText()=="45X4.6 cm"){
        return 4.6;
    }
    else if(dimDritto->currentText()=="24X3.1 cm"){
        return 3.1;
    }
    else if(dimDritto->currentText()=="32X4.1 cm"){
        return 4.1;
    }
    else if(dimDritto->currentText()=="37X5.3 cm"){
        return 5.3;
    }
    else if(dimDritto->currentText()=="46X6.7 cm"){
        return 6.7;
    }
    else return 0;
}
int Ricerca::getVelocita() const{
    if(velocita->currentText()=="Lv 1"){
        return 1 ;
    }
    else if(velocita->currentText()=="Lv 2"){
        return 2;
    }
    else if(velocita->currentText()=="Lv 3"){
        return 3;
    }
    else return 0;
}
int Ricerca::getCapienza() const{
    if(capienza->currentText()=="1 gr"){
        return 1 ;
    }
    else if(capienza->currentText()=="2 gr"){
        return 2;
    }
    else if(capienza->currentText()=="3 gr"){
        return 3;
    }
    else if(capienza->currentText()=="4 gr"){
        return 4;
    }
    return 0;
}
bool Ricerca::getSchermo() const{
    if(schermo->isChecked()==true) return true;
    else return false;
}
int Ricerca::getNDenti() const{
    if(ndenti->currentText()=="6"){
        return 6 ;
    }
    else if(ndenti->currentText()=="12"){
        return 12;
    }
    else if(ndenti->currentText()=="24"){
        return 24;
    }
    else if(ndenti->currentText()=="30"){
        return 30;
    }
    else if(ndenti->currentText()=="36"){
        return 30;
    }
    else return 0;
}
bool Ricerca::getRaccogliP() const{
    if(raccoglipoll->isChecked()==true) return true;
    else return false;
}
elementoWidget* Ricerca::getListaRicerca() const{
    return catalogo;
}