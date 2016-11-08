/*segunda parte del ejercicio "subir sueldo"*/

#include <iostream>

using namespace std;

int main(){
	int edad;
	double salario;
	double total2;
	double total3;
	
	cout << "\nIntroduzca la edad: ";
	cin >> edad;
	cout << "\nIntroduzca el salario: ";
	cin >> salario;
	
	if(edad > 65 or edad <35){
	
		total2 = 0.04*salario + salario;
		
		//cout << "\n\tEl salario total es: " << total2 << "\n\n";
		
		if(salario < 300){														//Para que se cumpla la segunda condición entonces debemos usar un condicial if.
																						//de modo que si el salario es menor de 300 se ejecuta el if y sino el else muestra 															
			total3 = 0.03*total2 + total2;												//el resultado del while (total2)
			
			cout << "\n\tEl salario total es: " << total3 << "\n\n";
		}
		else{
			cout << "\n\tEl salario total es: " << total2 << "\n\n";
		}
	
	}
	else{
		cout << "\n\tNo aplicable la subida";	
	}
}
