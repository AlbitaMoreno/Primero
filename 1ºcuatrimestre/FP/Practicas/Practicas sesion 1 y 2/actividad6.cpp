/*El programa intercambia el contenido de dos variables enteras. 
De modo que edad Pedro = edad Juan
*/

#include <iostream>

using namespace std;

int main(){
    double edad_pedro;                                           //El codigo no funciona ya porque las edades que nos van a salir únicamente 
    double edad_juan;                                           //dependeran del valor que tome la edad_juan
    
    cout << "La edad de Juan es: ";
    cin >> edad_juan;
    cout << "La edad de Pedro es: ";
    cin >> edad_pedro;
        
    edad_juan = edad_pedro;
    
    cout << "\nLa edad de Juan es: " << edad_juan << "\n\n";
    
    edad_pedro = edad_juan;
    
    cout << "\nLa edad de Pedro es: " << edad_pedro << "\n\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
