//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Demo-Lista.cpp
// 
//
/***************************************************************************/

#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	int nodos;
	TipoBase valor;	
	
	do{
		cout << "Crear Lista con un numero de nodos determinados, todos a 0: ";
		cin >> nodos;
	}while(nodos <= 0);
	
	cout << endl << endl;
	
	MiLista l(nodos);
	l = 1;
	MiLista l2(nodos);
	l2 = 3;
	
	cout << "l1 = 1-> ";
	for(int i = 0; i < l.GetNumNodos(); i++)
		cerr << " " << l[i];
	cout << endl;
	
	cout << "l2 = 3-> ";
	for(int i = 0; i < l2.GetNumNodos(); i++)
		cerr << " " << l2[i];
		
	cout << endl;
	cout << "Inserto un 1 con el operador +=" << endl;
	l2 += 1;
	
	for(int i = 0; i < l2.GetNumNodos(); i++)
		cerr << " " << l2[i];
	cout << endl;
	
	cout << "Borrar un 3 con el operador -=" << endl;
	l2 -= 3;

	for(int i = 0; i < l2.GetNumNodos(); i++)
		cerr << " " << l2[i];
	cout << endl << endl;
	
	MiLista res,res1,res2,res3;
	
	res = l + l2;
	cout << "res = l + l2 -> ";
	for(int i = 0; i < res.GetNumNodos(); i++)
		cerr << " " << res[i];
	cout << endl;
	
	if(res == l)
		cout << "Son iguales" << endl;
	else{
		if(res >= l)
			cout << "res >= l" << endl;
		else{
			if(res <= l)
				cout << "res <= l" << endl;
		}
	}
	cout << endl << endl;
	
	res1 = l - l2;
	cout << "res1 = l - l2 -> ";
	
	for(int i = 0; i < res1.GetNumNodos(); i++)
		cerr << " " << res1[i];
	cout << endl;
	
	res2 = l + 2;
	cout << "res2 = l + 2 -> ";
	
	for(int i = 0; i < res2.GetNumNodos(); i++)
		cerr << " " << res2[i];
	cout << endl;
	
	cout << "res3 = 2 + l2-> ";
	res3 = 2 + l2;

	for(int i = 0; i < res3.GetNumNodos(); i++)
		cerr << " " << res3[i];	

	cout << endl;
	return 0;	
}
