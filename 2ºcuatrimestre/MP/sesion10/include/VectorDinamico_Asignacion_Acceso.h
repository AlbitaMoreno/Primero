//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// VectorDinamico_Asignacion_Acceso.h
//
/***************************************************************************/

#ifndef VectorDinamico_Asignacion_Acceso
#define VECTORDINAMICO_ASIGNACION_ACCESO

typedef double TipoBase;
enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

class MiVectorDinamico{
	private:
		TipoBase *vec;
		int tam;
		TipoRedimension redimension = DeUnoEnUno;
		static const int TAMANIO_DEF = 5;

	public:
		/*************************************************/
		//
		//Constructores
		//
		/************************************************/
		
		MiVectorDinamico();		//constructor sin argumentos
		MiVectorDinamico(int );	//constructor con el num_casillas del nuevo vector
		MiVectorDinamico(const MiVectorDinamico & );		//constructor de copia sobrecargado
		
		/*************************************************/
		//
		//Destructor
		//
		/************************************************/
		
		~MiVectorDinamico();
		
		/*************************************************/
		//
		//Métodos
		//
		/************************************************/
		
		bool VectorVacio() const;
		int GetTamanio()const;
		void SetRedimension(TipoRedimension);
		void MuestraTipoRedimension() const;
		TipoBase * Redimensiona ();
		int GetUsados();
		void MismoValor( TipoBase valor = 0);

		/*************************************************/
		//
		//sobrecarga de operadores
		//
		/************************************************/
		
		MiVectorDinamico & operator = (const MiVectorDinamico & );
		MiVectorDinamico & operator = (const TipoBase );
		TipoBase & operator [](const int );

	private:
		
		void ReservaMem(int);	//reserva mememoria
		void LiberaMem();	//Libera memoria si se puede
		void CopiarDatos(const MiVectorDinamico &);		//copio en otro vector los datos que se pasan como argumento


};

#endif