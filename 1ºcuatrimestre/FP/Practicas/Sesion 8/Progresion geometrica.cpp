/*Cread las siguientes funciones relacionadas con la progresi�n geom�trica que se vio
en el ejercicio 23 de la relaci�n de problemas II. Analizad cu�les deben ser los par�metros
a estas funciones.

a) Una funci�n SumaHasta que calcule la suma de los primeros k valores de una
progresi�n geom�trica.

Cread un programa principal que llame a dicha funci�n.

b) Cambiemos ahora la implementaci�n de la anterior funci�n SumaHasta. Para
ello, en vez de usar un bucle aplicamos la siguiente f�rmula que nos da la sumatoria
aplicando �nicamente cinco operaciones:

Es muy importante remarcar que el programa main no cambia nada. Hemos
cambiado la implementaci�n de la funci�n y lo hemos podido hacer sin cambiar
el main, ya que �ste no ten�a acceso al c�digo que hay dentro de la funci�n. Esto
es ocultaci�n de informaci�n tal y como se describi� en las clases de teor�a.

Nota. Calculad la potencia (rk) con la funci�n Potencia definida en el ejercicio 3
de esta Relaci�n de Problemas.

Hay que destacar que el c�mputo de la potencia es una operaci�n costosa, por
lo que hasta podr�a ser m�s lenta la versi�n nueva que la antigua usando un
bucle for. Probad distintos valores para ver si hay diferencias significativas. En
cualquier caso, lo importante es que mientras no cambiemos la cabecera de la
funci�n SumaHasta, podemos cambiar su implementaci�n sin tener que cambiar
ni una l�nea de c�digo del main.

c) Una funci�n SumaHastaInfinito para calcular la suma hasta infinito, seg�n la
f�rmula:
siempre que el valor absoluto de la raz�n sea menor o igual que 1.

d) Una funci�n ProductoHasta para que multiplique los k primeros elementos de
la progresi�n, aplicando la f�rmula:
*/

#include <iostream>
#include <cmath>

using namespace std;

double SumaHasta(double num_a, double razon_r, double tope_k)		//apartado a
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

double SumaHasta2(double num_a, double razon_r, double tope_k)			//apartado b
{
	double total = 0;
	double numerador;
	double denominador;
	
	numerador = pow(razon_r, tope_k) - 1;		// se corresponde con r^k
	denominador = razon_r - 1;		
	total = total + num_a * (numerador / denominador);
	
	return total;
}

double SumaHastaInfinito(double num_a, double razon_r)
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

double ProductoHasta(double num_a, double razon_r, double tope_k)		//apartado d
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

int main()
{
	double num_a;
	double razon_r;
	double tope_k;
	double resultado1;
	double resultado2;
	double resultado3;
	double resultado4;
	
	do
	{
		cout << "\nIntroduzca el primer digito de la progresion: ";
		cin >> num_a;
		cout << "\nIntroduzca el factor (r): ";
		cin >> razon_r;
		cout << "\nIntroduzca el tope: ";
		cin >> tope_k;
	}while(tope_k < 0);	
	
	resultado1 = SumaHasta(num_a, razon_r, tope_k);
	resultado2 = SumaHasta2(num_a, razon_r, tope_k);
	resultado3 = SumaHastaInfinito(num_a, razon_r);
	resultado4 = ProductoHasta(num_a, razon_r, tope_k);
	
	cout << "\n\tLa suma de los terminos de la progresion  tiene como total: " << resultado1 << "\n";
	cout << "\n\tLa suma de los terminos de la progresion  tiene como valor final: " << resultado2 << "\n"; 
	cout << "\n\tLa suma de los terminos de la progresion hasta infinito tiene valor: " << resultado3 << "\n";
	cout << "\n\tSi la suma de los terminos en infinito es 0, "; 
	cout << "\n\tentonces la razon (r) es mayor de 1.\n";
	cout << "\n\tEl producto de los terminos de la progresion tiene valor: " << resultado4 << "\n";			

}
