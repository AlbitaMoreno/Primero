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
// Fichero: main.cpp
// Función main
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "utils.h"
#include "PoligonoRegular.h"

using namespace std;

//***************************************************************************/

int main ()
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales


	// Constructor sin argumentos --> Triángulo equilátero de lado 1
	// 								  centrado en (0,0)
	PoligonoRegular poligono1;

	poligono1.Pinta ("poligono1 - Poligono_por_defecto");


	// Constructor con dos argumentos --> Hexágono equilátero de lado 4
	//   								  centrado en (0,0)

	PoligonoRegular poligono2 (6, 4);

	poligono2.Pinta ("poligono2 - Hexagono l=4");


	// Comparar áreas

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
	// uno dado (en este caso un triangulo equilátero de longitud 1)

	cout << "**************************************************" << endl;
	cout << "APROXIMACION A CIRCUNFERENCIA" << endl;
	cout << endl;
	cout << "Precision de la aproximacion = ";
	cout << setw(7) << setprecision(5) << UMBRAL << endl;
	cout << "**************************************************" << endl;
	cout << endl;


	// Lectura del factor de incremento del número de lados

	int k;

	do {
		cout << "Factor multiplicador del numero de lados: ";
		cin >> k;
	} while (k<=1);


	// Crear polígono "p" a partir de "poligono1" (triámgulo de tres lados
	// de longitud 1) con la misma circunferencia circunscrita y con k veces
	// el número de lados

	PoligonoRegular p (poligono1.MultiplicaNumLados(k));


	// Calcular el área de la circunferencia circunscrita (área objetivo)

	double radio = p.GetRadio();
	double area_objetivo = PI * radio * radio;

	// Presentar datos iniciales de la aproximación

	cout << endl;
	cout << "Calculando el poligono que aproxima a una circunferencia "
	     << "de radio " << radio << endl;
	cout << "Area de la circunferencia objetivo = "
		 << setw(10) << setprecision(8) << area_objetivo << endl;
	cout << endl;

	cout << "Se construye desde el poligono regular siguiente: ";
	cout << endl;

	p.Pinta ("p - Poligono inicial para la aproximacion");

	// Calcular el polígono que aproxima la circunferencia

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

	// El perímetro del polígono que aproxima a la circunferencia
	//  circunscrita debe ser similar a la longitud de dicha circunferenca.

	cout << endl;
	cout << "La longitud de la circunf. circunscrita es   "
		 << setw(10) << setprecision(8) << 2*PI*p.GetRadio() << endl;
	cout << "El perimetro del poligono que la aproxima es "
	     << setw(10) << setprecision(8) << p.Perimetro() << endl;
	cout << endl;

	return (0);
}

/***************************************************************************/
