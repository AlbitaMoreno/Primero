/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// Examen de Febrero 2016
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/***************************************************************************/

const double PI = 3.1415926;

/***************************************************************************/
// Funci�n global (asociada a la constante PRECISION_SON_IGUALES) que
// permite que dos n�meros reales muy pr�ximos sean considerados iguales.

const double UMBRAL = 1e-5; // 0.00001

bool SonIguales(double uno, double otro)
{
	return (fabs(uno-otro) <= UMBRAL);
}


/////////////////////////////////////////////////////////////////////////////
// NOTA: La clase Punto2D que se adjunta proporciona m�s funcionalidad que la 
// que requiere el problema que se est� solucionando en este ejercicio. 

class Punto2D{
private:

	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x = 0;
	double y = 0;

public:

	/***********************************************************************/
	// Constructor sin argumentos.

	Punto2D (void)
	{ }

	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� creando.

	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// M�todo Set para fijar simultaneamente las coordenadas.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada,
	// respectivamente del punto que se est� modificando.

	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// M�todos Get para leer las coordenadas

	double GetX (void){
		return (x);
	}

	double GetY (void){
		return (y);
	}

	/***********************************************************************/
	// Calcula si dos puntos son iguales
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto impl�cito.
	// Devuelve: true, si se consideran iguales los dos objetos.

	bool EsIgual (Punto2D otro)
	{
		return (SonIguales(x,otro.x) && SonIguales(y,otro.y));
	}

	/***********************************************************************/
	// Calcula la distancia Eucl�dea del punto (objeto impl�cito) a otro que
	// se recibe como argumento.
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la
	// distancia eucl�dea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/***********************************************************************/
	// Devuelve un string con la representaci�n textual de un dato Punto2D
	
	string ToString ()
	{
		return ("["+to_string(x)+", "+to_string(y)+"]");
	}
	
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Un pol�gono regular tiene todos los lados de la misma longitud, y todos 
// los �ngulos interiores son iguales. Su centro geom�trico es el centro de 
// la circunferencia circunscrita (la que lo envuelve). 
// Supondremos que dos pol�gonos son distintos si se diferencian o bien en 
// sus centros geom�tricos, o bien en el n�mero de lados o bien en la longitud
// de cualquiera de ellos. As� pues, por ejemplo, no tendremos en cuenta las 
// distintas posiciones en el plano que se podr�an obtener girando el pol�gono 
// sobre su centro.

class PoligonoRegular{
 
private:
		
	Punto2D centro;     // Centro de la circunferencia circunscrita que encierra al pol�gono.
	Punto2D *vertices;
	int num_lados; 	// Num. de lados del pol�gono
	double 	longitud;   // Longitud de cada lado

public:
	
	/***********************************************************************/
	// Constructores
	/***********************************************************************/
	
	PoligonoRegular () 
	: centro (Punto2D(0.0,0.0)), num_lados(3), longitud(1), vertices(new Punto2D [3])
	{ }

	/***********************************************************************/

	PoligonoRegular (int el_numero_lados, double la_longitud_lado)
		: centro (Punto2D(0.0,0.0)),num_lados(el_numero_lados), longitud(la_longitud_lado), vertices(new Punto2D [el_numero_lados])
	{ }


	/***********************************************************************/

	PoligonoRegular(int el_numero_lados, double la_longitud_lado, Punto2D el_centro) 
		: centro (el_centro), num_lados(el_numero_lados), longitud(la_longitud_lado),vertices(new Punto2D [el_numero_lados])
	{ }

	/***********************************************************************/
	// M�todos de consulta directa
	/***********************************************************************/
	
	Punto2D GetCentro ()
	{
		return (centro);	
	}
	/***********************************************************************/

	double GetLongitud ()
	{
		return (longitud);	
	}
	
	/***********************************************************************/

	int GetNumLados ()
	{
		return (num_lados);	
	}
	
	int GetNumVertices(){
		return (num_lados);
	}

	/***********************************************************************/
	// M�todo de consulta indirecta
	/***********************************************************************/
	
	double GetRadio ()
	{
		return (longitud/(2.0*sin(PI/num_lados)));	
	}

	/***********************************************************************/
	// M�todos de c�lculo
	/***********************************************************************/
	
	double Perimetro ()
	{
		return (longitud*num_lados);	
	}
	
	/***********************************************************************/

	double Area ()
	{
		// M�todo 1:
		//		return (0.25*num_lados*longitud*longitud / tan(PI/num_lados));	

		// M�todo 2: 
		double radio = GetRadio ();
		return (0.5*num_lados*radio*radio*sin(2*PI/num_lados));					
	}

	//**********************************************************************//
				//metodo para borra los arrays dinamicos//
	//*********************************************************************//
	void Borra(){
		delete[] vertices;
	}
		
	/***********************************************************************/

	/***********************************************************************/
	// Otros m�todos
	/***********************************************************************/

	// Develve un nuevo pol�gono, inscrito en la misma circunferencia, 
	// pero multiplicando por un entero k el n�mero de lados.

	PoligonoRegular MultiplicaNumLados (int k)
	{
		PoligonoRegular nuevo (num_lados*k, NuevaLongitudLado(k), centro);
		return (nuevo);
	}
	
	/***********************************************************************/
	
	bool MayorQue (PoligonoRegular otro)
	{
		return (Area() > otro.Area());
	}
	
	/***********************************************************************/
	// Devuelve el �rea de la regi�n comprendida entre la circunferencia
 	// circunscrita y el pol�gono (en realidad, la suma de las �reas de
	// las num_lados regiones)

	double AreaEntreCircunferenciaYPoligono ()
	{
		double radio = GetRadio ();
		return (PI*radio*radio-Area());
	}

	/***********************************************************************/

