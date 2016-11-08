/*(Examen Febrero 2012) Sobre el ejercicio anterior:

 Implemente un método para determinar si un cuadrado tiene mayor área que otro.

 Implemente un método para determinar si un cuadrado contiene a otro. Un cuadrado
C1 determinado por la esquina (x1; y1) y la longitud l1 contiene a otro cuadrado
C2 dado por (x2; y2) y l2 si se cumple que 
x2 >= x1 y x2+l2 <= x1+l1
y2 >= y1 y y2 + l2 <= y1 + l1

*/

#include <iostream>
#include <cmath>

using namespace std;

class Punto2D{
	private:
		double abcisa;
		double ordenada;
	public:
		Punto2D(double abcisapunto, double ordenadapunto)
			:abcisa(abcisapunto),									//Constante
			ordenada(ordenadapunto){
			}
		
		void SetCoordenadas(double abcisapunto, double ordenadapunto){
			abcisa = abcisapunto;
			ordenada = ordenadapunto;
		}
		
		double Abcisa(){
			return abcisa;
		}
			
		double Ordenada(){
			return ordenada;
		}
};

class SegmentoDirigido{
	private:
		double x1, y1, x2, y2;
	public:
		SegmentoDirigido(double origenAbcisa, double origenOrdenada, double finalAbcisa, double finalOrdenada)
			:x1(origenAbcisa),
			y1(origenOrdenada),
			x2(finalAbcisa),
			y2(finalOrdenada){
			}
		
		void SetCoordenadas(double origenAbcisa, double origenOrdenada, double finalAbcisa, double finalOrdenada){
			x1 = origenAbcisa;
			y1 = origenOrdenada;
			x2 = finalAbcisa;
			y2 = finalOrdenada;	
		}
		double OrigenAbcisa(){
			return x1;
		}
		double origenOrdenada(){
			return y1;
		}
		double finalAbcisa(){
			return x2;
		}
		double finalOrdenada(){
			return y2;
		}
		double longitud(){
			double resta_abscisas = x2 - x1;
			double resta_ordenadas = y2 - y1;
			return sqrt(resta_abscisas * resta_abscisas + resta_ordenadas * resta_ordenadas);
		}
		void trasladarHorizontal(double unidades){
			x1 = x1 + unidades;
			x2 = x2 + unidades;
		}
		void trasladaVertical(double unidades){
			y1 = y1 + unidades;
			y2 = y2 + unidades;
		}
		void Traslada(double enHorizontal, double enVertical){
			x1 = x1 + enHorizontal;
			x2 = x2 + enHorizontal;
			y1 = y1 + enVertical;
			y2 = y2 + enVertical;
		}
		//Apartado 1: 
		bool SetComparacionArea(double l2){
			bool compara = false;
		
			if(longitud >= l2){
				return compara = true;
			}		
		}
		
		//Apartado 2:
		bool SetContencion(double l2){		//Nos devolvera true si el cuadrado 1 contiene al 22 y false si es al reves.
			bool comparacion = false;
			
			if(x2 >= x1 && x2 + l2 <= x1 + longitud){
				return comparacion = true;
			}
		}	
};

class Circunferencia{
	private:
		double centro_x, centro_y, radio;
	public:
		static const double PI = 3.141592;
		void SetCentro(double abcisa, double ordenada){
			centro_x = abcisa;
			centro_y = ordenada;
		}
		void SetRadio(double elradio){
			radio = elradio;
		}
		double GetAbcisaCentro(){
			return centro_x;
		}
		double GetOrdenadaCentro(){
			return centro_y;
		}
		double GetRadio(){
			return radio;
		}
		double Longitud(){
			return 2 * PI * radio;
		}
		double Area(){
			return PI * radio * radio;
		}
		void Traslada(double enHorizontal, double enVertical){
			centro_x = centro_x + enHorizontal;
			centro_y = centro_y + enVertical;
		}
};

