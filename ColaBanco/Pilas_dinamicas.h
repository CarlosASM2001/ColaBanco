#ifndef PILAS_DINAMICAS_H
#define PILAS_DINAMICAS_H
#include <iostream>
using namespace std;

template<class T> class Pilas_dinamicas;


template<class T>
class NodoP {
private:
    T valor;
    NodoP<T>* siguiente;
public:
    NodoP(T v, NodoP<T>* sig = NULL) : valor(v), siguiente(sig) {}

    void setValor(T val) { valor = val; }
    void setSiguiente(NodoP<T>* p) { siguiente = p; }
    T getValor() { return valor; }
    NodoP<T>* getSiguiente() { return siguiente; }
    friend class Pilas_dinamicas<T>;
};

template<class T>
class Pilas_dinamicas {
private:
    NodoP<T>* ultimo;
    int numNodos;
public:
    Pilas_dinamicas() { ultimo = NULL; numNodos = 0; }
    ~Pilas_dinamicas();
    bool isVacia();
    void AnadirInicio(T);
    void AnadirFinal(T);
    void Anadir(T v);
    T Eliminar();
    T Leer();
    void Vaciar();
    int Buscar(T& E);
    void Imprimir();
    void invert();

};


template<typename T>
void Pilas_dinamicas<T>::invert()
{
    NodoP<T>* prev = NULL;
    NodoP<T>* next = NULL;
    NodoP<T>* temp = ultimo;

    while (temp) {
        next = temp->getSiguiente();
        temp->setSiguiente(prev);
        prev = temp;
        temp = next;
    }
    ultimo = prev;
}

template<class T>
bool Pilas_dinamicas<T>::isVacia()
{
    NodoP<T>* p = ultimo;
    if (!p) {
        return true;
    }
    return false;
}

template<class T>
Pilas_dinamicas<T>::~Pilas_dinamicas()
{
    while (ultimo) Eliminar();
    numNodos = 0;
}

template<class T>
void Pilas_dinamicas<T>::Vaciar() {
    while (ultimo) Eliminar();
    numNodos = 0;
}
template<class T>
void Pilas_dinamicas<T>::Anadir(T v)
{
    NodoP<T>* nuevo;
    nuevo = new NodoP<T>(v, ultimo);
    ultimo = nuevo;
    numNodos++;
}

template<typename T>
void Pilas_dinamicas<T>::AnadirFinal(T data_)
{
    NodoP<T>* new_nodo = new NodoP<T>(data_);
    NodoP<T>* temp = ultimo;

    if (!ultimo) {
        ultimo = new_nodo;
    }
    else {
        new_nodo->setSiguiente(ultimo);
        ultimo = new_nodo;
        while (temp) {
            temp = temp->getSiguiente();
        }
    }
    numNodos++;
}

template<typename T>
void Pilas_dinamicas<T>::AnadirInicio(T data_)
{
    NodoP<T>* new_nodo = new NodoP<T>(data_);
    NodoP<T>* temp = ultimo;

    if (!ultimo) {
        ultimo = new_nodo;
    }
    else {
        while (temp->getSiguiente() != NULL) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(new_nodo);
    }
    numNodos++;
}

template<class T>
T Pilas_dinamicas<T>::Eliminar()
{
    NodoP<T>* _Nodo;
    T v=NULL;
    if (!ultimo) return v;
    _Nodo = ultimo;
    ultimo = _Nodo->siguiente;
    v = _Nodo->valor;
    delete _Nodo;
    numNodos--;
    return v;
}

template<class T>
T Pilas_dinamicas<T>::Leer() {

    NodoP<T>* _Nodo;
    T v;
    if (!ultimo) return v;
    _Nodo = ultimo;
    v = _Nodo->valor;
    return v;
}

template<class T>
int Pilas_dinamicas<T>::Buscar(T& E) {
    NodoP<T>* _Nodo = ultimo;
    while (_Nodo) {
        if (_Nodo->getValor() == E) {
            E = _Nodo->getValor();
            return 1;
        }
        else {
            _Nodo = _Nodo->getSiguiente();
        }
    }
    return 0;

}

template <class T>
void Pilas_dinamicas<T>::Imprimir() {
    NodoP<T>* p = ultimo;
    while (p) {
        cout << p->getValor() << " ";
        p = p->getSiguiente();
    }
}
#endif

