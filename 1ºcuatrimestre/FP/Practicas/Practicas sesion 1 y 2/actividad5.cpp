/*Programa que lleva la comtabilidad en una empresa. Calcula la ganancia total basandose
en una seri de condiciones:
       -tres fabricantes 
       -un diseñador que cobra el doble que el fabricante
La variable ganancia será el dinero ganado por fabricante más el diseñador
La variable diseñador, lo que gana el diseñador, será el doble de la ganancia.
Total será el percio del paquete.
       Diseñador = 2*ganancia   Ganancia = total/3
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
    
    cout << "\nEl diseñador gana: " << disenador << "\n\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
