/* Recuperad las implementaciones de las clases Punto2D, SegmentoDirigido y
Circunferencia vistas en clase de teoría. Definid también la clase Cuadrado.
Un cuadrado vendrá determinado por el punto correspondiente a la esquina inferior izquierda
y por la longitud de cualquiera de sus lados (estos serán sus datos miembros).
Añadid métodos para observar los valores de los datos miembros y para calcular el
área y el perímetro del cuadrado.

Definid sobre la clase Cuadrado los siguientes métodos:

 Cuatro métodos para devolver cada uno de los lados del cuadrado como objetos
de la clase SegmentoDirigido.

 Obtener el punto central interior al cuadrado:
Punto2D Centro()
Para calcular las coordenadas basta sumar la mitad de la longitud del cuadrado
a las coordenadas de la esquina inferior izquierda.

 Obtener la circunferencia inscrita al cuadrado (la que está por dentro):
Circunferencia CircunferenciaInscrita()
Esta circunferencia es la que tiene como centro el centro del cuadrado y como
radio la mitad de la longitud del cuadrado.

 Obtener la circunferencia circunscrita al cuadrado (la que está por fuera):
Circunferencia CircunferenciaCircunscrita()

Esta circunferencia es la que tiene como centro el centro del cuadrado y como
radio, la longitud del segmento que une el centro con la esquina inferior izquierda.
Obtened la longitud creando el objeto de la clase SegmentoDirigido y a
continuación llamad al método Longitud.

Cread un programa principal que llame a dichos métodos*/

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
			//Objeto de la clase segmento dirigido.
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
};
int main(){
	double abcisa, ordenada, longitud;
	
	cout << "\nIntroduzca la esquina abcisa: ";
	cin >> abcisa;
	cout << "\nIntroduzca la esquina ordenada: ";
	cin >> ordenada;
	do{
		cout << "\nIntroduzca la longitud: ";
		cin >> longitud;
	}while(longitud <= 0);
		
	Cuadrado objeto(abcisa, ordenada, longitud);
	
	cout << "\nEl punto central del cuadrado es: " << objeto.Centro().Abcisa() << ", " << objeto.Centro().Ordenada();
	cout << "\nLa circunferencia inscrita tiene de centro: " << objeto.CircunferenciaInscrita().GetAbcisaCentro() << ", " << objeto.CircunferenciaInscrita().GetOrdenadaCentro();
	cout << "\nRadio: " <<objeto.CircunferenciaInscrita().GetRadio();
	cout << "\nLa circunferencia circunscrita tiene de centro: " << objeto.CircunferenciaCircunscrita().GetAbcisaCentro() << ", " << objeto.CircunferenciaCircunscrita().GetOrdenadaCentro();
	cout << "\nRadio: "<< objeto.CircunferenciaCircunscrita().GetRadio();
}
