#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>

class deepPtr {
public:
    class nodo;

    nodo* punt;
    deepPtr(nodo* p = 0); //costruttore
    deepPtr(const deepPtr&); //costruttre di copia profondo
    ~deepPtr(); //distruttore profondo
    //operatori
    deepPtr& operator=(const deepPtr&); //assegnazione profonda
    nodo& operator*() const;
    nodo* operator->() const;
    bool operator==(const deepPtr&) const;
    bool operator!=(const deepPtr&) const;


class nodo {
public:
    T info;
    deepPtr prev;
    deepPtr next;
    unsigned int riferimenti;
    nodo();
    nodo(const T&, const deepPtr&, const deepPtr&);
};

};

//deepPtr

template <class T>
typename deepPtr<T>::deepPtr& deepPtr<T>::deepPtr::operator=(const deepPtr& p) {
    if (this != &p) {
        nodo* t = punt;
        punt = p.punt;
        if(punt) punt->riferimenti++;
        if(t) {
            t->riferimenti--;
            if(t->riferimenti == 0) delete t;
        }
    }
    return  *this;
}

template <class T>
deepPtr<T>::deepPtr(nodo* p): punt(p) {
    if(punt) punt->riferimenti++;
}

template <class T>
deepPtr<T>::deepPtr(const deepPtr& c): punt(c.punt) {
    if(punt) punt->riferimenti++;
}

template <class T>
deepPtr<T>::~deepPtr() {
    if(punt) {
        punt->riferimenti--;
        if (punt->riferimenti == 0) delete punt;
    }
}

template <class T>
typename deepPtr<T>::nodo& deepPtr<T>::deepPtr::operator*() const {
    return *punt;
}

template <class T>
typename deepPtr<T>::nodo* deepPtr<T>::deepPtr::operator->() const {
    return punt;
}

template <class T>
bool deepPtr<T>::operator==(const deepPtr& p) const {
    return punt == p.punt;
}

template <class T>
bool deepPtr<T>::operator!=(const deepPtr& p) const {
    return punt != p.punt;
}

//NODO

template <class T>
deepPtr<T>::nodo::nodo(): riferimenti(0) {}

template <class T>
deepPtr<T>::nodo::nodo(const T& i, const deepPtr& p, const deepPtr& n): info(i), prev(p), next(n), riferimenti(0) {}

#endif // DEEPPTR_H
