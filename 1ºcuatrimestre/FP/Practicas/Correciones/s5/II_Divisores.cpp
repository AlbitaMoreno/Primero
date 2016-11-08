////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/* 
	Calcular los divisores de un n�mero entero positivo >0 
	Somos conscientes de que mezclamos C/S pero por ahora 
	no tenemos herramientas	(ser�n los vectores) para separarlos
*/


#include <iostream> 
using namespace std;  
   
int main(){    
	int entero, ultimo_divisor_posible, divisor;

	do{
		cout << "Introduce un numero entero positivo mayor que 0: ";
		cin >> entero;
	}while (entero <= 0);

	divisor = 2;
   ultimo_divisor_posible = entero/2;

	while (divisor <= ultimo_divisor_posible){    
		if (entero % divisor == 0)
			cout << divisor << " es un divisor de " << entero << endl;
		
		divisor++;
	}

	cout << "\n\n";
	system("pause");
}