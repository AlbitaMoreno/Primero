/*Programa que lleva la comtabilidad en una empresa. Calcula la ganancia total basandose
en una seri de condiciones:
       -tres fabricantes 
       -un dise�ador que cobra el doble que el fabricante
La variable ganancia ser� el dinero ganado por fabricante m�s el dise�ador
La variable dise�ador, lo que gana el dise�ador, ser� el doble de la ganancia.
Total ser� el percio del paquete.
       Dise�ador = 2*ganancia   Ganancia = total/3
*/       

#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    double ganancia;
    double disenador;
    double total;
    
    cout << "Introduzca el total: ";
    cin >> total;
    
    ganancia = total/3;
    
    cout << "\nEl fabricante gana: " << ganancia << "\n\n";
    
    disenador = 2*ganancia;
    
    cout << "\nEl dise�ador gana: " << disenador << "\n\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
