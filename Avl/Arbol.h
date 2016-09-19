#pragma once
#include "Nodo.h"

template <class T>
class Arbol
{
public:
	Arbol() {
		root = 0;

	};

	//Funciones Básicas
	bool find(T d,Nodo<T> ** & p);
	bool insertar(T d);

	//Rotaciones AVL
	Nodo<T> * rsd(Nodo<T>*n1);
	Nodo<T> * rsi(Nodo<T>*n1);
	Nodo<T> * rdd(Nodo<T>*n1);
	Nodo<T> * rdi(Nodo<T>*n1);

	//Destructor;
	

private:
	Nodo<T> * root;

};

template<class T>
bool Arbol<T>::find(T d, Nodo<T>**& p)
{
	p = &root;
	while (*p)
	{
		if ((*p)->dato == d) return true;
		p = &((*p)->son[((*p)->dato < d)]);
	}
	return false;
}

template<class T>
bool Arbol<T>::insertar(T d)
{
	Nodo<T> ** q;
	if (find(d, q)) return false;
	* q = new Nodo<T>(d);
	return true;
}

template<class T>
Nodo<T>* Arbol<T>::rsd(Nodo<T>* n1)
{
	Nodo<T> *n2 = n1->son[0];
	n1->son[0] = n2->son[1];
	n2->son[1] = n1;
	return n2;
}

template<class T>
Nodo<T>* Arbol<T>::rsi(Nodo<T>* n1)
{
	
		Nodo<T> *n2 = n1->son[1];
		n1->son[1] = n2->son[0];
		n2->son[0] = n1;
		return n2;
	
}

template<class T>
Nodo<T>* Arbol<T>::rdd(Nodo<T>* n1)
{
	Nodo<T> * n2 = n1->son[0] = rsi(n1->son[0]);
	rsd(n1);
	return n2;
}

template<class T>
Nodo<T>* Arbol<T>::rdi(Nodo<T>* n1)
{
	Nodo<T> * n2 = n1->son[1] = rsd(n1->son[1]);
	rsi(n1);
	return n2;
}
