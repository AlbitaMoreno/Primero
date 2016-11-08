/*Se quiere construir una clase Nomina para realizar la funcionalidad descrita en el
ejercicio 12 de la relaci�n de problemas I sobre la n�mina del fabricante y dise�ador
(p�gina RP-I.5). Cread los siguientes programas (entregad un fichero por cada uno de
los apartados):

a) Suponed que s�lo gestionamos la n�mina de una empresa en la que hay un fabricante
y tres dise�adores. Los salarios brutos se obtienen al repartir los ingresos
de la empresa, de forma que el dise�ador cobra el doble de cada fabricante.
El programa leer� el valor de los ingresos totales y calcular� los salarios brutos
de los fabricantes y dise�ador, llamando a los m�todos oportunos de la clase
Nomina.
*/
#include <iostream>
using namespace std;

class Nomina{
	private:
		double ingreso_total;
		bool Ingr_negativo(double ingreso_total){
		
			bool ingr_negativo = (ingreso_total < 0);
			return ingr_negativo;
		}
   public:
		Nomina(){
			ingreso_total = 0;
		}
		void SetNomina(double ingresos_totales, ) {
			if(Ingr_negativo(ingreso_total)){
				ingreso_total = 0;
			}
			else{
				ingreso_total = ingresos_totales;
			}
		} 	    	
    	double GetDisenador(){
    		double ganancia;
    		double disenador;
    		
    		ganancia = ingreso_total / 5;
    		disenador = 2 * ganancia;
    		return disenador;
    	}
    	double GetFabricante(){
    		double fabricante;
    		
    		fabricante = ingreso_total / 5;
    		return fabricante;
    	}
};		

int main(){
	Nomina ingreso;
	double disenador;
	double fabricante;
	double ingreso_total;
	
	cout << "\nIntroduzca el total de ingresos: ";
	cin >> ingreso_total;
	ingreso.SetNomina(ingreso_total);
	
	disenador = ingreso.GetDisenador();
	fabricante = ingreso.GetFabricante();
	
	cout << "\nEl sueldo del disenador es: " << disenador << "\n";
	cout << "\nEl sueldo del fabricante es: " << fabricante << "\n";
}		
