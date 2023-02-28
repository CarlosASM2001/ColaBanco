#ifndef COLAS_DINAMICAS_H
#define COLAS_DINAMICAS_H
#include <iostream>
using namespace std;

template<class T> class Colas_dinamicas;


template<class T>
class nodo {
private:
	T valor;
	nodo<T>* siguiente;
public:
	nodo(T v, nodo<T>* sig = NULL) {
		valor = v;
		siguiente = sig;
	}
	void setValor(T val) { valor = val; }
	void setSiguiente(nodo<T>* p) { siguiente = p; }
	nodo<T>* getSiguiente() { return siguiente; }
	T getValor() { return valor; }
	friend class Colas_dinamicas<T>;
};

template<class T>
class Colas_dinamicas {
private:
	nodo<T>* primero, * ultimo;
	int numNodos;
public:
	Colas_dinamicas() : primero(NULL), ultimo(NULL), numNodos(0) {}
	~Colas_dinamicas();
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
void Colas_dinamicas<T>::invert()
{
	nodo<T>* prev = NULL;
	nodo<T>* next = NULL;
	nodo<T>* temp = primero;
	while (temp) {
		next = temp->getSiguiente();
		temp->setSiguiente(prev);
		prev = temp;
		temp = next;
	}
	primero = prev;
}

template<class T>
bool Colas_dinamicas<T>::isVacia()
{
	nodo<T>* p = primero;
	if (!p) {
		return true;
	}
	return false;
}

template<class T>
void Colas_dinamicas<T>::Imprimir()
{
	nodo<T>* p = primero;
	while (p) {
		cout << p->getValor() << endl;
		p = p->getSiguiente();
	}
}

template<class T>
Colas_dinamicas<T>::~Colas_dinamicas()
{
	while (primero)
		Eliminar();
	numNodos = 0;
}

template<class T>
void Colas_dinamicas<T>::Vaciar() {
	while (primero)
		Eliminar();
	numNodos = 0;
}
template<class T>
void Colas_dinamicas<T>::Anadir(T v)
{
	nodo<T>* nuevo;
	nuevo = new nodo<T>(v);
	if (ultimo) ultimo->siguiente = nuevo;
	ultimo = nuevo;
	if (!primero) primero = nuevo;
	numNodos++;
}

template<typename T>
void Colas_dinamicas<T>::AnadirInicio(T data_)
{
	nodo<T>* new_nodo = new nodo<T>(data_);
	nodo<T>* temp = primero;

	if (!primero) {
		primero = new_nodo;
	}
	else {
		new_nodo->getSiguiente() = primero;
		primero = new_nodo;
		while (temp) {
			temp = temp->getSiguiente();
		}
	}
	numNodos++;
}

template<typename T>
void Colas_dinamicas<T>::AnadirFinal(T data_)
{
	nodo<T>* new_nodo = new nodo<T>(data_);
	nodo<T>* temp = primero;

	if (!primero) {
		primero = new_nodo;
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
T Colas_dinamicas<T>::Eliminar()
{
	nodo<T>* Nodo;
	T v=NULL;
	Nodo = primero;
	if (!Nodo) return v;
	primero = Nodo->siguiente;
	v = Nodo->valor;
	delete Nodo;
	numNodos--;
	if (!primero) ultimo = NULL;
	return v;

}

template<class T>
T Colas_dinamicas<T>::Leer()
{
	nodo<T>* Nodo;
	T v=NULL;
	Nodo = primero;
	if (!Nodo) return v;
	v = Nodo->valor;
	return v;
}

template<class T>
int Colas_dinamicas<T>::Buscar(T& E) {

	nodo<T>* p = primero;
	while (p) {
		if (p->getValor() == E) {
			E = p->getValor();
			return 1;
		}
		else {
			p = p->getSiguiente();
		}
	}
	return 0;
}
#endif
