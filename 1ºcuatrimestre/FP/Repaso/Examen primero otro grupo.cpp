/*Programa que lee dos secuencias de enteros para números naturales mayores que 0 y menores que 1000 desde teclado y nos dice si todos los
valores de la primera secuencia son mayores que todos los valores de la segunda secuencia.
Se realizará la lectura de los enteros dentro de sendos bucles sobre una única variable llamada "dato". El final de cada secuencia viene
marcado cuando se lee el 0.
*/

#include <iostream>

using namespace std;

int main(){
	
	int dato;			//Declaración de variable de entrada de tipo entero.
	int min, max;		//Declaración de variables de salida de tipo entero.

	min = 1000;		//Inicialización de variable.
	max = 0;			//Inicialización de variable.
	
	do{		//Éste bucle se repetirá siempre y cuando el usuario no introduzca un 0.
		
		do{		//Con éste bucle controlo que introduce un valor entre 1 y 999 para la primera secuencia.
			cout << "\n\nIntroduzca un numero entero entre 0 y 1000 para la primera secuencia: ";
			cin >> dato;
		}while(dato < 0 || dato > 1000);
		
		if(dato != 0){			//Con ésta condición compruebo que no ha metido un 0, ya que sino terminaría la introducción de datos para ésta serie.
			
			if(dato <= min)
			{						//Con éste condicional averiguo si el número introducido en cada iteración es menor que el de la vuelta anterior y lo almaceno en "min" si es menor.
			min = dato;
									//	cout << "\nMin contine: " << min;
			}
		}
	
	}while(dato != 0);
	
	cout << "\n";
	
	do{
		
		do{		//Con éste bucle controlo que introduce un valor entre 1 y 999 para la segunda secuencia.
			cout << "\n\nIntroduzca un numero entero entre 0 y 1000 para la segunda secuencia: ";
			cin >> dato;
		}while(dato < 0 || dato > 1000);
		
		if(dato != 0){			//Con ésta condición compruebo que no ha metido un 0, ya que sino terminaría la introducción de datos para ésta serie.
			if(dato >= max)
			{					//Con éste condicional averiguo si el número introducido en cada iteración es mayor que el de la vuelta anterior y lo almaceno en "max" si es mayor.
			max = dato;
							//	cout << "\nMax contine: " << max;
			}
		}
		
	}while(dato != 0);
	
	if(min > max){
		if(min == 1000 || max == 0){	//Si el usuario ha introducido un 0 en la primera iteración de cualquiera de las dos secuencias, no se podrá realizar una comparación, puesto que una o ambas series estarían vacías.
			cout << "\nNo se han introducido valores para alguna de las secuencias.";
		}else{
			cout << "\n\nTodos los números de la 1ª secuencia son mayores que todos los números de la 2ª secuencia, ";
			cout << "puesto que el mínimo de la 1ª secuencia es: " << min << ", y el máximo de la 2ª secuencia es: " << max;
		}
	}else{
		cout << "\n\nNo se cumple que todos los números de la 1ª secuencia sean mayores que todos los de la 2ª secuencia, ";
		cout << "puesto que el mínimo de la 1ª secuencia es: " << min << ", y el máximo de la 2ª secuencia es: " << max;
	}
	
	cout << "\n\n";
	system("pause");

} 
