/*Programa que lee dos secuencias de enteros para n�meros naturales mayores que 0 y menores que 1000 desde teclado y nos dice si todos los
valores de la primera secuencia son mayores que todos los valores de la segunda secuencia.
Se realizar� la lectura de los enteros dentro de sendos bucles sobre una �nica variable llamada "dato". El final de cada secuencia viene
marcado cuando se lee el 0.
*/

#include <iostream>

using namespace std;

int main(){
	
	int dato;			//Declaraci�n de variable de entrada de tipo entero.
	int min, max;		//Declaraci�n de variables de salida de tipo entero.

	min = 1000;		//Inicializaci�n de variable.
	max = 0;			//Inicializaci�n de variable.
	
	do{		//�ste bucle se repetir� siempre y cuando el usuario no introduzca un 0.
		
		do{		//Con �ste bucle controlo que introduce un valor entre 1 y 999 para la primera secuencia.
			cout << "\n\nIntroduzca un numero entero entre 0 y 1000 para la primera secuencia: ";
			cin >> dato;
		}while(dato < 0 || dato > 1000);
		
		if(dato != 0){			//Con �sta condici�n compruebo que no ha metido un 0, ya que sino terminar�a la introducci�n de datos para �sta serie.
			
			if(dato <= min)
			{						//Con �ste condicional averiguo si el n�mero introducido en cada iteraci�n es menor que el de la vuelta anterior y lo almaceno en "min" si es menor.
			min = dato;
									//	cout << "\nMin contine: " << min;
			}
		}
	
	}while(dato != 0);
	
	cout << "\n";
	
	do{
		
		do{		//Con �ste bucle controlo que introduce un valor entre 1 y 999 para la segunda secuencia.
			cout << "\n\nIntroduzca un numero entero entre 0 y 1000 para la segunda secuencia: ";
			cin >> dato;
		}while(dato < 0 || dato > 1000);
		
		if(dato != 0){			//Con �sta condici�n compruebo que no ha metido un 0, ya que sino terminar�a la introducci�n de datos para �sta serie.
			if(dato >= max)
			{					//Con �ste condicional averiguo si el n�mero introducido en cada iteraci�n es mayor que el de la vuelta anterior y lo almaceno en "max" si es mayor.
			max = dato;
							//	cout << "\nMax contine: " << max;
			}
		}
		
	}while(dato != 0);
	
	if(min > max){
		if(min == 1000 || max == 0){	//Si el usuario ha introducido un 0 en la primera iteraci�n de cualquiera de las dos secuencias, no se podr� realizar una comparaci�n, puesto que una o ambas series estar�an vac�as.
			cout << "\nNo se han introducido valores para alguna de las secuencias.";
		}else{
			cout << "\n\nTodos los n�meros de la 1� secuencia son mayores que todos los n�meros de la 2� secuencia, ";
			cout << "puesto que el m�nimo de la 1� secuencia es: " << min << ", y el m�ximo de la 2� secuencia es: " << max;
		}
	}else{
		cout << "\n\nNo se cumple que todos los n�meros de la 1� secuencia sean mayores que todos los de la 2� secuencia, ";
		cout << "puesto que el m�nimo de la 1� secuencia es: " << min << ", y el m�ximo de la 2� secuencia es: " << max;
	}
	
	cout << "\n\n";
	system("pause");

} 
