/*Cread una funci�n que calcule el m�ximo entre tres double. La cabecera de la funci�n
ser� la siguiente:

double Max(double un_valor, double otro_valor, double el_tercero)

Construid un programa principal que llame a dicha funci�n con unos valores le�dos
desde teclado. Supongamos que dichos valores los leemos con cin dentro de la propia
funci�n, en vez de hacerlo en el main. El suspenso est� garantizado �Por qu�? */

//El suspenso est� garantizado porque cada funci�n tiene sus propios datos (par�metros formales
// y datos locales) y no se conocen en ning�n otro sitio, ya que, los nombres dados a los par�metros formales pueden coincidir
//con los nombres de los par�metros actuales pero son variables distintas.


#include <iostream>

using namespace std;

double Max(double num1, double num2, double num3)
{
	double mayor;
	
	if(num1 <= num2 && num2 <= num3)
	{
		mayor = num3;
	}
	else
	{
		mayor = num1;
	}
	if(num1 <= num2 && num2 >= num3)
	{
		mayor = num2;
	}
	
	return mayor;		//devuelve el mayor de los tres numeros
}
	
int main()
{
	double num1;
	double num2;
	double num3;
	double resultado;
	
	cout << "\nIntroduzca el primero numero: ";
	cin >> num1;
	cout << "\nIntroduzca el segundo numero: ";
	cin >> num2;
	cout << "\nIntroduzca el tercer numero: ";
	cin >> num3;
	
	resultado = Max(num1, num2, num3);		//tienen que ir en el mismo orden que en la funci�n, ya que si fuesen de tipo diferente y 
														//las pusiesemos desordenadas saldr�a un resultado err�neo.
	cout << "\nEl maximo de los tres valores es: " << resultado << "\n";
}
