/*Constructor
Modifique el programa principal del �ltimo apartado e imprima los valores de los
datos miembros de una recta, antes de asignarles los coeficientes. Mostrar�, obviamente,
un valor indeterminado. Para evitar este problema, a�ada un constructor
a la recta para que el objeto est� en un estado v�lido en el mismo momento
de su definici�n. El constructor deber� tener como par�metros, obligatoriamente,
los tres coeficientes de la recta. Tendr� que modificar convenientemente el main
para tener en cuenta este cambio.
*/

#include <iostream>

using namespace std;

class Recta{
	private:			//Los objetos de la clase recta son privados , asi lo especifica el apartado c.
		double a, b, c, x, y;
	
	public:	
		Recta(){				//Constructor, incializa todo a un valor.
			a = b = c = x = y = 0;
		}
		void SetCoeficientes(double datoA, double datoB, double datoC, double datoX, double datoY)
		{
			a = datoA;
			b = datoB;
			c = datoC;
			x = datoX;
			y = datoY;
		}
		double ObtenerPendiente(){		//No var�a ObtenerPendiente, ObtenerAbcisa, ObtenerOrdenada.
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
	double a,b,c,x,y;
	
	cout << "\nRecta de la forma Ax + By + C\n";
	//Recta 1:
	cout << "\tValor A en la recta uno: ";
	cin >> a;
	cout << "\tValor B en la recta uno: ";
	cin >> b;
	cout << "\tValor C en la recta uno: ";
	cin >> c;
	cout << "\tIntroduzca un valor para la ordenada (x): ";
	cin >> x;
	cout << "\tIntroduzca un valor para la abcisa (y): ";
	cin >> y;
	recta1.SetCoeficientes(a,b,c,x,y);
	
	pendiente1 = recta1.ObtenerPendiente();		
	ordenada1 = recta1.ObtenerOrdenada();
	abcisa1 = recta1.ObtenerAbcisa();
	
	cout << "\nLa pendiente de la recta1 es= " << pendiente1 << "\n\n";
	cout << "\nEl valor de la ordenada en el punto (y) " << y << " es= " << ordenada1;
	cout << "\nEl Valor de la abcisa en el punto (x) " << x << " es= " << abcisa1;
	cout << "\n\n";	
	//Recta 2:
	cout << "\tValor A en la recta dos: ";
	cin >> a;
	cout << "\tValor B en la recta dos: ";
	cin >> b;
	cout << "\tValor C en la recta dos: ";
	cin >> c;
	recta2.SetCoeficientes(a,b,c,0,0)			//Como de la recta2 s�lo nos piden calcular la pendiente, x e y no son necesario, pero al ser SertCoeficientes un m�todo con cinco argumentos debemos poner dos ceros. Sino dar�a error.
	
	pendiente2 = recta2.ObtenerPendiente();		//Machacamos el primer valor de la pendiente y mostramos el segundo.
			
	cout << "\nLa pendiente de la recta2 es= " << pendiente2;
	cout << "\n\n";		
}
