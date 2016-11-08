////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Calcular el total acumulado de un capital y los intereses correspondientes
   en varios años sucesivos
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado;
   int anios_transcurridos, numero_anios;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca número de años --> ";
   cin >> numero_anios;
   cout << "\nIntroduzca interés (como un %) --> ";
   cin >> interes;   
   
	/*
	Algoritmo:

		Incializar el capital obtenido al capital inicial

		Recorrer todos los años
			Acumular el capital del año anterior con el interés aplicado
	*/

   capital_acumulado = capital_inicial;
   anios_transcurridos  = 0; 
   
   while (anios_transcurridos < numero_anios){    
      capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0;   // valor nuevo = ciertas operaciones con valor antiguo 
      anios_transcurridos++;
		cout << "\nCapital obtenido transcurrido el año número " << anios_transcurridos << " = " << capital_acumulado;   
   }

   cout << "\n\n";
   system("pause");
}
