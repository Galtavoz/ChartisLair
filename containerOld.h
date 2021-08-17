#ifndef CONTAINER_H
#define CONTAINER_H

#include<iostream>
#include<QDebug>
#include "DeepPtr.h"

template<class T>

class lista {
private:
    deepPtr<T> primo;
    deepPtr<T> ultimo;
public:
    class iteratore {
    private:
        deepPtr<T>* it;
        bool fine;
    public:
        iteratore();
        iteratore(deepPtr<T>* = nullptr, bool = false);
        iteratore(const iteratore&);
        iteratore& operator++();
        iteratore& operator--();
        T operator*() const;
        T operator->() const;
        bool operator==(const iteratore&) const;
        bool operator!=(const iteratore&) const;
    };

    class iteratoreConst {
    private:
        const deepPtr<T>* constIt;
        bool fineConst;
    public:
        iteratoreConst();
        iteratoreConst(const deepPtr<T>* = nullptr, bool = false);
        iteratoreConst(const iteratoreConst&);
        iteratoreConst& operator++();
        iteratoreConst& operator--();
        bool operator==(const iteratoreConst&) const;
        bool operator!=(const iteratoreConst&) const;
        const T& operator*() const;
        const T* operator->() const;
    };

    void aggiungiTesta(const T&);
    void aggiungiCoda(const T&);
    bool vuoto();
    void togliUno(const T&); //da fare

    iteratore inizio();
    iteratore fine();
    iteratoreConst inizioC() const;
    iteratoreConst fineC() const;
};

//LISTA

template<class T>
void lista<T>::aggiungiTesta(const T& n) {
    if(primo == nullptr){
        primo = new typename deepPtr<T>::nodo(n,nullptr,nullptr);
        ultimo = primo;
    } else {
        typename deepPtr<T>::nodo* aux = new typename deepPtr<T>::nodo(n,nullptr,primo);
        primo = aux;
    }
}

template<class T>
void lista<T>::aggiungiCoda(const T& n) {
    if(primo == nullptr){
        primo = new typename deepPtr<T>::nodo(n,nullptr,nullptr);
        ultimo = primo;
    } else {
        typename deepPtr<T>::nodo* aux = new typename deepPtr<T>::nodo(n,ultimo,nullptr);
        ultimo->next = aux;
        ultimo = aux;
    }
}

template<class T>
bool lista<T>::vuoto() {
    if(primo == nullptr) return true;
    else return false;
}

template<class T>
void lista<T>::togliUno(const T& t) {

    deepPtr<T> p = primo;
       deepPtr<T> prec = nullptr;
       while(p != nullptr && !(p->info == t)) {

           prec = p;
           p = p->next;
       }
       if(p != nullptr) {
           if (prec == nullptr && p->next == nullptr) {
               primo = p->next;
               ultimo = primo;
           } else {
           if(prec == nullptr) {
               primo = p->next;
               primo->prev = nullptr;
           } else {
               if(p->next != nullptr) {
                   prec->next = p->next;
                   (p->next)->prev = prec;
               } else {
                   prec->next = p->next;
                   ultimo = prec;
                   }
               }
           }
       }
}

//ITERATORE

template<class T>
lista<T>::iteratore::iteratore(): it(nullptr), fine(false) {}

template<class T>
lista<T>::iteratore::iteratore(deepPtr<T>* iter,bool pastTheEnd): it(iter), fine(pastTheEnd) {}

template<class T>
lista<T>::iteratore::iteratore(const iteratore& iter): it(iter.it), fine(iter.fine) {}

template<class T>
typename lista<T>::iteratore lista<T>::inizio() {
    if(primo == nullptr) return iteratore(nullptr);
    else return iteratore(&primo);
}

template<class T>
typename lista<T>::iteratore lista<T>::fine() {
    if(ultimo == nullptr) return iteratore(nullptr);
    else return iteratore(&(ultimo->next),true);
}

template<class T>
bool lista<T>::iteratore::operator==(const iteratore& i) const{
    return it = i.it;
}

template<class T>
bool lista<T>::iteratore::operator!=(const iteratore& i) const {
    return it != i.it;
}

template<class T>
T lista<T>::iteratore::operator*() const{
    return (*(*it)).info;
}

template<class T>
T lista<T>::iteratore::operator->() const{
    return &(*(*(*it)).info);
}

template<class T>
typename lista<T>::iteratore& lista<T>::iteratore::operator++() {
    if(!fine && it != nullptr) {
        if((*it)->next == nullptr) {
            it = &((*it)->next);
            fine = true;
        } else {
            it = &((*it)->next);
        }
    }
    return *this;
}

template<class T>
typename lista<T>::iteratore& lista<T>::iteratore::operator--() {
    if(fine) {
        it = &(*(it)->prev);
        fine = false;
    } else {
        if(fine) &(*(it)->next);
    }
    return *this;
}

//ITERATORE CONST

template<class T>
lista<T>::iteratoreConst::iteratoreConst(): constIt(nullptr), fineConst(false) {}

template <class T>
lista<T>::iteratoreConst::iteratoreConst(const deepPtr<T>* p, bool f): constIt(p), fineConst(f) {}

template <class T>
lista<T>::iteratoreConst::iteratoreConst(const iteratoreConst& ic): constIt(ic.constIt), fineConst(ic.fineConst) {}

template <class T>
typename lista<T>::iteratoreConst lista<T>::inizioC() const {
    if(primo==nullptr) return iteratoreConst(nullptr);
    return iteratoreConst(&(primo));
}

template <class T>
typename lista<T>::iteratoreConst lista<T>::fineC() const {
    if(primo==nullptr) return iteratoreConst(nullptr);
    return iteratoreConst(&(ultimo->next),true);
}

template <class T>
typename lista<T>::iteratoreConst& lista<T>::iteratoreConst::operator++() {
    if(!fineConst && constIt!=nullptr) {
        if((*constIt)->next == nullptr) {
            constIt = &((*constIt)->next);
            fineConst = true;
        } else {
            constIt = &((*constIt)->next);
        }
    }
    return *this;
}

template <class T>
typename lista<T>::iteratoreConst& lista<T>::iteratoreConst::operator--() {
    if(fineConst) {
        constIt = &(*(constIt)->prev);
        fineConst = false;
    } else {
        if(fineConst) &(*(constIt)->next);
    }
    return *this;
}

template <class T>
bool lista<T>::iteratoreConst::operator==(const iteratoreConst& c) const {
    return constIt==c.constIt;
}

template <class T>
bool lista<T>::iteratoreConst::operator!=(const iteratoreConst& c) const {
    return constIt!=c.constIt;
}

template <class T>
const T& lista<T>::iteratoreConst::operator*() const {
    return ((*constIt)->info);
}

template <class T>
const T* lista<T>::iteratoreConst::operator->() const {
    return &((*constIt)->info);
}

#endif // CONTAINER_H
