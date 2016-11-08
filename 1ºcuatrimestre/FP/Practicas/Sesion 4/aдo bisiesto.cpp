/*Cread un programa que lea el número de un año e indique si es bisiesto o no. Un año
es bisiesto si es múltiplo de cuatro, pero no de cien. Excepción a la regla anterior son
los múltiplos de cuatrocientos que siempre son bisiestos*/

#include <iostream>

using namespace std;

int main(){
    int anio;                   
    
    cout << "\nIntroduzca el anio: ";
    cin >> anio;
    
    if(anio %4 == 0){
        cout << "\n\tEl anio escrito es bisiesto" "\n\n";
    } 
    
    else{
        cout << "\n\tEl anio no es bisiesto" "\n\n";
    }
}