	void Pinta (string msg)	
	{
		cout << "----------------------------------------------" << endl;
		cout << msg << endl;		
		cout << "----------------------------------------------" << endl;
		cout << "Centro     = " << GetCentro().ToString() << endl;
		cout << "Num. lados = " << setw(3) << GetNumLados() << endl;
		cout << "Longitud   = " << setw(10) << setprecision(8) 
		     << GetLongitud() << endl;
		cout << "Radio      = " << setw(10) << setprecision(8) 
		  	 << GetRadio() << endl;
		cout << endl;
		cout << "Area       = " << setw(10) << setprecision(8) 
			 << Area() << endl;
		cout << "Perimetro  = " << setw(10) << setprecision(8) 
			 << Perimetro()<< endl;
		cout << "Vertices   = " << setw(3) << GetNumVertices()<< endl; 			
		cout << "----------------------------------------------" << endl;
		cout << endl;
	}

	/***********************************************************************/

private:
		
	/***********************************************************************/
	// Devuelve la longitud del lado del nuevo poligono resultado de 
	// multiplicar por k el n�nero de lados. El radio sigue siendo el mismo 
	// porque el nuevo pol�gono est� inscrito en la misma circunferencia. 

	double NuevaLongitudLado (int k)
	{
		double radio = GetRadio();

		double nueva_longitud = radio * sqrt(2*(1-cos((2*PI)/(k*num_lados))));

		return (nueva_longitud);
	}
	
	/***********************************************************************/

};


/////////////////////////////////////////////////////////////////////////////



/***************************************************************************/

int main ()
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	

	// Constructor sin argumentos

	PoligonoRegular poligono1;
	
	poligono1.Pinta ("poligono1 - Poligono_por_defecto");
	
	
	// Constructor con dos argumentos

	PoligonoRegular poligono2 (6, 4);
	
	poligono2.Pinta ("poligono2 - Hexagono l=4");
	
	
	// Comparar �reas
	
	cout << endl;	
	if (poligono1.MayorQue(poligono2)) {
		cout << "poligono1 es mayor que poligono2"	<< endl;
	} 
	else {
		cout << "poligono2 es mayor que poligono1"	<< endl;		
	}
	cout << endl;		
	
	
	/***********************************************************************/
	// APROXIMACION A CIRCUNFERENCIA
	// Calcular el poligono que aproxima a una circunferencia a partir de
	// uno dado (en este caso un triangulo equil�tero de longitud 2)

	cout << "**************************************************" << endl;
	cout << "APROXIMACION A CIRCUNFERENCIA" << endl;
	cout << endl;
	cout << "Precision de la aproximacion = ";
	cout << setw(7) << setprecision(5) << UMBRAL << endl;
	cout << "**************************************************" << endl;
	cout << endl;
	
	
	// Lectura del factor de incremento del n�mero de lados
	 
	int k;
	
	do {		
		cout << "Factor multiplicador del numero de lados: ";
		cin >> k;
	} while (k<=1);

	
	// Crear pol�gono "p" a partir de "poligono1" (tri�ngulo de tres lados
	// de longitud 1) con la misma circunferencia circunscrita y con k veces
	// el n�mero de lados	

	PoligonoRegular p (poligono1.MultiplicaNumLados(k));


	p.Pinta ("p - Poligono inicial para la aproximacion");	



	// Calcular el �rea de la circunferencia circunscrita (�rea objetivo)

	double radio = p.GetRadio();
	double area_objetivo = PI * radio * radio;

	// Presentar datos iniciales de la aproximaci�n
	
	cout << endl;
	cout << "Calculando el poligono que aproxima a una circunferencia "
	     << "de radio " << radio << endl;
	cout << "Area de la circunferencia objetivo = "
		 << setw(10) << setprecision(8) << area_objetivo << endl;
	cout << endl;


	// Calcular el pol�gono que aproxima la circunferencia

	//	while (!SonIguales(p.Area(), area_objetivo)) {
	while (p.AreaEntreCircunferenciaYPoligono() > UMBRAL) {

		cout << "Lados = " << setw(5) << p.GetNumLados()
		     << " Area = " << setw(10) << setprecision(8) << p.Area();
	//		cout << " Dif  = " << setw(10) << setprecision(8)
	//		     << area_objetivo - p.Area() << endl;
	cout << " Dif  = " << setw(10) << setprecision(8)
	     <<p.AreaEntreCircunferenciaYPoligono() << endl;

		// Calcular nuevo poligono
		
		p = p.MultiplicaNumLados(k);
	}

	// Presentar resultado
	
	cout << endl;
	cout << "POLIGONO RESULTADO: " << endl;
	cout << "Lados = " << setw(5) << p.GetNumLados()
		 << " Area = " << setw(10) << setprecision(8) << p.Area();
	//	cout << " Dif  = " << setw(10) << setprecision(8)
	//	     << area_objetivo - p.Area() << endl;
	cout << " Dif  = " << setw(10) << setprecision(8)
	     <<p.AreaEntreCircunferenciaYPoligono() << endl;
	cout << endl << endl;
	
	
	     
	p.Pinta ("p - Poligono resultado de la aproximacion");

	// El per�metro del pol�gono que aproxima a la circunferencia 
	//  circunscrita debe ser similar a la longitud de dicha circunferenca.
	
	cout << endl;
	cout << "La longitud de la circunf. circunscrita es   " 
		 << setw(10) << setprecision(8) << 2*PI*p.GetRadio() << endl;
	cout << "El perimetro del poligono que la aproxima es " 
	     << setw(10) << setprecision(8) << p.Perimetro() << endl;
	cout << endl;
	
	//borro los arrays con los vertices una vez acabo las operaciones
	poligono1.Borra();
	p.Borra();

	return (0);
}

/***************************************************************************/
