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

	//Complementarios (Poner en Private despues)
	int profundidade(Nodo<T> * hijo);
	int factorEquilibrio(Nodo<T> * elegido);
	
private:
	Nodo<T> * root;
	

	//Rotaciones AVL
	Nodo<T> * rsd(Nodo<T>*n1);
	Nodo<T> * rsi(Nodo<T>*n1);
	Nodo<T> * rdd(Nodo<T>*n1);
	Nodo<T> * rdi(Nodo<T>*n1);

	//Balancear

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
#include <algorithm>
template<class T>
int Arbol<T>::profundidade(Nodo<T>* hijo)
{
	if (!hijo) return 0;
	if (!hijo->son[0] && !hijo->son[1]) return 1;
	return (1 + std::max(profundidade(hijo->son[0]), profundidade(hijo->son[1])));
}

template<class T>
int Arbol<T>::factorEquilibrio(Nodo<T>* elegido)
{
	return profundidade(elegido->son[1]) - profundidade(elegido->son[0]);
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
