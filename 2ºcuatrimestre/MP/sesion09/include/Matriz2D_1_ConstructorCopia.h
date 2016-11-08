//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_1_ConstructorCopia.h
//
/***************************************************************************/

#ifndef Matriz2D_1_ConstructorCopia
#define MATRIZ2D_1_CONSTRUCTORCOPIA

typedef int TipoBase;

class Matriz2D_1{
	private:
		int filas,columnas;
		TipoBase **datos;

	public:
		/*************************************************/
		//
		//Constructores
		//
		/************************************************/
		Matriz2D_1();
		Matriz2D_1(int);
		Matriz2D_1(int ,int );
		Matriz2D_1(int, int , TipoBase);
		Matriz2D_1(const Matriz2D_1 &);
		/*************************************************/
		//
		//Destructor
		//
		/************************************************/
		~Matriz2D_1();
		/*************************************************/
		//
		//Métodos
		//
		/************************************************/
		void InicializaMismoValor(TipoBase);
		void ModificarValor(int, int , TipoBase);
		TipoBase LeerValor (int, int)const;
		bool MatrizVacia();
		void Pinta()const;
		void Inicializa(const TipoBase valor = 0);

	private:
		void ReservaMem(int, int);
		void LiberaMem();
		void Copia(const Matriz2D_1 &);
};


#endif