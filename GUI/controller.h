#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QWidget>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QFileDialog>
#include<QScrollBar>
#include<QDesktopWidget>
#include<QGuiApplication>
#include<QApplication>
#include<QScreen>
#include<QTextDocument>
#include<QPixmap>
#include<QIcon>

#include"modello.h"
#include"GUI/popup.h"
#include"GUI/menu.h"
#include"GUI/catalogoCompleto.h"

class Controller: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    Modello* modello;
    Menu* menu;
    catalogoCompleto* catCompleto;
    QString file;
public:
    Controller(Modello*, QWidget* = nullptr);
    ~Controller();
    void caricaDati();
    void caricaDatiXML();
    Modello* getModello() const;
    void disabilita();
    void abilita();
public slots:
        void esci();
        void carica();
        void tornaHome();
        void vediInfoSviluppatore();
        void vediInfoCatalogo();
};
#endif // CONTROLLER_H
