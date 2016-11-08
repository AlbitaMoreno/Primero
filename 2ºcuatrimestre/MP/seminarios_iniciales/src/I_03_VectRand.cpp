#include <iostream>
#include <ctime>
using namespace std;

int main(){
	const int MY_MAX_RAND = 50;
	time_t t;
	const int TAMANIO = 1000;
	int v[TAMANIO];
	int *p = &v[0];
	int *tope = &v[TAMANIO - 1];

	//inicializo el reloj del sistema
	srand ((int) time(&t));

	while(p <= tope){
		//relleno el vector con enteros random
		*p = (rand()%((2*MY_MAX_RAND)+1)) - MY_MAX_RAND;
		cout << " " << *p;
		p++;
	}

	cout << endl;
	//vuelvo a apuntar p a la posicion v[0]
	p = &v[0];

	while(p <= tope){
		if (*p < 0){
			//le cambio el signo
			*p = -(*p);
		}
		cout << " " << *p;
		p++;
	}
	cout << endl;
}	