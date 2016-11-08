/*El ejercicio reparte la ganancia de un producto cambiando ek tipo de dato de la ganancia.
		total = ganancia / persona
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int total;
	double ganancia;
	double persona;
	
	cout << "Introduzca el precio del producto: ";
	cin >> ganancia;
	cout << "Introduzca el numero de empleados: ";
	cin >> persona;
	
	total = ganancia / persona;
	
	cout << "El total es: " << total << "\n\n";
	
	return 0;
}
