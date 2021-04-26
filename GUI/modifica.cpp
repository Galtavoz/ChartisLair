#include "modifica.h"

Modifica::Modifica(QWidget* p):
    parent(p),
    labelNomeRegalo(new QLabel(this)),
    nome(new QLineEdit(this)),
    regalo(new QCheckBox(this)),
    labelIngredienti(new QLabel(this)),
    labelPeso(new QLabel(this)),
    peso(new QLineEdit(this)),
    labelHemp(new QLabel(this)),
    hempI(new QCheckBox(this)),
    hempS(new QCheckBox(this)),
    labelProd(new QLabel(this)),
    prodI(new QCheckBox(this)),
    prodO(new QCheckBox(this)),
    labelColori(new QLabel(this)),
    colori(new QComboBox(this)),
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
    formaC(new QComboBox(this)),

    lableTipoAroma1(new QLabel(this)),
    aroma1(new QComboBox(this)),
    lableTipoAroma2(new QLabel(this)),
    aroma2(new QComboBox(this)),
    lableSfuso(new QLabel(this)),
    sfuso(new QComboBox(this)),
//NON CONSUMABILI
    lableTipoBong(new QLabel(this)),
    backer(new QCheckBox(this)),
    dritto(new QCheckBox(this)),
    lableTipoDimensioni(new QLabel(this)),
    dimBacker(new QComboBox(this)),
    dimDritto(new QComboBox(this)),

    lableSchermo(new QLabel(this)),
    schermo(new QComboBox(this)),
    lableCapienza(new QLabel(this)),
    capienza(new QComboBox(this)),
    lableVelocita(new QLabel(this)),
    velocita(new QComboBox(this)),

    lableNDenti(new QLabel(this)),
    ndenti(new QComboBox(this)),
    lableRaccPoll(new QLabel(this)),
    raccoglipoll(new QComboBox(this)),

    salva(new QPushButton(this))
    {


     QVBoxLayout* layoutMod         = new QVBoxLayout(this);
     QHBoxLayout* layoutNomeRegalo  = new QHBoxLayout();
     QHBoxLayout* layoutPeso        = new QHBoxLayout();
     QHBoxLayout* layoutHemp        = new QHBoxLayout();
     QHBoxLayout* layoutProduzione  = new QHBoxLayout();
     QHBoxLayout* layoutColori      = new QHBoxLayout();
     QHBoxLayout* layoutFarine      = new QHBoxLayout();
     QHBoxLayout* layoutGocce       = new QHBoxLayout();
     QHBoxLayout* layoutFondenza    = new QHBoxLayout();
     QHBoxLayout* layoutGranella    = new QHBoxLayout();
     QHBoxLayout* layoutFormaC      = new QHBoxLayout();
     QHBoxLayout* layoutAroma1      = new QHBoxLayout();
     QHBoxLayout* layoutAroma2      = new QHBoxLayout();
     QHBoxLayout* layoutSfuso       = new QHBoxLayout();
     QHBoxLayout* layoutFormaB      = new QHBoxLayout();
     QHBoxLayout* layoutDimensioni  = new QHBoxLayout();
     QHBoxLayout* layoutSchermo     = new QHBoxLayout();
     QHBoxLayout* layoutCapienza    = new QHBoxLayout();
     QHBoxLayout* layoutVelocita    = new QHBoxLayout();
     QHBoxLayout* layoutNDenti      = new QHBoxLayout();
     QHBoxLayout* layoutRaccpolline = new QHBoxLayout();


     layoutMod->addWidget(tipoProdotto);
     layoutMod->addLayout(layoutNomeRegalo);
     layoutMod->addWidget(labelIngredienti);

     layoutMod->addLayout(layoutPeso);
     layoutMod->addLayout(layoutHemp);
     layoutMod->addLayout(layoutProduzione);
     layoutMod->addLayout(layoutColori);

     layoutMod->addLayout(layoutFarine);
     layoutMod->addLayout(layoutGocce);
     layoutMod->addLayout(layoutFondenza);
     layoutMod->addLayout(layoutGranella);
     layoutMod->addLayout(layoutFormaC);
     layoutMod->addLayout(layoutAroma1);
     layoutMod->addLayout(layoutAroma2);
     layoutMod->addLayout(layoutSfuso);
     layoutMod->addLayout(layoutFormaB);
     layoutMod->addLayout(layoutDimensioni);
     layoutMod->addLayout(layoutSchermo);
     layoutMod->addLayout(layoutCapienza);
     layoutMod->addLayout(layoutVelocita);
     layoutMod->addLayout(layoutNDenti);
     layoutMod->addLayout(layoutRaccpolline);
     layoutMod->addWidget(salva);

     layoutNomeRegalo->addWidget(labelNomeRegalo);
     layoutNomeRegalo->addWidget(nome);
     layoutNomeRegalo->addWidget(regalo);

     layoutPeso->addWidget(labelPeso);
     layoutPeso->addWidget(peso);

     layoutHemp->addWidget(labelHemp);
     layoutHemp->addWidget(hempI);
     layoutHemp->addWidget(hempS);

     layoutProduzione->addWidget(labelProd);
     layoutProduzione->addWidget(prodI);
     layoutProduzione->addWidget(prodO);

     layoutColori->addWidget(labelColori);
     layoutColori->addWidget(colori);

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
     layoutFormaC->addWidget(formaC);

     layoutAroma1->addWidget(lableTipoAroma1);
     layoutAroma1->addWidget(aroma1);
     layoutAroma2->addWidget(lableTipoAroma2);
     layoutAroma2->addWidget(aroma2);
     layoutSfuso->addWidget(lableSfuso);
     layoutSfuso->addWidget(sfuso);

     layoutFormaB->addWidget(lableTipoBong);
     layoutFormaB->addWidget(backer);
     layoutFormaB->addWidget(dritto);

     layoutDimensioni->addWidget(lableTipoDimensioni);
     layoutDimensioni->addWidget(dimBacker);
     layoutDimensioni->addWidget(dimDritto);

     layoutSchermo->addWidget(lableSchermo);
     layoutSchermo->addWidget(schermo);
     layoutCapienza->addWidget(lableCapienza);
     layoutCapienza->addWidget(capienza);
     layoutVelocita->addWidget(lableVelocita);
     layoutVelocita->addWidget(velocita);

     layoutNDenti->addWidget(lableNDenti);
     layoutNDenti->addWidget(ndenti);
     layoutRaccpolline->addWidget(lableRaccPoll);
     layoutRaccpolline->addWidget(raccoglipoll);


     salva->show();
     salva->setText("Salva");
     QList<QString> prodotti={"Seleziona prodotto...","Biscotti","Cioccolata","Infusi","Bong","Vaporizzatore","Grinder"};
     for(int i=0;i<prodotti.length();++i)
             tipoProdotto->addItem(prodotti[i]);
      tipoProdotto->setCurrentIndex(0);

      labelNomeRegalo->hide();
      nome->hide();
      regalo->hide();
      labelIngredienti->hide();
      labelPeso->hide();
      peso->hide();
      labelHemp->hide();
      hempI->hide();
      hempS->hide();
      labelProd->hide();
      prodI->hide();
      prodO->hide();
      labelColori->hide();
      colori->hide();

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
      formaC->hide();

      lableTipoAroma1->hide();
      aroma1->hide();
      lableTipoAroma2->hide();
      aroma2->hide();
      lableSfuso->hide();
      sfuso->hide();

      lableTipoBong->hide();
      backer->hide();
      dritto->hide();
      lableTipoDimensioni->hide();
      dimBacker->hide();
      dimDritto->hide();

      lableSchermo->hide();
      schermo->hide();
      lableCapienza->hide();
      capienza->hide();
      lableVelocita->hide();
      velocita->hide();

      lableNDenti->hide();
      ndenti->hide();
      lableRaccPoll->hide();
      raccoglipoll->hide();

      labelNomeRegalo->setText("Inserisci il nome e spunta se confezione regalo");
      regalo->setText("Confezione Regalo?");
      labelPeso->setText("Peso:");
      labelHemp->setText("Tipologia di hemp:");
      hempI->setText("Indica");
      hempS->setText("Sativa");
      prodI->setText("Indoor");
      prodO->setText("Outdoor");
      labelProd->setText("Tipo di produzione:");
      labelColori->setText("Colore:");
      QList<QString> listaColori={"Bianco","Blu","Verde","Arancione","Viola","Fucsia","Oro","Giallo"};
      for(int i=0;i<listaColori.length();++i)
              colori->addItem(listaColori[i]);
       colori->setCurrentIndex(0);

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
      bassa->setText("50%");
      media->setText("75%");
      alta->setText("90%");

      lableTipoGranella->setText("Seleziona la tipologia di granella :");
      cocco->setText("Cocco");
      noce->setText("Noce");
      mandorla->setText("Mandorla");
      nocciola->setText("Nocciola");

      lableFormaC->setText("Seleziona la tipologia di forma :");
      QList<QString> listaFormaC={"Stecche","Praline"};
      for(int i=0;i<listaFormaC.length();++i)
          formaC->addItem(listaFormaC[i]);
      formaC->setCurrentIndex(0);

      lableTipoAroma1->setText("Seleziona il primo aroma: ");
      QList<QString> listaaromi={"Albicocca","Limone","Liquirizia","Menta","Zenzero"};
      for(int i=0;i<listaaromi.length();++i)
          aroma1->addItem(listaaromi[i]);
      aroma1->setCurrentIndex(0);
      lableTipoAroma2->setText("Seleziona il secondo aroma , se desiderato, senno lasciare 'Nessun aroma': ");
      QList<QString> listaaromi1={"Nessun aroma","Albicocca","Limone","Liquirizia","Menta","Zenzero"};
      for(int i=0;i<listaaromi1.length();++i)
          aroma2->addItem(listaaromi1[i]);
      aroma2->setCurrentIndex(0);
      lableSfuso->setText("Seleziona se l' infuso è sfuso oppure no.");
      QList<QString> listaSfuso={"Sfuso","Non sfuso"};
      for(int i=0;i<listaSfuso.length();++i)
          sfuso->addItem(listaSfuso[i]);
      sfuso->setCurrentIndex(0);


      lableTipoBong->setText("Seleziona la forma del bong");
      backer->setText("Backer");
      dritto->setText("Dritto");
      lableTipoDimensioni->setText("Seleziona le dimensioni del bong");
      QList<QString> listaDimB={"33X4.6 cm","45X4.6 cm"};
      for(int i=0;i<listaDimB.length();++i)
          dimBacker->addItem(listaDimB[i]);
      QList<QString> listaDimD={"24X3.1 cm","32X4.1 cm","37X5.3 cm","46X6.7 cm"};
      for(int i=0;i<listaDimD.length();++i)
          dimDritto->addItem(listaDimD[i]);

      lableSchermo->setText("Selezionare se il vaporizzatore ha schermo o meno");
      QList<QString> listaSchermo={"Schermo","No schermo"};
      for(int i=0;i<listaSchermo.length();++i)
          schermo->addItem(listaSchermo[i]);
      schermo->setCurrentIndex(0);
      lableCapienza->setText("Selezionare la quantita massima di carico del vaporizzatore");
      QList<QString> listaCapienza={"1 gr","2 gr","3 gr","4 gr"};
      for(int i=0;i<listaCapienza.length();++i)
          capienza->addItem(listaCapienza[i]);
      capienza->setCurrentIndex(0);
      lableVelocita->setText("Selezionare il livello di velocita il cui il prodotto fa evaporare l'erba");
      QList<QString> listaVelocita={"Lv 1","Lv 2","Lv 3"};
      for(int i=0;i<listaVelocita.length();++i)
          velocita->addItem(listaVelocita[i]);
      velocita->setCurrentIndex(0);

      lableNDenti->setText("Seleziona il numero di denti presenti nel grider :");
      QList<QString> listaDenti={"6","12","24","30","36"};
      for(int i=0;i<listaDenti.length();++i)
          ndenti->addItem(listaDenti[i]);
      lableRaccPoll->setText("Seleziona se il grinder ha o no il raccogli polline");
      QList<QString> raccogliP={"Con raccogli polline","Senza raccogli polline"};
      for(int i=0;i<raccogliP.length();++i)
          raccoglipoll->addItem(raccogliP[i]);
      raccoglipoll->setCurrentIndex(0);;



      labelNomeRegalo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      labelNomeRegalo->setWordWrap(true);

      labelIngredienti->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      labelIngredienti->setWordWrap(true);

      labelPeso->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      labelPeso->setWordWrap(true);

      labelHemp->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      labelHemp->setWordWrap(true);

      labelProd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      labelProd->setWordWrap(true);

      labelColori->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      labelColori->setWordWrap(true);

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

      lableTipoAroma1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoAroma1->setWordWrap(true);
      lableTipoAroma2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoAroma2->setWordWrap(true);
      lableSfuso->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableSfuso->setWordWrap(true);

      lableTipoBong->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoBong->setWordWrap(true);

      lableTipoDimensioni->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableTipoDimensioni->setWordWrap(true);

      lableSchermo->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableSchermo->setWordWrap(true);
      lableCapienza->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableCapienza->setWordWrap(true);
      lableVelocita->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableVelocita->setWordWrap(true);

      lableNDenti->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableNDenti->setWordWrap(true);
      lableRaccPoll->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
      lableRaccPoll->setWordWrap(true);



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
      //CONNECT CHECKHEMP
      connect(hempI,SIGNAL(toggled(bool)),this,SLOT(checkIndica(bool)));
      connect(hempS,SIGNAL(toggled(bool)),this,SLOT(checkSativa(bool)));
      //CONNECT CHECKPRODUZIONE
      connect(prodI,SIGNAL(toggled(bool)),this,SLOT(checkIndoor(bool)));
      connect(prodO,SIGNAL(toggled(bool)),this,SLOT(checkOutdoor(bool)));
      //CONNECT CHECKGRANELLA
      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteVapo()));
      connect(tipoProdotto,SIGNAL(currentIndexChanged(int)),this,SLOT(scelteGrinder()));

      connect(backer,SIGNAL(stateChanged(int)),this,SLOT(resetDim()));
      connect(dritto,SIGNAL(stateChanged(int)),this,SLOT(resetDim()));
}
void Modifica::setProdotto(catalogo *p){
    prodottoDaModificare=p;
}
