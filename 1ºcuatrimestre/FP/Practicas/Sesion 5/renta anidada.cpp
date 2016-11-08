
/* Cread un programa que lea los datos fiscales da una persona, reajuste su renta bruta
seg�n el criterio que se indica posteriormente e imprima su renta neta final.

 La renta bruta es la cantidad de dinero �ntegra que el trabajador gana.
 La renta neta es la cantidad que le queda despu�s de quitarle el porcentaje de
retenci�n fiscal, es decir:
Renta_neta = Renta_bruta - Renta_bruta * Retenci�n / 100

Los datos a leer son:
 Si la persona es un trabajador aut�nomo o no
 Si es pensionista o no
 Estado civil
 Renta bruta (total de ingresos obtenidos)
 Retenci�n inicial a aplicar

La modificaci�n se har� de la siguiente forma:
 Se baja un 3% la retenci�n fiscal a los aut�nomos

 Para los no aut�nomos:
� Se sube un 1% la retenci�n fiscal a todos los pensionistas.
� Al resto de trabajadores se le sube un 2% la retenci�n fiscal. Una vez hecha
esta subida lineal del 2 %, se le aplica (sobre el resultado anterior) las
siguientes subidas adicionales, dependiendo de su estado civil y niveles de
ingresos:

 Se sube un 6% la retenci�n fiscal si la renta bruta es menor de 20.000
euros
 Se sube un 8% la retenci�n fiscal a los casados con renta bruta superior
a 20.000 euros
 Se sube un 10% la retenci�n fiscal a los solteros con renta bruta superior
a 20.000 euros

Nota: Cuando se pide subir un x% la retenci�n fiscal, significa que la nueva retenci�n
fiscal ser� la antigua m�s el resultado de realizar el x% sobre la antigua retenci�n.

Nueva_retenci�n = Antigua_retenci�n + Antigua_retenci�n * x / 100
De forma an�loga, si se le baja la retenci�n, habr� que restar en vez de sumar.
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
	autonomo = (tolower(autonomo_letra) == 's'); 	//Convierte la letra introducida en min�scula y asigna true a la variable si es "s" min�scula.
	
	if(autonomo)			//En caso de que sea autonomo no es preciso realizar el resto de c�lculos.
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
			retencion_basica = retencion_basica+retencion_basica*2/100;		//Este c�lculo aplica el incremento lineal.
			
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
