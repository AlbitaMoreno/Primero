/*EXAMEN 2010 2011 SEPTIEMBRE*/

//LEE UNA SECUENCIA DE NUMEROS DE RANGO 0 A 100
//subsecuencia mas larga 

#include<iostream>
using namespace std;

int main(){
	int tamanio = 100;
	int vector_sec[tamanio];
	int i, numero;
	int utilizados = 0;
	int longitud1 = 0;
	int longitud2 = 0;
	int minimo1, posicion1;
	int minimo2, posicion2;
	
	do{
		cout << "\nIntroduzca un numero en la posicion " << utilizados << " : ";
		cin >> numero;
		if(utilizados < tamanio && numero < 100 & numero > 0){
			vector_sec[utilizados] = numero;
			utilizados++;
		}
	}while(numero < 100 && numero > 0);
	
	cout << "\nLA SECUENCIA INTRODUCIDA ES: ";
	for(i = 0; i < utilizados; i++){
		cout << " " << vector_sec[i];
	}
	
	//SALIDA POSICION DE INICIO Y LONGITUD 
	
	for(i = 0; i < utilizados - 1; i++){
		if(i == 1){
			minimo1 = vector_sec[0];
			posicion1 = i;
		}
		
		if(vector_sec[i] > minimo1){
			longitud1++;
		}
		else{
			minimo2 = vector_sec[i];
			posicion2 = i;
			longitud2 = 1;
		}
		if(vector_sec[i] > minimo2){
			longitud2++;
		}
		else{
			if(longitud1 > longitud2){
				minimo2 = vector_sec[i];
				posicion2 = i;
			}
			else{
				minimo1 = vector_sec[i];
				posicion1 = i;
			}
		}
	}
	
	if(longitud1 > longitud2){
		cout << "\nPOSICION: " << posicion1;
		cout << "\nLONGITUD: " << longitud1;
	}
	else{
		cout << "\nPOSICION: " << posicion2;
		cout << "\nLONGITUD: " << longitud2;
	}
}
