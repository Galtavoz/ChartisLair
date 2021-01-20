#include"GUI/catalogoLista.h"

catalogoLista::catalogoLista(QWidget* p,catalogo* c): parent(p), prodotti(c) {
    aggiornaPiatto();
}

void catalogoLista::aggiornaPiatto() {
    QString path;
    if(dynamic_cast<biscotti*>(prodotti)) path=QString::fromStdString(":/IMMAGINI/biscotti.jpg");
    if(dynamic_cast<cioccolata*>(prodotti)) path=QString::fromStdString(":/IMMAGINI/cioccolata.jpg");
    if(dynamic_cast<infusi*>(prodotti)) path=QString::fromStdString(":/IMMAGINI/infusi.jpg");
    if(dynamic_cast<bong*>(prodotti)) path=QString::fromStdString(":/IMMAGINI/bong.jpg");
    if(dynamic_cast<vaporizzatore*>(prodotti)) path=QString::fromStdString(":/IMMAGINI/vaporizzatore.jpg");
    if(dynamic_cast<grinder*>(prodotti)) path=QString::fromStdString(":/IMMAGINI/grinder.jpg");
    QPixmap p(path);
    setIcon(p.scaled(400,400,Qt::AspectRatioMode::KeepAspectRatio));
    setText(QString::fromStdString(prodotti->visualizzaInfo()));
}

catalogo* catalogoLista::getSelezionato() const {
    return prodotti;
}
