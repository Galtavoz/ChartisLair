#include"GUI/controller.h"

Controller::Controller(Modello* m,QWidget* p):
    parent(p),
    modello(m){

    QVBoxLayout* controller = new QVBoxLayout(this);

    setMinimumSize(800,800);
    setWindowTitle("Chartis'Lair");
    //setWindowIcon(QPixmap(":IMMAGINI/logo.png"));

    QRect screenGeometry = QGuiApplication::screens()[0]->geometry();
    //setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), screenGeometry));
}
