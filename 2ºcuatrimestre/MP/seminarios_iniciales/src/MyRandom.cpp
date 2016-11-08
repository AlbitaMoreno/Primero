/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Clase: MyRandom
//
/***************************************************************************/


#include <cstdlib> // Necesario para la clase MyRandom 
#include <ctime>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
// Generador de números aleatorios. 
// Los objetos de esta clase sirven para generar números aleatorios a demanda 
// con el metodo "Next" entre los valores "min" y "max". 

class MyRandom
{
	
private:
	
	// PRE: minVal <= MaxVal
	
    int minVal;	// Mínimo Valor
    int maxVal;	// Máximo valor

	/***********************************************************************/
	// Inicializa el generador de números aleatorios 
	// Es un método privado que se invoca solo al actuar el constructor.
	
	void InitMyRandom (void)
    {
        time_t t;
        srand ((int) time(&t));     // Inicializa el generador
                                    // con el reloj del sistema
    }
    
public:
	
	/***********************************************************************/	
	// Constructor
	
    MyRandom (int el_minimo, int el_maximo) :
        minVal(el_minimo), maxVal(el_maximo)
    {
        InitMyRandom();

        int no_lo_uso = Next(); // Desecho el primero
    }

	/***********************************************************************/	
	// Calcula y devuelve un número aleatorio en el rango prefijado.
	
    int Next (void) {
    	
        int rango = (maxVal - minVal)+1;
        int v1 = rango * (rand() / (RAND_MAX*1.0));
        int v2 = minVal + (v1 % rango);

        return (v2);
    }

	/***********************************************************************/
	
    int Min (void) 
	{
        return (minVal);
    }

	/***********************************************************************/
	
    int Max (void) 
	{
        return (maxVal);
    }

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////

 
