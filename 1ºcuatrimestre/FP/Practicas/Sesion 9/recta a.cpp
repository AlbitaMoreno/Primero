/*En este ejercicio se plantean varias modificaciones. Debe entregar un fichero cpp por
cada uno de los apartados.
Se desea implementar una clase Recta para representar una recta en el plano. Una
recta viene determinada por tres coeficientes A, B, C, de forma que todos los puntos
(x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0

a) Definición de la clase y creación de objetos
Defina la clase Recta. En este apartado utilice únicamente datos miembro públicos.
Cree un programa principal que haga lo siguiente:
 Defina dos objetos de la clase Recta.
 Lea seis reales desde teclado.
 Le asigne los tres primeros a los coeficientes de una recta y los otros tres a
la segunda recta.
 Calcule e imprima la pendiente de cada recta aplicando la fórmula:
pendiente = - A / 
*/

#include <iostream>

using namespace std;

class Recta{
	public:			//Los objetos de la clase recta son públicos , asi lo especifica el problema
		double a, b, c, x, y;
};

int main(){
	Recta recta1;		//Objeto de la clase Recta.
	Recta recta2;
	double pendiente;
	
	cout << "\nRecta de la forma Ax + By + C\n";
	cout << "\tValor A en la recta uno: ";
	cin >> recta1.a;									//Guardamos el valor de a en recta1.
	cout << "\tValor B en la recta uno: ";
	cin >> recta1.b;
	cout << "\tValor C en la recta uno: ";
	cin >> recta1.c;
	
	pendiente =  -recta1.a/recta1.b;		
	
	cout << "\nLa pendiente de la recta1 es: " << pendiente << "\n\n";
	
	cout << "\tValor A en la recta dos: ";
	cin >> recta2.a;
	cout << "\tValor B en la recta dos: ";
	cin >> recta2.b;
	cout << "\tValor C en la recta dos: ";
	cin >> recta2.c;
	
	
	pendiente = -recta2.a/recta2.b;		//Machacamos el primer valor de la pendiente y mostramos el segundo.
			
	cout << "\nLa pendiente de la recta2 es: " << pendiente;
	cout << "\n\n";
}
