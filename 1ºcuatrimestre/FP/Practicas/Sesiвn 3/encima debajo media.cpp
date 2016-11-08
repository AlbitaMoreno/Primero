/* El programa calcula la media aritmetica muestral y la desviaci�n est�ndar de la altura de tres 
personas. 
n = 3 		media = 1/3*(dato1 + dato2 + dato3)  
desviaci�n = sqrt(1/3*(dato1 + dato2 + dato3 - media)*(dato1 + dato2 + dato3 - media))
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double media;
	double desviacion;
	double dato1;						
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
	
	cout << "\nEl valor de desviacion es: " << desviacion << "\n\n";
	
	//ampliacion:
	
	if(desviacion < media){
		cout << "\n\tLa desviacion es menor que la media";
	}
	
	else{
		cout << "\n\tLa desviacion es mayor o igual a la media";
	}
}

//para esta ampliaci�n del ejercicio debemos usar el condicional if; yo lo he usado para que la 
//desviaci�n sea menor que la media, pero se podr�a haber utilizado para que la desviaci�n fuese 
//mayor o igual o menos o igual.
//Si la condicion if no se cumple entonces el resultado debr� ser, en este caso, que la desviaci�n 
//es mayor o igual.
