#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>

class deepPtr {
private:
    T* d_Ptr;
    unsigned int riferimenti;
public:
    deepPtr(T* d_Ptr = nullptr);//costruttore
    deepPtr(const deepPtr<T>&); //costruttre di copia profondo
    ~deepPtr(); //distruttore profondo
    
	//operatori

    T* get();

    deepPtr& operator=(const deepPtr&); //assegnazione profonda
    T& operator*() const;
    T* operator->() const;
    bool operator==(const deepPtr&) const;
    bool operator!=(const deepPtr&) const;

};
//GIUSTA....FORSE, la parte sopra

//deepPtr
template <class T>
deepPtr<T>::deepPtr(T* ptr) : d_Ptr(ptr), riferimenti(ptr ? 1 : 0) {}//costruttore

template <class T>//costruttore di copia profonda
deepPtr<T>::deepPtr(const deepPtr& cptr) : d_Ptr(cptr.d_Ptr), riferimenti(cptr.riferimenti) {
    if (d_Ptr != nullptr) riferimenti++;
    else riferimenti = 0;
}

template <class T>//distruttore profondo
deepPtr<T>::~deepPtr() {
    if (riferimenti > 0) riferimenti--;
    if (riferimenti <= 0) {
        delete d_Ptr;
        d_Ptr = nullptr;
        riferimenti = 0;
    }
}
//operatori
template <class T>
deepPtr<T>& deepPtr<T>::operator=(const deepPtr& p) {
    if (this != &p) {
        if(riferimenti > 0 ) riferimenti--;
        if(riferimenti <= 0){
            delete d_Ptr;
            d_Ptr = nullptr;
            riferimenti = 0;
        }

        d_Ptr = p.d_Ptr;
        riferimenti = p.riferimenti;

        if(d_Ptr != nullptr) riferimenti++;
        else riferimenti=0;

    }
    return *this;
}

template <class T>
T* deepPtr<T>::get() {
    return d_Ptr;
}

template <class T>
T& deepPtr<T>::operator*() const {
    return *d_Ptr;
}

template <class T>
T* deepPtr<T>::operator->() const {
    return &d_Ptr;
}

template <class T>
bool deepPtr<T>::operator==(const deepPtr& p) const {
    return d_Ptr == p.d_Ptr;
}

template <class T>
bool deepPtr<T>::operator!=(const deepPtr& p) const {
    return d_Ptr != p.d_Ptr;
}

#endif // DEEPPTR_H
