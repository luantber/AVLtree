#pragma once

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

