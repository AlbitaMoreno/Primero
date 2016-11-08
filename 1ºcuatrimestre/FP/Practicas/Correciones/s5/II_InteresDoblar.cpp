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
   Calcular el número de años que han de pasar para obtener un total acumulado 
   del doble del capital inicial
*/

#include <iostream> 
using namespace std;  
   
int main(){    
   double interes, capital_inicial, capital_acumulado, cuantia_final_a_conseguir;
   int  anios_transcurridos;
   
   cout << "Introduzca capital inicial --> ";
   cin >> capital_inicial;
   cout << "\nIntroduzca interés (como un %) --> ";
   cin >> interes;   

   /*
	Algoritmo:

		Incializar el capital obtenido al capital inicial

		Recorrer años hasta llegar al capital objetivo
			Acumular el capital del año anterior con el interés aplicado
	*/

	/*
		Si ponemos:
			while (capital_acumulado < capital_inicial * 2)
		estamos evaluando la misma expresión capital_inicial * 2 cada vez que entremos al bucle.
		Como la expresión no varía, mejor guardamos el valor en una variable antes de entrar al bucle:
	*/

   capital_acumulado = capital_inicial;
   anios_transcurridos = 0;
   cuantia_final_a_conseguir = capital_inicial * 2;

   while (capital_acumulado < cuantia_final_a_conseguir){             
      capital_acumulado = capital_acumulado  +  capital_acumulado * interes / 100.0;
		anios_transcurridos++;  
      cout << "\nDinero obtenido en el año número " << anios_transcurridos << " = " << capital_acumulado;   
   }
   
   cout << "\n\nPara doblar la cantidad inicial han de pasar " << anios_transcurridos << " años";
   
   cout << "\n\n";
   system("pause");
}
