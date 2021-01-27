#include"GUI/controller.h"

Controller::Controller(Modello* m,QWidget* p):
    parent(p),
    modello(m),
    menu(new Menu(this)),
    ricerca(new Ricerca(this)),
    catCompleto(new catalogoCompleto(this)),
    file(QFileDialog::getOpenFileName(this,tr("Scegli file"),"../ChartisLair/SALVATAGGIO","File XML(*.xml)")){

    QVBoxLayout* controller = new QVBoxLayout(this);

    setMinimumSize(500,500);
    setWindowTitle("Chartis'Lair");
    setWindowIcon(QIcon("../ChartisLair/IMMAGINI/logo.png"));

    QRect screenGeometry = QGuiApplication::screens()[0]->geometry();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), screenGeometry));

    controller->addWidget(menu);
    controller->addWidget(catCompleto);
    controller->addWidget(ricerca);
    caricaDati();

    menu->show();
    catCompleto->show();
    ricerca->hide();

    connect(menu->getEsci(),SIGNAL(triggered()),this,SLOT(esci()));
    connect(menu->getCarica(),SIGNAL(triggered()),this,SLOT(carica()));
    connect(menu->getHome(),SIGNAL(triggered()),this,SLOT(tornaHome()));
    connect(menu->getRicerca(),SIGNAL(triggered()),this,SLOT(vediRicerca()));
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
void Controller::esci() {
    close();
}
void Controller::carica() {
    caricaDatiXML();
}
void Controller::tornaHome(){
    ricerca->hide();
    catCompleto->show();
}
void Controller::vediRicerca(){

    catCompleto->hide();
    ricerca->show();
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
