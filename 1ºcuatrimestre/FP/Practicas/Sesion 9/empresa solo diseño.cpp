/*Recuperad la solución del ejercicio 11 de la Relación de Problemas II (Empresa). Reescribid
el programa principal usando una clase Ventas para gestionar los cómputos
de las ventas realizadas. Únicamente se pide que se indiquen las cabeceras de los
métodos públicos de la clase y las llamadas a éstos en el programa principal. No hay
que implementar ninguno de los métodos.
El programa principal sería de la siguiente forma:

cin >> identif_sucursal;
fichero_vacio = identif_sucursal == TERMINADOR;

if (!fichero_vacio){
	while (identif_sucursal != TERMINADOR){
		cin >> cod_producto;
		cin >> unidades_vendidas;
		
			--> Actualiza el número de unidades
			vendidas de la sucursal leida
		
			cin >> identif_sucursal;
	}
	
	--> Obtener el identificador y el número de ventas
	de la sucursal ganadora
}
*/

#include <iostream>
using namespace std;

class Ventas{
	private: 
		int identif_suc;
		char cod_suc;
		int unid_vendidas;
		int sucursal;
		int ventas;
		char codigo;
		bool Compventas(int identif_suc, char cod_suc, int unid_vendidas){
				bool compventa;
				compventa = unid_vendidas > ventas;			//Las unidades vendidas son superiores a 0
				return compventa;
		}
		
	public:
		Ventas(){
			identif_suc = 1;
			cod_suc = 'a';
			unid_vendidas = 0;
			sucursal = 1;
			codigo = 'a';
			ventas = 0;
		}
		void SetVenta(int identificador, char codig, int unid_vend){
				identif_suc = identificador;
				cod_suc = codig;
				unid_vendidas = unid_vend;
			
				if(Compventas(identificador, codig, unid_vend)){
					sucursal = identificador;
					codigo = codig;
					ventas = unid_vend;	
				}
		}
		int SetSucursal(){
			return sucursal;
		}	
		char SetCodigo(){
			return codigo;
		}
		int SetVentas(){
			return ventas;
		}
};

int main(){
	Ventas lista_venta;
	int identif_suc;
	char cod_suc;
	int unid_vendidas;
	int sucursal;
	int ventas;
	char codigo;
	bool dato_correcto;
	bool sin_dato;
	
	cout << "\nPara salir del bucle pulse -1\n";
	
	do{
		cout << "\nIntroduzca el identificador de la sucursal (1,2,3)--> ";
		cin >> identif_suc;
		dato_correcto = identif_suc != -1;			//Si se introduce -1 no pide ni el codigo ni las unidades vendidas
		if(dato_correcto){
			cout << "\nIntroduzca el codigo del producto (a,b,c)--> ";
			cin >> cod_suc;
			cout << "\nIntroduzca el numero de unidades vendidas--> ";
			cin >> unid_vendidas;
			lista_venta.SetVenta(identif_suc, cod_suc, unid_vendidas);
		}
	}while(dato_correcto);
	
	sin_dato = (ventas == 0);		//se hayan estado metiendo sucursales y codigos pero no numero de unidades.
	
	if(sin_dato){			
		cout << "\n\nNo ha introducido ninguna unidad";
	}
	else{					// para ver la sucursar que mas ha vendido, almacenamos los valores de los maximo en ventas, y vamos comprando en el metodo.
		sucursal = lista_venta.SetSucursal();
		codigo = lista_venta.SetCodigo();
		ventas = lista_venta.SetVentas();
		cout << "\n\nLa sucursal que mas ha vendido es la sucursal numero " << sucursal << " que \nha vendido " << ventas << " ";	
	}
}
