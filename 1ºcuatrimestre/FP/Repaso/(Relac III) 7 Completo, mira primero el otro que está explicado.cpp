#include <iostream>

using namespace std;

class Recta{
	public:
		double a, b, c, x, y;
		
		Recta(){
			a = b = c = x = y = 0;
		}
		
		double Pendiente(){
			return -a/b;
		}
};
		
int main(){
	Recta recta1;
	Recta recta2;
	double pendiente1;
	double pendiente2;
	
	cout << "En la recta1 Ax + By + C = 0 dime un valor para A: ";
	cin >> recta1.a;
	cout << "En la recta1 Ax + By + C = 0 dime un valor para B: ";
	cin >> recta1.b;
	cout << "En la recta1 Ax + By + C = 0 dime un valor para C: ";
	cin >> recta1.c;
	
	pendiente1 = recta1.Pendiente();		// Igual que que el otro, lo que pasa es que ahora vamos a calcular dos pendientes y para no perder el valor lo guardamos en una variable
	
	cout << "\nEn la recta2 Ax + By + C = 0 dime otro valor para A: ";
	cin >> recta2.a;
	cout << "En la recta2 Ax + By + C = 0 dime otro valor para B: ";
	cin >> recta2.b;
	cout << "En la recta2 Ax + By + C = 0 dime otro valor para C: ";
	cin >> recta2.c;
	
	pendiente2 = recta2.Pendiente();		// Lo mismo que he hecho para la recta1 ahora lo hago para la recta2
	
	cout << "\nLa pendiente de la recta1 es: " << pendiente1;		// Aqui si que saco por pantalla la variable que tiene el valor de la pendiente, porque como he llamao dos veces al método Pendiente un valor machaca al anterior
	cout << "\nLa pendiente de la recta2 es: " << pendiente2;
	cout << "\n\n";
}
// Como ves el ejercicio en verdad es sencillo, y solo hace falta una clase y un método para poder hacer todas las rectas que quieras
// Puedes pedir tres datos para recta1, llamas al método, lo sacas por pantalla, luego pides otros tres para recta2, llamas otra vez a método y lo sacas por pantalla, así no haría falta usar variables para guardar la pendiente que sale, pero es mejor ir guardándolas en variables, xk se supone que son datos que se usarán para algo
