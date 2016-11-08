/* El programa pide un radio y calcula el área del círculo y la longitud de la circunferencia
		longitud = 2*3.1416*r		área = 3.1416*r^2
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double radio;
	double longitud;
	double area;
	
	cout << "Introduzca valor de radio ";
	cin >> radio;
	
	longitud = 2*3.1416*radio;
	
	cout << "\nEl valor de la longitud es: " << longitud <<"\n\n";
	
	area = 3.1416*radio*radio;
	
	cout << "\nEl valor del area es: " << area <<"\n\n";
}
	
