/*Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con
tres números, el identificador de la sucursal (1,2 ó 3), el código del producto codificado
como un carácter (a, b ó c) y el número de unidades vendidas. Diseñar
un programa que lea desde el teclado una serie de registros compuestos por
sucursal, producto, unidades y diga cuál es la sucursal que más productos
ha vendido. La serie de datos termina cuando la sucursal introducida vale -1.
*/

#include <iostream>

using namespace std;

int main()
{
	int suc;
	char prod;
	double unid;
	double unid_1 = 0; 		//contador unidad1
	double unid_2 = 0; 		//contador unidad2
	double unid_3 = 0;
	
	cout << "\nEl programa finalizara si se introduce sucursal = -1\n";
	
	do
	{
		cout << "\nIntroduzca la sucursal (1,2,3): ";
		cin >> suc;
		cout << "\nIntroduzca el producto (a,b,c): ";
		cin >> prod;
		cout << "\nIntroduzca el numero de unidades: ";
		cin >> unid;
		
		if(suc == 1)
		{
			unid_1 = unid_1 + unid;
		}
		if(suc == 2)
		{
			unid_2 = unid_2 + unid;
		}
		else
		{
			unid_3 = unid_3 + unid;
		}
		cout << suc << prod << unid;
				
	}while((suc >= 1 && suc <= 3) && (prod == 'a' || prod == 'b' || prod == 'c') && (unid > 0));
	
	if(unid_1 < unid_2 && unid_2 < unid_3)
	{
		cout << "\nLa sucursal que más a vendido es 3 con : " << unid_3; 
	}
	else
	{
		cout << "\nLa sucursal que más a vendido es 1 con: " << unid_1;
	}
	if(unid_1 < unid_2 && unid_2 > unid_3)
	{
		cout << "\nLa sucursal que mas a vendido es 2 con: " << unid_2;
	}
}
