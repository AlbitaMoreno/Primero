/*Métodos privados
Añada un método privado que nos indique si los coeficientes son correctos, es
decir, A y B no pueden ser simultáneamente nulos. Llame a este método en el
constructor y en el método SetCoeficientes y realice las operaciones que
estime oportuno en el caso de que los coeficientes pasados como parámetros no
sean correctos.*/

#include <iostream>

using namespace std;

class Recta{
	private:			//Los objetos de la clase recta son privados , asi lo especifica el apartado c.
		double a, b, c, x, y;
		bool VerificarCoeficientes(double a, double b){
			bool verificar = false;
			return verificar = (a == 0 && b == 0);		//Devuelve true si a y b son 0.
		}
	public:	
		Recta(){			
			if(!VerificarCoeficientes(a,b))
				a = b = c = x = y = 0;
			
		}
		bool SetCoeficientes(double datoA, double datoB, double datoC, double datoX, double datoY)
		{			
			if(!VerificarCoeficientes(datoA,datoB)){
			
				a = datoA;
				b = datoB;
				c = datoC;
				x = datoX;
				y = datoY;
			}
			else{
				a = b = c = x = y = 0;
			}
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
	recta2.SetCoeficientes(a,b,c,0,0);
	
	pendiente2 = recta2.ObtenerPendiente();		//Machacamos el primer valor de la pendiente y mostramos el segundo.
	
	cout << "\nLa pendiente de la recta2 es= " << pendiente2;
	cout << "\n\n";		
}
