// Avl.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Arbol.h"
#include "Nodo.h"

#include <iostream>
using namespace std;
int main()
{
	Arbol<int> a;
	Nodo<int> ** q ;
	std::cout << a.insertar(5)<<std::endl;
	std::cout << a.insertar(4) << std::endl;
	std::cout << a.insertar(3) << std::endl;
	std::cout << a.insertar(2) << std::endl;

	cout << "here "<<a.find(5, q)<<endl;
	cout << a.factorEquilibrio(*q) << endl;


	//cout << a.

    return 0;
}