class Cuadrado{
	private:
		double esquina_abcisa;
		double esquina_ordenada;
		double longitud;
	public:
		Cuadrado(double abcisita, double ordenadita, double longitudita)
			:esquina_abcisa(abcisita),
			esquina_ordenada(ordenadita),
			longitud(longitudita){	
			}
		SegmentoDirigido x_1(){
			SegmentoDirigido X1(esquina_abcisa, esquina_ordenada, esquina_abcisa + longitud, esquina_ordenada);
		
			return X1;
		}
		SegmentoDirigido x_2(){
			SegmentoDirigido X2(esquina_abcisa, esquina_ordenada, esquina_abcisa, esquina_ordenada + longitud);
			
			return X2;
		}
		SegmentoDirigido y_1(){
			SegmentoDirigido Y1(esquina_abcisa+longitud, esquina_ordenada, esquina_abcisa + longitud, esquina_ordenada + longitud);
		
			return Y1;
		}
		SegmentoDirigido y_2(){
			SegmentoDirigido Y2(esquina_abcisa, esquina_ordenada + longitud, esquina_abcisa + longitud, esquina_ordenada + longitud);
		
			return Y2;
		}
		Punto2D Centro(){
			Punto2D CENTRO((longitud / 2) + esquina_abcisa, (longitud / 2) + esquina_ordenada);
		
			return CENTRO;
		}
		Circunferencia CircunferenciaInscrita(){
			Circunferencia circulo;
			circulo.SetCentro((longitud / 2) + esquina_abcisa, (longitud / 2) + esquina_ordenada);
			circulo.SetRadio(longitud / 2);
			
			return circulo;
		}
		Circunferencia CircunferenciaCircunscrita(){
			Circunferencia circulo;				//Objeto de la clase circunferencia, 
			SegmentoDirigido longitud1(esquina_abcisa, esquina_ordenada, esquina_abcisa + (longitud / 2), esquina_ordenada + (longitud / 2));
			circulo.SetCentro((longitud / 2) + esquina_abcisa, (longitud / 2) + esquina_ordenada);
			circulo.SetRadio(longitud1.longitud());
			
			return circulo;
		}
		//Apartado 1: area mayor, el area de un cuadrado es l^2, tendra mayor area el que mayor longitud de lados tenga.
		SegmentoDirigido ComparacionArea(double longitud2){
			SegmentoDirigido compara;
			compara.SetComparacionArea(longitud2); 
		}
	
		//Apartado 2: ver si un cuadrado contiene a  otro.
		
		SegmentoDirigido Contencion(double longitud2){
			SegmentoDirigido contiene;
			contiene.SetContencion(longitud2);
			
			return contiene;
		}
};

int main(){
	double abcisa, ordenada, longitud;
	bool contiene, compara;
	
	cout << "\nIntroduzca la esquina abcisa: ";
	cin >> abcisa;
	cout << "\nIntroduzca la esquina ordenada: ";
	cin >> ordenada;
		do{
			cout << "\nIntroduzca la longitud: ";
			cin >> longitud;
			cout << "\nIntroduzca la longitud del segundo cuadrado: ";		//Pides la longitud del segundo cuadrado, ya que todos los calculos dependen unicamente de eso
			cin >> longitud2;
		}while(longitud <= 0 && longitud2 <= 0);

	
	Cuadrado objeto(abcisa, ordenada, longitud);
	
	cout << "\nEl punto central del cuadrado es: " << objeto.Centro().Abcisa() << ", " << objeto.Centro().Ordenada();
	cout << "\nLa circunferencia inscrita tiene de centro: " << objeto.CircunferenciaInscrita().GetAbcisaCentro() << ", " << objeto.CircunferenciaInscrita().GetOrdenadaCentro();
	cout << "\nRadio: " <<objeto.CircunferenciaInscrita().GetRadio();
	cout << "\nLa circunferencia circunscrita tiene de centro: " << objeto.CircunferenciaCircunscrita().GetAbcisaCentro() << ", " << objeto.CircunferenciaCircunscrita().GetOrdenadaCentro();
	cout << "\nRadio: "<< objeto.CircunferenciaCircunscrita().GetRadio();
	//Apartado 1:
	compara = obgeto.ComparacionArea(longitud2);
	
	if(compara){
		cout << "\nEl primer cuadrado tiene mayor area que el segundo";
	}
	else{
		cout << "\nEl segundo cuadrado tiene mayor area que el primero";
	}
	//Apartado 2:
	contiene = obgeto.Contencion(longitud2);
	
	if(compara){
		cout << "\nEl primer cuadrado contiene al segundo";
	}
	else{
		cout << "\nEl segundo cuadrado contiene al primero";
	}
	
}
