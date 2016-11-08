/*Añadid un método EliminaRepetidos que quite los elementos repetidos, de forma
que cada componente sólo aparezca una única vez. Se mantendrá la primera aparición,
de izquierda a derecha. Por ejemplo, si la secuencia contiene
{'b','a','a','h','a','a','a','a','c','a','a','a','g'}
después de quitar los repetidos, se quedaría como sigue:
{'b','a','h','c','g'}

c) El anterior algoritmo nos obliga a desplazar muchas componentes cada vez que
encontremos una repetida. Proponed una alternativa (sin usar vectores locales)
para que el número de desplazamientos sea el menor posible e implementadla.
Consejo: Usad la misma técnica que se indicó en el ejercicio 6 de eliminar las
mayúsculas.*/

#include <iostream>
 using namespace std;
 
class ContadorMayusculas{
	private:
		static const int TAMANIO = 50;
		char cadena[TAMANIO];
		int utilizados;
	public:
		SecuenciaCaracteres()
			:utilizados(0)
	
		int TotalUtilizados(){
			return utilizados;
		}
	
		int Capacidad(){
			return TAMANIO;
		}
	
		void SetCoeficientes(char nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[utilizados] = nuevo;
				utilizados++;
			}
		}
		int ContadorMayusculas(){
			bool es_mayus;
			int i;
			
			for( i = 0; i <= utilizados - 1; i++){
				es_mayus = ((cadena[i] >= 'A') && (cadena[i] <= 'Z'));
				if(es_mayus){
					contador_mayus++;
				}
			}
			return contador_mayus;
		}
		void EliminaSiExiste(char letra){
			int posicion_elim, i;
			bool eliminar = false;
			//comprobamis si la letra introducida existe y nos quedamos con su posicion para borrarlo
			for( i = 0; i < total_utilizados; i++){
				eliminar = (vector_privado[i] == letra)
				if (eliminar){
					for (i = posicion_elim; i < total_utilizados; i++){		// borramos el registro de la letra existente
						vector_privado[i] = -1;
					}
					total_utilizados--;
				}
			}
		}
};

int main(){
	char caracter;
	ContadorMayusculas cadena;
	int j;
	int i = 0;
	char vector_nuevo;
	
	cout << "\nPara dejar de introducir caracteres introduzca '.'";
	
	do{
		cout << "nIntroduzca un caracter: ";
		cin >> caracter;
		cadena.SetCoeficientes(caracter);
		i++;
	}while(caracter != 46 && cadena <= tope);
	
	cout << "\nIntroduzca el caracter que desea eliminar: ";
	cin >> caracter;
	cadena.EliminarSiExiste(caracter);
	
	for(j = 0; j <= i - 1; j++){
		vector_nuevo = caracter.Elemento(j);
		
		cout << "\nEl vector que tiene ahora es: " << vector_nuevo << "\n\n";
	}
}
