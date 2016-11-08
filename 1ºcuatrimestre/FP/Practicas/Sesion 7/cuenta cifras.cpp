/* (Examen Septiembre 2014) �Cu�ntas veces aparece el d�gito 9 en todos los n�meros
que hay entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los n�meros 19 y
92 mientras que aparece dos veces en el 99. Pretendemos dise�ar un algoritmo que
responda a esta sencilla pregunta, pero de forma suficientemente generalizada. Para
ello, se pide construir un programa que lea tres enteros cifra (entre 1 y 9), min y
max y calcule el n�mero de apariciones del d�gito cifra en los n�meros contenidos
en el intervalo cerrado [min, max] */

#include <iostream>

using namespace std;

int main()
{
	 int min1;
	 int max1;
	 int num_descriptivo = 0;
	 int acumulador_numero = 0;
	 int i;
	 int resto;
	 int numero; 
 
	 do
	 {
		 cout << "\nIntroduzca el primer numero (min): ";    //Introducimos el numero de donde partimos a contar.
		 cin >> min1;
		 cout << "\nIntrduzca un tope (max): ";    //Introducimos o tope.
		 cin >> max1;
		 cout << "\nIntroduzca el numero que quiere reconocer: ";  //N�mero que buscamos.
		 cin >> num_descriptivo;
		 cout << "\n";
	 }while ((max1 < min1) || (min1 < 0));   //Filtro para reconocer si el n�mero max es menor que el min y mayor que 0.
	 
	 for (i = min1; i <= max1; i++)     //Bucle FOR recorre del min al max
	 {
	  	numero = i;
	  	
		while( (numero != 0))  //El bucle se hace mientras el numero2 sea diferente de 0.
		{
			resto = numero % 10;		
			numero = numero / 10;
		   
			if(resto == num_descriptivo)       //A�adimos 1 si el resto es igual al n�mero que buscamos.
			{
				acumulador_numero++;
			} 
		}
	 }
	 
	 cout << "\nEl numero de veces totales que aparece el numero " << num_descriptivo << " es: " << acumulador_numero << "\n";
	 
}	

