/*expresi�n l�gica que sea verdadera si una variable de tipo car�cter llamada
letra es una letra min�scula y falso en otro caso*/

#include <iostream>

using namespace std;

int main() {
    char letra;                             //Variable tipo letra.
        
    cout << "\nIntroduzca la letra: "; 
    cin >> letra;
    
    if(letra == toupper(letra))
    {                            //La funcion toupper pasa a mayuscula, al ponerla en if estas condicionando la mayuscla.
        cout << "\n\tLa letra introducida es mayuscula" "\n\n";
    }
    
    else 
    {
        cout << "\n\n\tLa letra introducida es una minuscula" "\n\n";
    }
}
