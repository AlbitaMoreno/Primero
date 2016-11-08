
/* Cread un programa que lea los datos fiscales da una persona, reajuste su renta bruta
según el criterio que se indica posteriormente e imprima su renta neta final.

 La renta bruta es la cantidad de dinero íntegra que el trabajador gana.
 La renta neta es la cantidad que le queda después de quitarle el porcentaje de
retención fiscal, es decir:
Renta_neta = Renta_bruta - Renta_bruta * Retención / 100

Los datos a leer son:
 Si la persona es un trabajador autónomo o no
 Si es pensionista o no
 Estado civil
 Renta bruta (total de ingresos obtenidos)
 Retención inicial a aplicar

La modificación se hará de la siguiente forma:
 Se baja un 3% la retención fiscal a los autónomos

 Para los no autónomos:
– Se sube un 1% la retención fiscal a todos los pensionistas.
– Al resto de trabajadores se le sube un 2% la retención fiscal. Una vez hecha
esta subida lineal del 2 %, se le aplica (sobre el resultado anterior) las
siguientes subidas adicionales, dependiendo de su estado civil y niveles de
ingresos:

 Se sube un 6% la retención fiscal si la renta bruta es menor de 20.000
euros
 Se sube un 8% la retención fiscal a los casados con renta bruta superior
a 20.000 euros
 Se sube un 10% la retención fiscal a los solteros con renta bruta superior
a 20.000 euros

Nota: Cuando se pide subir un x% la retención fiscal, significa que la nueva retención
fiscal será la antigua más el resultado de realizar el x% sobre la antigua retención.

Nueva_retención = Antigua_retención + Antigua_retención * x / 100
De forma análoga, si se le baja la retención, habrá que restar en vez de sumar.
*/

#include <iostream>
#include <cctype>

using namespace std;

int main(){
	double renta_bruta;
	double retencion;	
	double retencion_basica;				
	bool autonomo;
	bool pensionista; 
	bool est_civil;
	char autonomo_letra;
	char pensionista_letra;
	char est_civil_letra;
	
	cout << "\nIntroduzca renta: ";
	cin >> renta_bruta;	
	cout << "\nIntroduzca la retencion incial: ";
	cin >> retencion;	
	retencion_basica = renta_bruta * retencion/ 100;			
	cout << "\nEs autonomo (s/n): ";
	cin >> autonomo_letra;
	autonomo = (tolower(autonomo_letra) == 's'); 	//Convierte la letra introducida en minúscula y asigna true a la variable si es "s" minúscula.
	
	if(autonomo)			//En caso de que sea autonomo no es preciso realizar el resto de cálculos.
	{
		retencion_basica = retencion_basica-retencion_basica*3/100;		
	}
	else 			
	{
		cout << "\nEs pensionista (s/n): ";
		cin >> pensionista_letra;
		pensionista = (tolower(pensionista_letra) == 's');
		
		if(pensionista)
		{
			retencion_basica = retencion_basica-retencion_basica*1/100;					//Si se da que pensionista es true se aplica el retencion = 1 en el calculo final.
		}
		else
		{
			retencion_basica = retencion_basica+retencion_basica*2/100;		//Este cálculo aplica el incremento lineal.
			
			if(renta_bruta < 20000)
			{
				retencion_basica = retencion_basica+retencion_basica*6/100;
			}
			else
			{
				cout << "\nEsta casado(s/n): ";
				cin >> est_civil_letra;
				est_civil = (tolower(est_civil_letra) == 's');
				
				if(est_civil)
				{
					retencion_basica = retencion_basica+retencion_basica*8/100;
				}
				else
				{
					retencion_basica = retencion_basica+retencion_basica*10/100;
				}
			}
		}
	}
	
	cout << "\nLa renta neta final es: " << renta_bruta-retencion_basica << "\n\n";
}
