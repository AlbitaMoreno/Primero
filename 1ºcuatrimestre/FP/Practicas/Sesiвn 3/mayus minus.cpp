/* programa que lea un car�cter (supondremos que el usuario introduce una
may�scula), lo pase a min�scula y lo imprima en pantalla*/

#include <iostream>

using namespace std;

int main(){
	char c;
	
	cout << "Introduzca una letra: ";
	cin >> c;
	
	if(c >= 'a' and c <= 'z' ){
		c -= 'a' - 'A';										// c -= a - A significa que el caracter que introduzcas
		cout << "\n\tLa letra es: " << c << "\n\n";	//se le resta (a-A)
	}
	
	else if( c >= 'A' and c <= 'Z'){
		c -= 'A' - 'a';
		cout << "\n\tLa letra es: ";
	}

return 0;	
}


