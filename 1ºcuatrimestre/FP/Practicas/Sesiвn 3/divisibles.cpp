/* El programa ve si dos números son divisible entre si*/

#include <iostream>

using namespace std;

int main(){
	int num1;
	int num2;
	
	cout << "\nIntroduzca el digito de valor superior: ";
	cin >> num1;
	cout << "\nIntroduzca el digito de valor inferior: ";
	cin >> num2;
	
	if(num1 %num2 == 0){
		cout << "\n\tLos digitos son divisibles";
	}
		
	else{
		cout << "\n\tLos digitos no son divisibles";
	}
}
