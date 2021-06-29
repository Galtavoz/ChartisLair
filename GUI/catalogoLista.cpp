#include"GUI/catalogoLista.h"

catalogoLista::catalogoLista(QWidget* p,catalogo* c): parent(p), prodotti(c) {
    aggiornaPiatto();
}

void catalogoLista::aggiornaPiatto() {
    QString path;
    if(dynamic_cast<biscotti*>(prodotti)) path=QString::fromStdString("../ChartisLair/IMMAGINI/biscotti.png");
    if(dynamic_cast<cioccolata*>(prodotti)){
        if(dynamic_cast<cioccolata*>(prodotti)->getForma())path=QString::fromStdString("../ChartisLair/IMMAGINI/cioccolata.png");
        else path=QString::fromStdString("../ChartisLair/IMMAGINI/download.png");
    }
    if(dynamic_cast<infusi*>(prodotti)) path=QString::fromStdString("../ChartisLair/IMMAGINI/infuso.png");
    if(dynamic_cast<bong*>(prodotti)){
        if(dynamic_cast<bong*>(prodotti)->getForma()) path=QString::fromStdString("../ChartisLair/IMMAGINI/bongB.png");
        else path=QString::fromStdString("../ChartisLair/IMMAGINI/bong.png");
    }
    if(dynamic_cast<vaporizzatore*>(prodotti)){
        if(dynamic_cast<vaporizzatore*>(prodotti)->getSchermo()) path=QString::fromStdString("../ChartisLair/IMMAGINI/vapo.png");
        else path=QString::fromStdString("../ChartisLair/IMMAGINI/vapoSS.png");
    }
    if(dynamic_cast<grinder*>(prodotti)) path=QString::fromStdString("../ChartisLair/IMMAGINI/grinder.png");
    QPixmap p(path);
    setIcon(p.scaled(400,400,Qt::AspectRatioMode::KeepAspectRatio));
    setText(QString::fromStdString(prodotti->visualizzaInfo()));
}

catalogo* catalogoLista::getSelezionato() const {
    return prodotti;
}
