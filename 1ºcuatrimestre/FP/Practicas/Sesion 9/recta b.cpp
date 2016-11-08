/*b) Métodos públicos
En vez de calcular la pendiente en el programa principal, vamos a ponerlo como
un método de la clase y así lo reutilizaremos todas las veces que necesitemos.
Añada un método para el cálculo de la pendiente y modificad el main para tener
en cuenta este cambio.

¿Añadimos pendiente como dato miembro de la recta? La respuesta es que
no ¿Por qué?

Añadir también los siguiente métodos:
 Obtener la ordenada (y) dado un valor de abscisa x, aplicando la fórmula:
(-C -xA) / B
 Obtener la abscisa (x) dado un valor de ordenada y, aplicando la fórmula:
(-C -yB) / A
En la función main leed un valor de abscisa e imprimir la ordenada según la recta
y leed un valor de ordenada e imprimid la abscisa que le corresponde. 
Hacedlo sólo con la primera recta.*/

#include <iostream>

using namespace std;
//No debemos incluir pendiente como miembro de la clase Resta porque es una propiedad, se puede calcular en función de los datos.
class Recta{
	public:			//Los objetos de la clase recta son públicos , asi lo especifica el problema
		double a, b, c, x, y;
		
		double ObtenerPendiente(){		//Método que devuelve el valor de la pendiente, que es el valor que queremos mostrar.
			return -a / b;
		}
		double ObtenerAbcisa(){
			return (-c - a * x) / b;
		}
		double ObtenerOrdenada(){
			return (-c - b * y) / a;
		}
};
		
int main(){
	Recta recta1;		//Objeto de la clase Recta.
	Recta recta2;
	double pendiente1;
	double pendiente2;
	
	double abcisa1;
	double ordenada1;
	
	cout << "\nRecta de la forma Ax + By + C\n";
	cout << "\tValor A en la recta uno: ";
	cin >> recta1.a;									//Guardamos el valor de a en recta1, antes a = 0.
	cout << "\tValor B en la recta uno: ";
	cin >> recta1.b;
	cout << "\tValor C en la recta uno: ";
	cin >> recta1.c;
	cout << "\tIntroduzca un valor para la ordenada (x): ";
	cin >> recta1.x;
	cout << "\tIntroduzca un valor para la abcisa (y): ";
	cin >> recta1.y;
	
	pendiente1 = recta1.ObtenerPendiente();		//Llamamos al método de la clase Recta que nos devuelve el valor de la pendiente.
	ordenada1 = recta1.ObtenerOrdenada();
	abcisa1 = recta1.ObtenerAbcisa();
	
	cout << "\nLa pendiente de la recta1 es= " << pendiente1 << "\n\n";
	cout << "\nEl valor de la ordenada en el punto (y) " << recta1.y << " es= " << ordenada1;
	cout << "\nEl Valor de la abcisa en el punto (x) " << recta1.x << " es= " << abcisa1;
	cout << "\n\n";	
	
	cout << "\tValor A en la recta dos: ";
	cin >> recta2.a;
	cout << "\tValor B en la recta dos: ";
	cin >> recta2.b;
	cout << "\tValor C en la recta dos: ";
	cin >> recta2.c;
	
	pendiente2 = recta2.ObtenerPendiente();		//Machacamos el primer valor de la pendiente y mostramos el segundo.
			
	cout << "\nLa pendiente de la recta2 es= " << pendiente2;
	cout << "\n\n";		
}
