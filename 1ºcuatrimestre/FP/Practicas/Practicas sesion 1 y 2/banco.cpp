/* El programa calcula la variable total del dinero que se tendr� al cabo de un a�o en el banco.
Esto se har� mediante la f�rmula:
		total = capital + capital*(interes/100)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double capital;
	double interes;
	double total;
	
	cout << "Introduzca el capital: ";
	cin >> capital;
	cout << "Introduzca el interes: ";
	cin >> interes;
	
	total = capital + capital*(interes/100);
	
	cout << "\nEl total es: " << total << "\n\n";
	
	capital = total;
	
	cout << "\nEl capital sera: " << capital << "\n\n";
}
