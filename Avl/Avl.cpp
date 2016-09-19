// Avl.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Arbol.h"
#include "Nodo.h"

#include <iostream>
int main()
{
	Arbol<int> a;
	Nodo<int> ** q ;
	std::cout << a.insertar(5)<<std::endl;
	std::cout << a.insertar(4) << std::endl;
	std::cout << a.insertar(3) << std::endl;
    return 0;
}

