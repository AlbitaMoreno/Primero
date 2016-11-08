#include <iostream>
#include <cmath>

using namespace std;

/* Al introducir unaos datos para cada una de las tres variables (horas, minutos y segundos) el 
programa nos dara el resultado dentro del rango. No calcula años, ni meses... 
*/

int main(int argc, char** argv) {
	
	int horas, minutos, segundos, dias, x, y, z;
	
	cout << "Introduzca las horas: ";
	cin >> horas;
	cout << "Introdizca los minutos: ";
	cin >> minutos;
	cout << "Introduzca los segundos: ";
	cin >> segundos;
	
	x = segundos/60;
	segundos = segundos %60;
	y = x + minutos;
	z = y/60;
	minutos = y %60;
	horas = horas + z;
   dias= horas/24;
   horas = horas %24;
	
   cout << "\n\n\n\tLos dias totales serian: " << dias << "\n";	
	cout << "\n\tLas horas totales serian: " << horas << "\n\n";
	cout << "\n\tLos minutos totales serian: " << minutos << "\n\n";
	cout << "\n\tLos segundos serian: " << segundos << "\n\n";
	cout << "\n\t " << horas << " : " << minutos << " : " << segundos << "\n\n";
	
	system("PAUSE");
	
	return 0;
}
