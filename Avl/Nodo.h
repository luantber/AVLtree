#pragma once

#include <iostream>
using namespace std;

template <class T>
class Nodo
{

public:

	Nodo(T d) { dato = d; };
	Nodo<T> * son[2] = { 0, 0 };

	//Destructor
	

	T dato;
private:
};

