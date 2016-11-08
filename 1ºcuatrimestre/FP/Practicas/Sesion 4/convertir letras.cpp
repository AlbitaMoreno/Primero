/*Queremos modificar el ejercicio "comprobacion mayusculas" para leer un car�cter letra_original 
desde teclado y hacer lo siguiente:
- Si es una letra may�scula, almacenaremos en la variable letra_convertida
la correspondiente letra min�scula.
- Si es una letra min�scula, almacenaremos en la variable letra_convertida
la correspondiente letra may�scula.
- Si es un car�cter no alfab�tico, almacenaremos el mismo car�cter en la variable
letra_convertida*/

#include <iostream>

using namespace std;

int main(){
	char letra_convertida, letra_original;
	bool es_mayus, es_minus;						//Variable l�gica para may�sculas y minusculas para el condicional IF
	const int distancia_may_min = 'a'-'A';
	
	cout << "\nIntroduzca letra: ";
	cin >> letra_original;
		
	if((letra_original >= 'A') && (letra_original <= 'Z')){
		es_mayus = true;														//El programa funcionar�a m�s rapido y de forma m�s eficaz si obviamos las lineas
	}																				//24 y 26-31.
		
	if(es_mayus){
		letra_convertida = letra_original + distancia_may_min;
		
		cout << "\nLa letra es: " << letra_convertida << "\n\n";
	}
	if((letra_original >= 'a') && (letra_original <= 'z')){
		letra_convertida = letra_original - distancia_may_min;		//Para el paso de min�scula a may�scula se resta la constante
		
		cout << "\n\tLa letra es: " << letra_convertida << "\n\n";
	}
	
	if((es_mayus == false) && (es_minus == false)){
		
		es_minus = true;
	}
	if(es_minus){
		cout << "\nNo ha introducido ninguna letra: " << letra_original << "\n\n";	
																				//si es_mayus es false y es_minus es false entonces se cumple el if.
	}																			// && obliga a que se cumplan ambas condiciones
}
		
