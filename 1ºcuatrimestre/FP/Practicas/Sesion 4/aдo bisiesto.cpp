/*Cread un programa que lea el n�mero de un a�o e indique si es bisiesto o no. Un a�o
es bisiesto si es m�ltiplo de cuatro, pero no de cien. Excepci�n a la regla anterior son
los m�ltiplos de cuatrocientos que siempre son bisiestos*/

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
