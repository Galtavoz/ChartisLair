#include"catalogoCompleto.h"

catalogoCompleto::catalogoCompleto(QWidget* p):
    QWidget(p),
    listaCatalogo(new elementoWidget(this)),
    modifica(new QPushButton(this)),
    rimuovi(new QPushButton(this))
{
    QVBoxLayout* menuPiatti = new QVBoxLayout(this);
    QHBoxLayout* bottoni = new QHBoxLayout();

    listaCatalogo->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    modifica->setText("Modifica");
    rimuovi->setText("Rimuovi");

    bottoni->addWidget(modifica);
    bottoni->addWidget(rimuovi);

    menuPiatti->addWidget(listaCatalogo);
    menuPiatti->addLayout(bottoni);
}

elementoWidget* catalogoCompleto::getLista() const {
    return listaCatalogo;
}

QPushButton* catalogoCompleto::getModifica() const {
    return modifica;
}

QPushButton* catalogoCompleto::getRimuovi() const {
    return rimuovi;
}
