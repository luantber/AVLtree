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
	
	a.insertar(5);
	a.insertar(10);
	a.insertar(15);
	a.insertar(4);
	a.insertar(1);
	a.insertar(6);
	a.insertar(7);
	a.insertar(8);



	cout << a.root << endl;

	a.borrar(8);
	
	cout << a.root << endl;

    return 0;
}

