#ifndef CATALOGOLISTA_H
#define CATALOGOLISTA_H

#include<QListWidgetItem>

#include"gerarchia.h"
#include"DeepPtr.h"

class catalogoLista: public QListWidgetItem {
private:
    QWidget* parent;
   catalogo* prodotti;
public:
    catalogoLista(QWidget* = nullptr, catalogo* = nullptr);
    void aggiornaLista();
    catalogo* getSelezionato() const;
};

#endif // CATALOGOLISTA_H
