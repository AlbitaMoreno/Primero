/* b) Supongamos que se aplica una retenci�n fiscal y que �sta es la misma para
los fabricantes y el dise�ador. En el constructor se establecer� el porcentaje de
retenci�n fiscal (de tipo double) y posteriormente no se permitir� que cambie, de
forma que todas las operaciones que se hagan ser�n siempre usando la misma
retenci�n fiscal. Los salarios netos se obtienen al aplicar la retenci�n fiscal a los
salarios brutos (despu�s de repartir los ingresos totales de la empresa):

salario_neto = salario_bruto - salario_bruto * retencion_fiscal / 100.0

El programa leer� el valor de los ingresos totales y la retenci�n fiscal a aplicar y
calcular� los salarios brutos y netos de los fabricantes y dise�ador, llamando a
los m�todos oportunos de la clase Nomina.*/

#include <iostream>
using namespace std;

class Nomina{
	private:
		double ingreso_total;
		const double RETENCION_FISCAL;
		bool Ingr_negativo(double ingreso_total){
		
			bool ingr_negativo = (ingreso_total < 0);
			return ingr_negativo;
		}
   public:
		Nomina(double retencion_fiscal)
			:RETENCION_FISCAL(retencion_fiscal){
				ingreso_total = 0;
				retencion_fiscal = 0;
			}
		
		void SetNomina(double ingresos_totales, double retencion) {
			if(Ingr_negativo(ingreso_total)){
				ingreso_total = 0;
			}
			else{
				retencion_fiscal = retencion;
				ingreso_total = ingresos_totales - (ingresos_tales * retencion / 100.0);
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
	double disenador;
	double fabricante;
	double ingreso_total;
	double retencion;
	
	cout << "\nIntroduzca el total de ingresos: ";
	cin >> ingreso_total;
	cout << "\nIntroduzca la retencion a tener en cuenta: ";
	cin >> retencion;
	Nomina ingreso(retencion_fiscal);
	ingreso.SetNomina(ingresos_totales, retencion);
	
	disenador = ingreso.GetDisenador();
	fabricante = ingreso.GetFabricante();
	
	cout << "\nEl sueldo del disenador es: " << disenador << "\n";
	cout << "\nEl sueldo del fabricante es: " << fabricante << "\n";
}
