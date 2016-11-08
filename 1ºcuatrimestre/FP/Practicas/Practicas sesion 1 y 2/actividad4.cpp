/* El programa lee los coeficientes de mu y de sigma e imprime el valor que toma x
	resultado = 1/(sigma*sqrt(2*3.1416))*e^(-1/2*((abcisa-mu/sigma)^2))
	func1 = 1/(sigma*sqrt(2*3.1416))
	func2 = pow((abcisa-mu)/(sigma,2))
	expo = exp(-1/2*func2)
	resultado = func1*exp
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double resultado;
	double func1;
	double func2;
	double expo;
	double mu;
	double sigma;
	double abcisa;
	
	cout << "Introduzca el valor de sigma: ";
	cin >> sigma;
	cout << "Introduza el valor de mu: ";
	cin >> mu;
	cout << "Introduza el valor de la abcisa: ";
	cin >> abcisa;
	
	func1 = 1/(sigma*sqrt(2*3.1416));
	func2 = pow((abcisa-mu)/sigma,2);
	expo = exp(-1/2*func2);
	resultado = func1*expo;
	
	cout << "\nEl valor del resultado es: " << resultado << "\n\n";
}
	
	
	


