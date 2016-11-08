
/* 
	Reajustar renta.

   * Bajar un 3% la retenci�n fiscal a los aut�nomos
   * Para los no aut�nomos:
      - Se sube un 1% la retenci�n fiscal a todos los pensionistas.
      - Al resto de trabajadores se le sube un 2% la retenci�n fiscal. 
		Una vez hecha esta subida lineal del 2 %, se le aplica 
		(sobre el resultado anterior) las siguientes subidas adicionales, 
		dependiendo de su estado civil y niveles de ingresos:
         1) Subir un 6% la retenci�n fiscal a las rentas de trabajo 
			inferiores a 20.000 euros
         2) Subir un 8% la retenci�n fiscal a los casados con rentas 
			de trabajo superiores a 20.000 euros
         3) Subir un 10% la retenci�n fiscal a los solteros con 
			rentas de trabajo superiores a 20.000 euros

	C�mputo de porcentajes de incremento (Matem�ticas de tercero de la ESO).

		Supongamos un producto cuyo precio es P.
		1)	Un incremento del 3%, por ejemplo, se traduce en que el precio 
			final del producto ser� 
			P+(P * 3/100) = P + 3P/100 = (100P + 3P)/100 = 103P/100 = 1.03*P
		2)	Una rebaja del 3%, por ejemplo, se traduce en que el precio final 
			del producto ser� 0.97*P 
		3)	La aplicaci�n sucesiva de incrementos supone ir multiplicando 
			sucesivamente los incrementos porcentuales.
		P.e. Si subimos un 3% y al resultado le aplicamos otra subida del 
		5%, el precio final es 1.03*1.05*P
		
		Entradas: 
			* Si la persona es un trabajador aut�nomo o no
			* Si es pensionista o no
			* Estado civil
			* Renta bruta (total de ingresos obtenidos)
			* Retenci�n 
		
*/
/*********************************************************************/

#include <iostream>
#include <cctype>
#include <iomanip> // Recursos para dar formato a la presentaci�n de datos 
using namespace std;

int main()
{
	const double INCR_AUTONOMO = 0.97; 	
	const double INCR_PENSIONISTA = 1.01;
	const double INCR_LINEAL = 1.02;	
	const double INCR_SALARIO_BAJO = 1.06;
	const double INCR_SALARIO_NORMAL_SOLTERO = 1.1;
	const double INCR_SALARIO_NORMAL_CASADO = 1.08;
	const double LIMITE_SALARIO_NORMAL = 20000;

	double	renta_bruta, renta_neta, 
			retencion_inicial, retencion_final, 
			porcentaje_modificacion;

	bool es_autonomo, es_soltero, es_pensionista;	

	// Lectura
	
	// Lectura de las propiedades binarias es_autonomo, 
	// es_pensionista y es_soltero. Observe c�mo se asigna 
	// el valor bool adecuado de manera indirecta
	
	char opcionSN;
	
	cout << "�Aut�nomo (S/N)? : "; 
	cin >> opcionSN;
	es_autonomo = (toupper(opcionSN) == 'S');

	cout << "�Pensionista (S/N)? : "; 
	cin >> opcionSN;
	es_pensionista = (toupper(opcionSN) == 'S');

	cout << "�Soltero (S/N)? : "; 
	cin >> opcionSN;
	es_soltero = (toupper(opcionSN) == 'S');
	
	// Lectura de valores num�ricos
	
	cout << "Retenci�n inicial : "; 
	cin >> retencion_inicial;
	
	cout << "Renta bruta : "; 
	cin >> renta_bruta;	
	

	// C�lculos
	
	if (es_autonomo)   
		porcentaje_modificacion = INCR_AUTONOMO;   

	else 
	
		if (es_pensionista)
			porcentaje_modificacion = INCR_PENSIONISTA;

		else { // Ni aut�nomo ni pensionista

      		porcentaje_modificacion = INCR_LINEAL;

      		if (renta_bruta < LIMITE_SALARIO_NORMAL)
         		porcentaje_modificacion = porcentaje_modificacion * 
								   INCR_SALARIO_BAJO;
								   
      		else // renta_bruta >= LIMITE_SALARIO_NORMAL
      		
				if (es_soltero)
         			porcentaje_modificacion = porcentaje_modificacion * 
								   INCR_SALARIO_NORMAL_SOLTERO;
      			else  
         			porcentaje_modificacion = porcentaje_modificacion * 
								   INCR_SALARIO_NORMAL_CASADO;
   }

	retencion_final = retencion_inicial * porcentaje_modificacion;
	renta_neta = renta_bruta * (1 - retencion_final /100.0);


	// Salida
	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	cout << endl << endl;

	cout << "Autonomo = ";
	if (es_autonomo) 
		cout << "SI";
	else  
		cout << "NO";
	cout << endl;

	cout << "Pensionista = ";
	if (es_pensionista) 
		cout << "SI";
	else  
		cout << "NO";
	cout << endl;

	cout << "Soltero = ";
	if (es_soltero) 
		cout << "SI";
	else  
		cout << "NO";
	cout << endl << endl;

	cout << "Retenci�n inicial = " << setw(6) << setprecision(2) 
						           << retencion_inicial << endl;
	cout << "Retenci�n final =   " << setw(6) << setprecision(2) 
						           << retencion_final << endl;
	cout << "Renta bruta = " << setw(10) << setprecision(2) 
		                     << renta_bruta << endl;
	cout << "Renta final = " << setw(10) << setprecision(2) 
						     << renta_neta;
	cout << "\n\n";

	return (0);
}

