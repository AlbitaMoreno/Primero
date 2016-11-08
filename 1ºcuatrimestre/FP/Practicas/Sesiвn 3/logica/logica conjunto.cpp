/*programa que lea las variables letra, edad y anio, calcule el valor de
las expresiones lógicas anteriores e imprima el resultado*/

#include <iostream>

using namespace std;

int main(){
    char letra;
    int edad;
    int anio;
    
    cout << "Introduce la letra: " "\n";
    cin >> letra;
    cout << "\nIntroduce la edad: " "\n";
    cin >> edad;
    cout << "\nIntroduce el anio: " "\n";
    cin >> anio;
    
    if(letra == toupper(letra))
    {                            
        cout << "\n\tLa letra introducida es mayuscula" "\n\n";
    }
    
    else 
    {
        cout << "\n\n\tLa letra introducida es una minuscula" "\n\n";
    }
    
    if(edad >=18 and edad <= 65)
    {
         cout << "\n\tLa edad introducida esta en el rango comprendido" "\n\n";
    }
   
    else
    {
        cout << "\n\tLa edad no es valida" "\n\n";
    }
    
     if(anio %4 == 0)          
    {
        cout << "\n\tEl anio escrito es bisiesto" "\n\n";
    } 
    
    else
    {
        cout << "\n\tEl anio no es bisiesto" "\n\n";
    }
system("PAUSE");
}
