#include <iostream>

using namespace std;

class Recta{		// Definimos la clase que se llama Recta
	public:			// Todos los datos son públicos porque lo pide el ejercicio
		double a, b, c, x, y;	// Declaro todas las variables de una recta Ax + By + C = 0, aunque en este ejemplo solo hagan dalta la A y la B es mejor hacer la clase de forma genérica para que funcione en otro programas si hace falta
		
		Recta(){		// El constructor para inicializar todo a cero en caso de que no le asignemos nada a algún dato, los constructores hay que ponerlos siempre y tienen que ser SIEMPRE PUBLICOS
			a = b = c = x = y = 0;
		}
		
		double Pendiente(){  // Declaramos el método, lo llamo pendiente porque lo que va a hacer es calcular la pendiente. Los métodos tienes que verlos como si fuesen funciones, que en verdad es lo que son. Pueden usarse para darle valores a las variables de la clase (a, b, c...) o para hacer calculos como en este caso
			return -a/b;	// Éste método calcula la pendiente de la recta cuando lo usas
		}
};
		
int main(){		// Empezamos el programa
	Recta recta1;	// Declaramos recta1 y recta2 como objetos de nuestra clase, vamos, como si ponemos int recta1 int recta2 por ejemplo
	Recta recta2;
	
	cout << "En la recta Ax + By + C = 0 dime un valor para A: ";		// Pido los valores de A b y C y los guardo en a b y c de la recta1
	cin >> recta1.a;
	cout << "En la recta Ax + By + C = 0 dime un valor para B: ";
	cin >> recta1.b;
	cout << "En la recta Ax + By + C = 0 dime un valor para C: ";
	cin >> recta1.c;
	
	cout << "\nLa pendiente de la recta es: " << recta1.Pendiente();	// Cuando ya tengo los datos de a b y c en mi recta1 puedo llamar al método Pendiente, para que calcule la pendiente de la recta1. Como solo es una línea lo he puesto en el mismo cout, es como si pones     cout << 5+3;      sin poner antes        x = 5+3;    cout << x;     pos pongo el método dentro del cout para ahorrar una variable
	cout << "\n\n";
}
	// Este es un ejemplo sencillo, el ejercicio 7 pide esto pero lo mismo que lo hago para recta1 pues para recta2 también, pero eso se hace con un while o como quieras, no hay que hacer otra clase ni nada de eso. Es como si tienes una función que hace el factorial y tu la llamas las veces que quieras para los datos que quieras sin tener que hacer 20 funciones de factorial. En todo caso, si luego envez de la pendiente pide pide otra cosa pues abrá que hacer otro método que haga otras cosas con los datos y devuelva lo que quieras, o nada, pero la clase es geérica.
	
	
	
	
