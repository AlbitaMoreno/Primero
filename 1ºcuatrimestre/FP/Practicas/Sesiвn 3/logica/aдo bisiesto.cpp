/*expresión lógica que nos informe cuando un año es bisiesto.*/

#include <iostream>

using namespace std;

int main(){
    int anio;                   
    
    cout << "\nIntroduzca el anio: ";
    cin >> anio;
    
    if(anio %4 == 0)            //sera año bisiesto si al dividir el año entre 400 el resto es 0
    {
        cout << "\n\tEl anio escrito es bisiesto" "\n\n";
    } 
    
    else
    {
        cout << "\n\tEl anio no es bisiesto" "\n\n";
    }
}

                                
