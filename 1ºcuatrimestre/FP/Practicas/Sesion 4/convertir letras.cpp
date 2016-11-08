/*Queremos modificar el ejercicio "comprobacion mayusculas" para leer un carácter letra_original 
desde teclado y hacer lo siguiente:
- Si es una letra mayúscula, almacenaremos en la variable letra_convertida
la correspondiente letra minúscula.
- Si es una letra minúscula, almacenaremos en la variable letra_convertida
la correspondiente letra mayúscula.
- Si es un carácter no alfabético, almacenaremos el mismo carácter en la variable
letra_convertida*/

#include <iostream>

using namespace std;

int main(){
	char letra_convertida, letra_original;
	bool es_mayus, es_minus;						//Variable lógica para mayúsculas y minusculas para el condicional IF
	const int distancia_may_min = 'a'-'A';
	
	cout << "\nIntroduzca letra: ";
	cin >> letra_original;
		
	if((letra_original >= 'A') && (letra_original <= 'Z')){
		es_mayus = true;														//El programa funcionaría más rapido y de forma más eficaz si obviamos las lineas
	}																				//24 y 26-31.
		
	if(es_mayus){
		letra_convertida = letra_original + distancia_may_min;
		
		cout << "\nLa letra es: " << letra_convertida << "\n\n";
	}
	if((letra_original >= 'a') && (letra_original <= 'z')){
		letra_convertida = letra_original - distancia_may_min;		//Para el paso de minúscula a mayúscula se resta la constante
		
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
		
