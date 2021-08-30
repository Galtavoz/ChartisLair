#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>
class deepPtr {
private:
    T* d_Ptr;
public:
    deepPtr(T* = nullptr);//costruttore
    deepPtr(const deepPtr<T>&); //costruttre di copia profondo
    deepPtr& operator=(const deepPtr&); //assegnazione profonda
    ~deepPtr(); //distruttore

    //operatori
//    T* get();
    T& operator*();
    T* operator->() const; /*const??*/
    const T& operator*() const;
//    const T* operator->() const;/*senza const davanti??*/
    bool operator==(const deepPtr&) const;
    bool operator!=(const deepPtr&) const;
    operator T*() const;

};
//GIUSTA....FORSE, la parte sopra

//deepPtr
template <class T>
deepPtr<T>::deepPtr(T* ptr) : d_Ptr(ptr) {}//costruttore

template <class T>//costruttore di copia profonda
deepPtr<T>::deepPtr(const deepPtr& dptr){
//    if (d_Ptr != nullptr) {
//        new deepPtr(d_Ptr);
//        *d_Ptr = *cptr.d_Ptr;
//    }
//    else new deepPtr(nullptr);
    if(dptr) d_Ptr=dptr.d_Ptr->clone();
    else d_Ptr=nullptr;
}

template <class T>//distruttore profondo
deepPtr<T>::~deepPtr() {
//    if (riferimenti > 0) riferimenti--;
//    if (riferimenti <= 0) {
//        delete d_Ptr;
//        d_Ptr = nullptr;
//        riferimenti = 0;
//    }
//    if(d_Ptr!=nullptr) {
//        delete d_Ptr;
//        d_Ptr=nullptr;
//    }
    if(d_Ptr) delete d_Ptr;
}
//operatori
template <class T>
deepPtr<T>& deepPtr<T>::operator=(const deepPtr& dptr) {
   if (this != &dptr) {
//        if(riferimenti > 0 ) riferimenti--;
//        if(riferimenti <= 0){
//            delete d_Ptr;
//            d_Ptr = nullptr;
//            riferimenti = 0;
//        }

//        d_Ptr = p.d_Ptr;
//        riferimenti = p.riferimenti;

//        if(d_Ptr != nullptr) riferimenti++;
//        else riferimenti=0;
//        if(d_Ptr!=nullptr) {
//            delete d_Ptr;
//            d_Ptr=nullptr;
//        }
//        d_Ptr = p.d_Ptr;
    if(d_Ptr) delete d_Ptr;
    d_Ptr = dptr.d_Ptr->clone();
    }
    return *this;
}

//template <class T>
//T* deepPtr<T>::get() {
//    return d_Ptr;
//}

template <class T>
T& deepPtr<T>::operator*() {
    return *d_Ptr;
}

template <class T>
T* deepPtr<T>::operator->() const{
    return &d_Ptr;
}
template <class T>
const T& deepPtr<T>::operator*() const {
    return *d_Ptr;
}

//template <class T>
//const T* deepPtr<T>::operator->() const {
//    return d_Ptr;
//}

template <class T>
bool deepPtr<T>::operator==(const deepPtr& dptr) const {
//    return d_Ptr == p.d_Ptr;
    return *d_Ptr==*(dptr.d_Ptr);
}

template <class T>
bool deepPtr<T>::operator!=(const deepPtr& dptr) const {
//    return d_Ptr != p.d_Ptr;
      return *d_Ptr != *(dptr.d_Ptr);
}
template<class T>
deepPtr<T>::operator T *() const{
    return d_Ptr;
}
#endif // DEEPPTR_H
