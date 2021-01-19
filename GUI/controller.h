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
#include"modello.h"

class Controller: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    Modello* modello;
public:
    Controller(Modello*, QWidget* = nullptr);
    ~Controller();
    void caricaDati();
    void caricaDatiXML();
     Modello* getModello() const;
};
#endif // CONTROLLER_H
