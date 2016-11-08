/*En el ejercicio 4 de esta relación de problemas se definieron varias funciones para
operar sobre una progresión geométrica. Definid ahora una clase para representar
una progresión geométrica.

a) Diseñad la clase pensando cuáles serían los datos miembro esenciales que definen
una progresión geométrica, así como el constructor de la clase.

b) Definir un método Termino que devuelva el término k-ésimo.

c) Definid los métodos SumaHastaInfinito, SumaHasta, MultiplicaHasta.

d) Cread un programa principal que lea los datos miembro de una progresión, cree el
objeto correspondiente y a continuación lea un entero tope e imprima los tope
primeros términos de la progresión, así como la suma hasta tope de dichos
términos.
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
		{			//El termino k-ésimo se refiere al término general de la sucesión.
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
			int i = 2;						// i=1 es el primer termino de la sucesión.
			double total = 0;
			double num_ak = num_a;
			
			do
			{
				num_ak = num_ak * razon_r;		//para sacar el último elemento de la progresión
				i++;
			}while(i <= tope_k);
			
			total = 	sqrt(pow(num_a * num_ak, tope_k));
			return total;
		}
		
};

int main()
{
	Progresion valores;		//dentro de valores están: a, r y k.
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
