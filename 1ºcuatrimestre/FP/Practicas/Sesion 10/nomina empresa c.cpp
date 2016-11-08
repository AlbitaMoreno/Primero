/* c) Supongamos que gestionamos las n�minas de varias sucursales de una empresa.
Queremos crear objetos de la clase Nomina que se adapten a las caracter�sticas
de cada sucursal:

 En cada sucursal hay un �nico dise�ador pero el n�mero de fabricantes es
distinto en cada sucursal. Por tanto, el n�mero de fabricantes habr� que especificarlo
en el constructor y posteriormente no podr� cambiarse.

 La forma de repartir el dinero es la siguiente: el dise�ador se lleva una parte
del total y el resto se reparte a partes iguales entre los fabricantes. En los
apartados anteriores, por ejemplo, la parte que se llevaba el dise�ador era
2/5 y el resto (3/5) se repart�a entre los tres fabricantes. La parte que el dise�ador
se lleva puede ser distinta entre las distintas sucursales (2/5, 1/6,
etc), pero no cambia nunca dentro de una misma sucursal. Por tanto, el porcentaje
de ganancia (2/5, 1/6, etc) habr� que especificarlo en el constructor
y posteriormente no podr� cambiarse.

 Las retenciones fiscales de los fabricantes y dise�ador son distintas. Adem�s,
se prev� que �stas puedan ir cambiando durante la ejecuci�n del programa.
Por lo tanto, no se incluir�n como par�metros en el constructor.

El programa leer� los siguientes datos desde un fichero externo:
 El n�mero de sucursales.

 Los siguientes valores por cada una de las sucursales:
� Ingresos totales a repartir
� N�mero de fabricantes
� Parte que se lleva el dise�ador
� Retenci�n fiscal del dise�ador
� Retenci�n fiscal de los fabricantes
*/

#include <iostream>
using namespace std;

class Nomina{
	private:
		double ingreso_total;
		double retencion_disenador;
		double retencion_fabricantes;
		const int TRABAJADORES;
		bool Ingr_negativo(double ingreso_total){
			bool ingr_negativo = (ingreso_total < 0);
			return ingr_negativo;
		}
   public:
		Nomina(int fabricante)
		:TRABAJADORES(fabricante)
		{
			ingreso_total = 0;
			retencion_disenador = 0;
			retencion_fabricantes = 0;
		}		
		void SetNomina(double ingresos_totales, double retencion_dise, double retencion_fabri){
			if(Ingr_negativo(ingreso_total)){
				ingreso_total = 0;
			}
			else{
				ingreso_total = ingresos_totales;
				retencion_disenador = retencion_dise;
				retencion_fabricantes = retencion_fabri;
			}
		}    	
    	double GetDisenador(){
    		double ganancia = 0;
    		
			ganancia = (ingreso_total - (ingreso_total * retencion_disenador / 100.0) )* (1 / TRABAJADORES) ;		//habra un dise�ador por sucursal 
    		return ganancia;
    	}
    	double GetFabricante(){
    		double fabricante = 0;
    		
    		fabricante = (ingreso_total - (ingreso_total * retencion_fabricantes / 100.0) ) / TRABAJADORES;
    		return fabricante;
    	}
};		

int main(){
	int numero;
	double ingreso_total;
	double fabricantes;
	double disenador;
	double retenc_dise;
	double retenc_fabri;
	double total1;
	double total2;
	int i;
	
	do{
		cout << "\nIntroduzca el numero de sucursales: ";
		cin >> numero;
	}while(numero <= 0);
	
	for(i = 1; i <= numero + 1; i++){			//Las variables creadas en cuerpo del for, se reescriben cada vez que el for inicia un ciclo.
				
		cout << "\nIntroduzca las caracteristicas de la sucursal n�:  " << i << " \n";
		cout << "\nIntroduzca el ingreso total: ";		
		cin >> ingreso_total;
				
		cout << "\nCantidad de fabricantes: ";
		cin >> fabricantes;		
		
		cout << "\nIntroduzca la retencion del dise�ador: ";
		cin >> retenc_dise;
		
		cout << "\nIntroduzca la retencion de los fabricantes: ";
		cin >> retenc_fabri;
		
		Nomina sucursal(fabricantes);
		sucursal.SetNomina(ingreso_total, retenc_dise, retenc_fabri);
		
		total2 = sucursal.GetDisenador();
		total1 = sucursal.GetFabricante();
		
		cout << "\nCada fabricante gana " << total1 << " euros y el disenador obtiene " << total2 << " euros\n";
	}	
}
