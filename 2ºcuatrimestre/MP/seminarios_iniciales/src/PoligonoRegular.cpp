/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Examen de Febrero 2016
//
// Fichero: PoligonoRegular.cpp
// Definición de la clase PoligonoRegular
//
/***************************************************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "utils.h"
#include "Punto2D.h"
#include "PoligonoRegular.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Métodos de la clase PoligonoRegular

/***********************************************************************/
// Constructores
/***********************************************************************/

PoligonoRegular :: PoligonoRegular ()
                 : centro (Punto2D(0.0,0.0)),
				   num_lados(3),
				   longitud(1)
{ }

/***********************************************************************/

PoligonoRegular :: PoligonoRegular (int el_numero_lados,
								    double la_longitud_lado)
				 : centro (Punto2D(0.0,0.0)),
			  	   num_lados(el_numero_lados),
				   longitud(la_longitud_lado)
{ }


/***********************************************************************/

PoligonoRegular :: PoligonoRegular (int el_numero_lados,
								    double la_longitud_lado,
									Punto2D el_centro)
				 : centro (el_centro),
			       num_lados(el_numero_lados),
				   longitud(la_longitud_lado)
{ }

/***********************************************************************/
// Métodos de consulta directa
/***********************************************************************/

Punto2D PoligonoRegular :: GetCentro ()
{
	return (centro);
}
/***********************************************************************/

double PoligonoRegular :: GetLongitud ()
{
	return (longitud);
}

/***********************************************************************/

int PoligonoRegular :: GetNumLados ()
{
	return (num_lados);
}

/***********************************************************************/
// Método de consulta indirecta
/***********************************************************************/

double PoligonoRegular :: GetRadio ()
{
	return (longitud/(2.0*sin(PI/num_lados)));
}

/***********************************************************************/
// Métodos de cálculo
/***********************************************************************/

double PoligonoRegular :: Perimetro ()
{
	return (longitud*num_lados);
}

/***********************************************************************/

double PoligonoRegular :: Area ()
{
	// Método 1:
	//		return (0.25*num_lados*longitud*longitud / tan(PI/num_lados));

	// Método 2:
	double radio = GetRadio ();
	return (0.5*num_lados*radio*radio*sin(2*PI/num_lados));
}

/***********************************************************************/

/***********************************************************************/
// Otros métodos
/***********************************************************************/

// Develve un nuevo polígono, inscrito en la misma circunferencia,
// pero multiplicando por un entero k el número de lados.

PoligonoRegular PoligonoRegular :: MultiplicaNumLados (int k)
{
	PoligonoRegular nuevo (num_lados*k, NuevaLongitudLado(k), centro);
	return (nuevo);
}

/***********************************************************************/

bool PoligonoRegular :: MayorQue (PoligonoRegular otro)
{
	return (Area() > otro.Area());
}

/***********************************************************************/
// Devuelve el área de la región comprendida entre la circunferencia
// circunscrita y el polígono (en realidad, la suma de las áreas de
// las num_lados regiones)

double PoligonoRegular :: AreaEntreCircunferenciaYPoligono ()
{
	double radio = GetRadio ();
	return (PI*radio*radio-Area());
}

/***********************************************************************/
// Muestra un polígono regular

void PoligonoRegular :: Pinta (string msg)
{
	string linea ="----------------------------------------------";

	cout << linea << endl;
	cout << msg << endl;
	cout << linea << endl;
// setw() esplaza lo que se va a sacar por pantalla n unidades hacia la derecha	
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
	cout << linea << endl;
	cout << endl;
}


/***********************************************************************/
// Métodos private
/***********************************************************************/

/***********************************************************************/
// Devuelve la longitud del lado del nuevo poligono resultado de
// multiplicar por k el núnero de lados. El radio sigue siendo el mismo
// porque el nuevo polígono está inscrito en la misma circunferencia.

double PoligonoRegular :: NuevaLongitudLado (int k)
{
	double radio = GetRadio();

	double nueva_longitud = radio * sqrt(2*(1-cos((2*PI)/(k*num_lados))));

	return (nueva_longitud);
}

/***********************************************************************/

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
