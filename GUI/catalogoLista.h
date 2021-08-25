#ifndef CATALOGOLISTA_H
#define CATALOGOLISTA_H

#include<QListWidgetItem>

#include"gerarchia.h"
#include"DeepPtr.h"

class catalogoLista: public QListWidgetItem {
private:
    QWidget* parent;
   prodotto* prodotti;
public:
    catalogoLista(QWidget* = nullptr, prodotto* = nullptr);
    void aggiornaLista();
    prodotto* getSelezionato() const;
};

#endif // CATALOGOLISTA_H
