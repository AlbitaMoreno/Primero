/*Escribir una expresi�n l�gica que sea verdadera si hay la edada queda comprendida entre 18 y 65*/
/*Expresi�n logica para comprobar si el numero introducido esta comprendido entre */
#include <iostream>

using namespace std;

int main(){
    int edad;
    
    cout << "\n\nIntroduzca la edad: ";
    cin >> edad;
    cout << "\n\tLa edad introducida es: " << edad << "\n\n";
    
// el condicional if compara si el n�mero entero que introducimos est� entre los 18 y los 65
    if(edad >=18 and edad <= 65)
    {
         cout << "\n\tLa edad introducida esta en el rango comprendido" "\n\n";
}

// si la condici�n no se cumple, entonces se ejecuta else y nos saldr� un mensaje en pantalla 
//que nos dir� que el n�mero no es v�lido.
    
    else
    {
        cout << "\n\tLa edad no es valida" "\n\n";
    }
        
}



    
   
    
