/* (Examen Septiembre 2014) ¿Cuántas veces aparece el dígito 9 en todos los números
que hay entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los números 19 y
92 mientras que aparece dos veces en el 99. Pretendemos diseñar un algoritmo que
responda a esta sencilla pregunta, pero de forma suficientemente generalizada. Para
ello, se pide construir un programa que lea tres enteros cifra (entre 1 y 9), min y
max y calcule el número de apariciones del dígito cifra en los números contenidos
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
		 cout << "\nIntroduzca el numero que quiere reconocer: ";  //Número que buscamos.
		 cin >> num_descriptivo;
		 cout << "\n";
	 }while ((max1 < min1) || (min1 < 0));   //Filtro para reconocer si el número max es menor que el min y mayor que 0.
	 
	 for (i = min1; i <= max1; i++)     //Bucle FOR recorre del min al max
	 {
	  	numero = i;
	  	
		while( (numero != 0))  //El bucle se hace mientras el numero2 sea diferente de 0.
		{
			resto = numero % 10;		
			numero = numero / 10;
		   
			if(resto == num_descriptivo)       //Añadimos 1 si el resto es igual al número que buscamos.
			{
				acumulador_numero++;
			} 
		}
	 }
	 
	 cout << "\nEl numero de veces totales que aparece el numero " << num_descriptivo << " es: " << acumulador_numero << "\n";
	 
}	

