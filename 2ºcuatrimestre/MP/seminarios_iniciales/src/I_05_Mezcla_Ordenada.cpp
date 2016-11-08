#include <iostream>
using namespace std;

void Intercambia(float *pos1, float *pos2){
	float tmp;
	tmp = *pos1;
	*pos1 = *pos2;
	*pos2 = tmp;
}

int main(){
	const int MAX = 100;
	float v1 [MAX] = {2,3,8,22,44,88,99,100,101,255,665};
	float v2 [MAX] = {1,3,4,5,6,25,87,89,99,100,500,1000};
	float res [2*MAX];

	int tam_v1 = 11;
	int tam_v2 = 12;
	int tam_res = tam_v1 + tam_v2;

	float *p1 = &v1[0];
	float *p2 = &v2[0];
	float *pres = &res[0];
	float const *tope2 = &v2[11];
	float const *topres = &res[23];

	for( ;p2 <= tope2; p1++, p2++, pres++){
	
	//introducir el ultimo numero
		if (p2 == tope2)
			*pres = *p2;
		
		if(*p1 < *p2){
			*pres = *p1;
			pres++;
			*pres = *p2;
		}
		
		else{
			*pres = *p2;
			pres++;
			*pres = *p1;
		}
	}
	cout << endl;
	//res desordenado
	for(pres = &res[0]; pres <= topres; pres++){
		cout << " " << *pres;
	}
	cout << endl;
	//como los valores se han introducido ordenados dos a dos ahora los ordeno comparandolos dos a dos
	pres = &res[2];
	float *aux = &res[1];

	for( ; pres <topres; pres++, aux++){
		if(*pres < *aux)
			Intercambia(pres,aux);
	}

	for(pres = &res[0]; pres <= topres; pres++){
		cout << " " << *pres;
	}

	cout << endl;
}