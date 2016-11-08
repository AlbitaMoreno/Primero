//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_2_ConstructorCopia.h
//
/***************************************************************************/

#ifndef Matriz2D_2_ConstructorCopia
#define Matriz2D_2_CONSTRUCTORCOPIA

typedef int TipoBase;

class Matriz2D_2{
	private:
		int filas,columnas;
		TipoBase **datos;

	public:
		/*************************************************/
		//
		//Constructores
		//
		/************************************************/
		Matriz2D_2();
		Matriz2D_2(int);
		Matriz2D_2(int ,int );
		Matriz2D_2(int, int , TipoBase);
		Matriz2D_2(const Matriz2D_2 &);
		/*************************************************/
		//
		//Destructor
		//
		/************************************************/
		~Matriz2D_2();
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
		void Copia(const Matriz2D_2 &);
};


#endif