/* Se quiere construir una clase DepositoSimulacion para simular pr�stamos, ofreciendo
la funcionalidad descrita en los ejercicios 15 (reinvierte capital e inter�s un
n�mero de a�os) y 16 (reinvierte capital e inter�s hasta obtener el doble de la cantidad
inicial) de la relaci�n de problemas II (p�gina RP-II.7). Por tanto, la clase debe
proporcionar, para un capital y unos intereses dados, m�todos para:

a) Calcular el capital que se obtendr� al cabo de un n�mero de a�os,
b) Calcular el n�mero de a�os que deben pasar hasta obtener el doble de la cantidad
inicial.

A la hora de dise�ar la clase, tendremos que analizar cuestiones como:

 �Cu�les son sus datos miembro? Parece claro que el capital y el inter�s s� lo
ser�n ya que cualquier operaci�n que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. �Pero y el n�mero
de a�os?
 �Qu� constructor definimos?
 �Queremos modificar el capital y el inter�s una vez creado el objeto?
 �Queremos poder modificarlos de forma independiente?
 �Hay alguna restricci�n a la hora de asignar un valor al capital e inter�s?
 �Es mejor un m�todo para calcular el n�mero de a�os hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un m�todo para calcular el n�mero
de a�os hasta obtener una cantidad espec�fica?*/

#include <iostream>
using namespace std;

class DepositoSimulacion{
	private:
		int anio;
		double capital;
		double interes;
		bool Capi_inte_anio(int anio, double capital, double interes){ 		//Precognici�n, ni el capital ni el interes ni los a�os pueden ser menores que cero
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
	cout << "\nAnios invirtiendo " << capital1 << " � a un interes " << interes << " : ";
	cin >> anio;
	capital.SetDeposito(anio,capital1,interes);
	
	capi_anio = capital.HallarCapiAnios();
	anio_capi = capital.HallarAniosCapi();
		
	cout << "\n\nTranscurridos " << anio << " anios el capital sera de " << capi_anio;
	cout << "\nPara doblar el capital, haran falta " << anio_capi << " anios.";
	
}
