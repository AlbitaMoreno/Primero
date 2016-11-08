/* Se quiere construir una clase DepositoSimulacion para simular préstamos, ofreciendo
la funcionalidad descrita en los ejercicios 15 (reinvierte capital e interés un
número de años) y 16 (reinvierte capital e interés hasta obtener el doble de la cantidad
inicial) de la relación de problemas II (página RP-II.7). Por tanto, la clase debe
proporcionar, para un capital y unos intereses dados, métodos para:

a) Calcular el capital que se obtendrá al cabo de un número de años,
b) Calcular el número de años que deben pasar hasta obtener el doble de la cantidad
inicial.

A la hora de diseñar la clase, tendremos que analizar cuestiones como:

 ¿Cuáles son sus datos miembro? Parece claro que el capital y el interés sí lo
serán ya que cualquier operación que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. ¿Pero y el número
de años?
 ¿Qué constructor definimos?
 ¿Queremos modificar el capital y el interés una vez creado el objeto?
 ¿Queremos poder modificarlos de forma independiente?
 ¿Hay alguna restricción a la hora de asignar un valor al capital e interés?
 ¿Es mejor un método para calcular el número de años hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un método para calcular el número
de años hasta obtener una cantidad específica?*/

#include <iostream>
using namespace std;

class DepositoSimulacion{
	private:
		int anio;
		double capital;
		double interes;
		bool Capi_inte_anio(int anio, double capital, double interes){ 		//Precognición, ni el capital ni el interes ni los años pueden ser menores que cero
			bool Capi_inte_anio = true;
			Capi_inte_anio = (capital > 0 && anio > 0 && interes > 0);		// booleana true si los tres miembros son mayores de cero.	
		}
	
	public:
		DepositoSimulacion(){
			anio = capital = interes = 0;
		}	
		void SetDeposito(double anio1, double capital_inicio, double interes_inicio){
			
			if(Capi_inte_anio(anio1,capital_inicio,interes_inicio)){			//si la precgnicion no se cumple se muestra una indeterminacion en el main.
				anio = anio1;
				capital = capital_inicio;
				interes = interes_inicio;
			}
			else{
				anio = capital = interes = 0;
			}
		}
		int HallarAniosCapi(){
			int i = 0;
			double capital2;
			
			capital2 = capital;
			do			
			{		
				capital2 = (capital2 + (capital2 * interes) / 100);		
				i++;	
																			//i incrementa en 1 hasta que se cumpla el while.						
			}while(capital2 < 2 * capital);	
			
			return i;	
		}
		double HallarCapiAnios(){
			int i;
			
			for(i = 0; anio > i; i++){
				
				capital = (capital + (capital * interes) / 100);
			}
			return capital;
		}
};

int main(){
	DepositoSimulacion capital;
	int anio;
	double capital1;
	double interes;
	int anio_capi;
	double capi_anio;
	
	cout << "\nIntroduzca el capital incial: ";
	cin >> capital1;
	cout <<"\nIntroduzca el interes inicial: ";
	cin >> interes;
	cout << "\nAnios invirtiendo " << capital1 << " € a un interes " << interes << " : ";
	cin >> anio;
	capital.SetDeposito(anio,capital1,interes);
	
	capi_anio = capital.HallarCapiAnios();
	anio_capi = capital.HallarAniosCapi();
		
	cout << "\n\nTranscurridos " << anio << " anios el capital sera de " << capi_anio;
	cout << "\nPara doblar el capital, haran falta " << anio_capi << " anios.";
	
}
