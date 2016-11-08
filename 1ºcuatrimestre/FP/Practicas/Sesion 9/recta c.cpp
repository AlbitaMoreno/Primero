/*Datos miembro privados
Cambie ahora los datos miembro públicos y póngalos privados. Tendrá que añadir métodos para asignar y ver los valores de los datos miembro. Añada métodos
para asignar un valor a cada uno de los tres datos miembro. Modifique el main para tener en cuenta estos cambios.
*/

#include <iostream>

using namespace std;

class Recta{
	private:			//Los objetos de la clase recta son privados , asi lo especifica el apartado c.
		double a, b, c, x, y;
	
	public:	
		double Coef1(double coef1){
			a = coef1;
		}
		double Coef2(double coef2){
			 b = coef2;
		}
		double Coef3(double coef3){
			 c = coef3;
		}
		double Ordenadas(double ordenada){
			x = ordenada;
		}
		double Abcisas(double abcisa){
			y = abcisa;
		}
		double ObtenerPendiente(){		//No varía ObtenerPendiente, ObtenerAbcisa, ObtenerOrdenada.
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
	recta1.Coef1(a);									//Guardamos el valor de a en recta1, antes a = 0.
	cout << "\tValor B en la recta uno: ";
	cin >> b;
	recta1.Coef2(b);
	cout << "\tValor C en la recta uno: ";
	cin >> c;
	recta1.Coef3(c);
	cout << "\tIntroduzca un valor para la ordenada (x): ";
	cin >> x;
	recta1.Ordenadas(x);
	cout << "\tIntroduzca un valor para la abcisa (y): ";
	cin >> y;
	recta1.Abcisas(y);
	
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
	recta2.Coef1(a);
	cout << "\tValor B en la recta dos: ";
	cin >> b;
	recta2.Coef1(b);
	cout << "\tValor C en la recta dos: ";
	cin >> c;
	recta2.Coef1(c);
	
	pendiente2 = recta2.ObtenerPendiente();		//Machacamos el primer valor de la pendiente y mostramos el segundo.
			
	cout << "\nLa pendiente de la recta2 es= " << pendiente2;
	cout << "\n\n";		
}
