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
// Generador de n�meros aleatorios. 
// Los objetos de esta clase sirven para generar n�meros aleatorios a demanda 
// con el metodo "Next" entre los valores "min" y "max". 

class MyRandom
{
	
private:
	
	// PRE: minVal <= MaxVal
	
    int minVal;	// M�nimo Valor
    int maxVal;	// M�ximo valor

	/***********************************************************************/
	// Inicializa el generador de n�meros aleatorios 
	// Es un m�todo privado que se invoca solo al actuar el constructor.
	
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
	// Calcula y devuelve un n�mero aleatorio en el rango prefijado.
	
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

 
