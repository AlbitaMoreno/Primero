//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
//Matriz2D_1.h
//
/***************************************************************************/

#ifndef Matriz2D_1
#define MATRIZ2D_1

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
		Matriz2D_1(int ,int );
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
		
		bool MatrizVacia()const;
		void MismoValor(TipoBase valor = 0);
		int GetFilas()const;
		int GetColumnas()const;
		/*************************************************/
		//
		//Sobrecarga de operadores
		//
		/************************************************/

		Matriz2D_1 & operator = (const Matriz2D_1 &);
		Matriz2D_1 & operator = (const TipoBase);
		TipoBase & operator () (const int , const int );
		Matriz2D_1 operator +();
		Matriz2D_1 operator -();
		
		//Operadores combinados
		Matriz2D_1 & operator += (TipoBase);
		Matriz2D_1 & operator -= (TipoBase);
		Matriz2D_1 & operator *= (TipoBase);
		Matriz2D_1 & operator /= (TipoBase);

		//Operadores relacionales
		bool operator == (const Matriz2D_1 &);
		bool operator != (const Matriz2D_1 &);
		/***********************************************/
		//Uso de funciones amigas en la sobrecarga
		friend Matriz2D_1 operator +(const Matriz2D_1 &, const Matriz2D_1 &);
		friend Matriz2D_1 operator +(TipoBase, const Matriz2D_1);
		friend Matriz2D_1 operator +(const Matriz2D_1, TipoBase);
	
	private:
		void ReservaMem(int, int);
		void LiberaMem();
		void CopiaDatos(const Matriz2D_1 &);
};


#endif



