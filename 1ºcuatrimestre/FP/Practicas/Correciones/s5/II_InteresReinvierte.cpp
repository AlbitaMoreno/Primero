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
   Calcular el total acumulado de un capital y los intereses correspondientes
   en varios a�os sucesivos
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado;
   int anios_transcurridos, numero_anios;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca n�mero de a�os --> ";
   cin >> numero_anios;
   cout << "\nIntroduzca inter�s (como un %) --> ";
   cin >> interes;   
   
	/*
	Algoritmo:

		Incializar el capital obtenido al capital inicial

		Recorrer todos los a�os
			Acumular el capital del a�o anterior con el inter�s aplicado
	*/

   capital_acumulado = capital_inicial;
   anios_transcurridos  = 0; 
   
   while (anios_transcurridos < numero_anios){    
      capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0;   // valor nuevo = ciertas operaciones con valor antiguo 
      anios_transcurridos++;
		cout << "\nCapital obtenido transcurrido el a�o n�mero " << anios_transcurridos << " = " << capital_acumulado;   
   }

   cout << "\n\n";
   system("pause");
}
