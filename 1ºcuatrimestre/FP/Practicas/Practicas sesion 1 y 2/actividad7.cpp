/* El programa calcula la media aritmetica muestral y la desviación estándar de la altura de tres 
personas. 
n = 3 		media = 1/3*(dato1 + dato2 + dato3)  
desviación = sqrt(1/3*(dato1 + dato2 + dato3 - media)*(dato1 + dato2 + dato3 - media))
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double media;
	double desviacion;
	double dato1;						//siendo las variables dato las alturas de las personas.
	double dato2;
	double dato3;
	
	cout << "Introduzca 1 medida: ";
	cin >> dato1;
	cout << "Introduzca 2 medida: ";
	cin >> dato2;
	cout << "Introduzca 3 medida: ";
	cin >> dato3;
	
	media = (dato1 + dato2 + dato3) / 3;
	
	cout << "\nEl valor de la media aritmetica muestral es: " << media << "\n\n";
	
	desviacion = sqrt((dato1 + dato2 + dato3 - media)*(dato1 + dato2 + dato3 - media))/ 3;
	
	cout << "\nEl valor de desviación es: " << desviacion << "\n\n";
	
	system("PAUSE");
}
