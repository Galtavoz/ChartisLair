#include"popup.h"

popup::popup(QString n,QString t):
    nomeFinestra(n),
    testo(t)
{
    this->setWindowTitle(nomeFinestra);
    this->setText(testo);
    if(n == "Informazione") {
        setIcon(QMessageBox::Information);
        setWindowIcon(QIcon(":/IMMAGINI/question.png"));
    } else if(n== "Warning") {
        setIcon(QMessageBox::Warning);
        setWindowIcon(QIcon(":/IMMAGINI/exclamation.png"));
    } else {
        setIcon(QMessageBox::Critical);
        setWindowIcon(QIcon(":/IMMAGINI/skull.jpg"));
    }
}
