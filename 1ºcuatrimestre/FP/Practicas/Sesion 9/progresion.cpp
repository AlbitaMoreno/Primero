/*En el ejercicio 4 de esta relaci�n de problemas se definieron varias funciones para
operar sobre una progresi�n geom�trica. Definid ahora una clase para representar
una progresi�n geom�trica.

a) Dise�ad la clase pensando cu�les ser�an los datos miembro esenciales que definen
una progresi�n geom�trica, as� como el constructor de la clase.

b) Definir un m�todo Termino que devuelva el t�rmino k-�simo.

c) Definid los m�todos SumaHastaInfinito, SumaHasta, MultiplicaHasta.

d) Cread un programa principal que lea los datos miembro de una progresi�n, cree el
objeto correspondiente y a continuaci�n lea un entero tope e imprima los tope
primeros t�rminos de la progresi�n, as� como la suma hasta tope de dichos
t�rminos.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Progresion{
	private:
		double num_a;
		double razon_r;
		double tope_k;
	
	public:
		Progresion(){
			num_a = razon_r = tope_k = 0;
		}
		void SetProgresion(double incio, double razon, double tope)
		{
			num_a = incio;
			razon_r = razon;
			tope_k = tope;
		}
		double HallarTermino()
		{			//El termino k-�simo se refiere al t�rmino general de la sucesi�n.
			double term_general;
			int i;
			for(i = 1; i <= tope_k; i++){
				term_general = num_a * pow(razon_r, (i -1));
			}
			return term_general;	
		}
		double SumarHasta()		//apartado a
		{
			int i;
			double total = 0;
			double exponente;
			
			for(i = 1; i <= tope_k; i++)
			{
				exponente = num_a * pow(razon_r,(i-1));		// se corresponde con r^(k-1), la base es razon_r y el exponente (k-1)
				total = total + exponente;
			}
			
			return total;
		}
		
		double SumarHastaInfinito()
		{
			double total = 0;
			double denominador;
			double division;		
				
			if(razon_r <= 1)
			{
				denominador = (1 - abs(razon_r));
				division = num_a / denominador;
				total = total + division;
			}
		
			return total;
		}
		double MultiplciarHasta()		//apartado d
		{
			int i = 2;						// i=1 es el primer termino de la sucesi�n.
			double total = 0;
			double num_ak = num_a;
			
			do
			{
				num_ak = num_ak * razon_r;		//para sacar el �ltimo elemento de la progresi�n
				i++;
			}while(i <= tope_k);
			
			total = 	sqrt(pow(num_a * num_ak, tope_k));
			return total;
		}
		
};

int main()
{
	Progresion valores;		//dentro de valores est�n: a, r y k.
	double termino;
	double suma;
	double infinito;
	double producto;
	double num_a, razon_r, tope_k;
	do
	{
		cout << "\nIntroduzca el primer digito de la progresion: ";
		cin >> num_a;
		cout << "\nIntroduzca el factor (r): ";
		cin >> razon_r;
		cout << "\nIntroduzca el tope: ";
		cin >> tope_k;
		valores.SetProgresion(num_a,razon_r,tope_k);
	}while(tope_k < 0);
	
	termino = valores.HallarTermino();
	suma = valores.SumarHasta();
	infinito = valores.SumarHastaInfinito();
	producto = valores.MultiplciarHasta();
	
	cout << "\n\tEl k-esimo termino de la progresion es: " << termino << "\n";
	cout << "\n\tLa suma de los terminos de la progresion  tiene como total: " << suma << "\n";
	cout << "\n\tLa suma de los terminos de la progresion hasta infinito tiene valor: " << infinito << "\n";
	cout << "\n\tEl producto de los terminos de la progresion tiene valor: " << producto << "\n";		
}
