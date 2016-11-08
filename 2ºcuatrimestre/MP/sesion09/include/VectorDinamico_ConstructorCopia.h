//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: VectorDinamico_ConstructorCopia.h
// 
//
/***************************************************************************/

#ifndef VectorDinamico_ConstructorCopia
#define VECTORDINAMICO_CONSTRUCTORCOPIA

typedef double TipoBase;
enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

class MiVectorDinamico{
	private:
		TipoBase *vec;
		int tam;
		int usados;
		TipoRedimension redimension;
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
		int GetUsados()const;
		int GetTamanio()const;
		void SetValor(TipoBase);
		void SetRedimension(TipoRedimension);
		TipoBase GetValor(int ) const;
		void MuestraTipoRedimension() const;
		void PintaVector() const;
		int Suma(int, int );
		TipoBase * Redimensiona ();

	private:
		void ReservaMem(int);	//reserva mememoria
		void LiberaMem();	//Libera memoria si se puede
		void CopiarDatos(const MiVectorDinamico &);		//copio en otro vector los datos que se pasan como argumento


};

#endif