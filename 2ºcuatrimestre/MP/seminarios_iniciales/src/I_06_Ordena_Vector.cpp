#include <iostream>
#include <cstdlib>
using namespace std;


void Intercambia(int *p1, int *p2){
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main(){
	const int n = 20;
	int v[n];
	int *p1 = &v[0];
	int *tope1 = &v[(n-1)];
	
	int *p2 = &v[0]; // se movera mientras sea <= a *p1
	int *tope2 = &v[(n-2)]; //se movera hacia atras mientras sea  >= *tope1

	//para hacer el ejercicio relleno el vector con numeros aleatorio del 0 100
	for(p2 = &v[0] ;p2 <= tope1; p2++){
		*p2 = rand()%101;
		cout << " " << *p2;
	}
	// ordena una mitad de mayor a menor, empezando por el principio
	p2 = &v[1];
	cout << endl;
	while(p2 <= tope2){
		if(*p2 <= *p1){
			p2++;
			p1++;
		}
		else{
			//si intercambio dos posiciones ==> vuelvo a inicializar el vector
			Intercambia(p1,p2);
			p1 = &v[0];
			p2 = &v[1];
		}
		
		if(*tope2 > *tope1){
			tope2--;
			tope1--;
		}
		else{
			Intercambia(tope1,tope2);
			tope1 = &v[(n-1)];
			tope2 = &v[(n-2)];
		}
	}
	tope1 = &v[(n-1)];

	for(p2 = &v[0] ;p2 <= tope1; p2++){
		cout << " " << *p2;
	}
	cout << endl;
}