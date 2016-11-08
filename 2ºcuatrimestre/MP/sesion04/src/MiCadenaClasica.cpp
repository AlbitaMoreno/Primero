//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: MiCadenaClasica.cpp
// Contiene las funciones implementadas de la sesion 4
/***************************************************************************/
#include <iostream>
#include "MiCadenaClasica.h"

using namespace std;

//Función global que calcula la longitud de una cadena clásica
//recibe un puntero a v, la dir. de la primera posició de v

int LongitudCadena(char *p){
	//creamos un puntero *p que apunta a la primera posición de v
	//char *p = &v;
	//incializamos longitud a 0
	int longitud = 0; 
	//bucle que irá desde la primera hasta que encuentre el '\0' de forma que incrementará
	//la longitud con cada vuelta
	while(*p != '\0'){
		longitud++;
		//apuntamos a l siguiente posición
		p++;
	}

	//devolvemos la longitud

	return(longitud);
}

//devuelve true si una cadean se lee igual de derecha a izquierda
bool Palindromo(char *p){
	bool palindromo;
	char copia[100];
	char *der = &copia[0];
	//copio el vector al que apunta p en copia y desde ahi compruebo si es paindromo
	while (*p != '\0'){		
		*der = *p;
		der++;
		p++;
	}
	
	char *izq = &copia[0];

	der = &copia[(LongitudCadena(copia)-1)];
	//mientras no se crucen los punteros, el bucle compara el contenido de ambos en 
	//ese instante, si son iguales entonces es un palindromo, pero si una letra falla, 
	//entramos en el if, lo que hace es apuntar ambos punteros a la posicion incial para 
	//que salgan del bucle while, devolviendo así palindromo = false si una letra no coincide
	while(izq != der){
		palindromo = (*izq == *der);
		izq++;
		der--;
		if(!palindromo){
			izq = der;
		}
	}

	//devuelvo palindromo
	return(palindromo);
}

int CompararCadenas(char *a,char *b){
	//incialmente las cadenas son iguales,de forma que al ir comparandolas 
	//se resten o se sumen unos según sea el caso
	int contador = 0;

	//mientras no sean *a y *b simultaneamente 0 el bucle continuará, de forma que
	//no necesito el tamaño ya que el while seguirá hasta que el más grande termine
	while(*a != '\0' && *b != '\0'){
		//es valor de la primera es más pequeño que el de la segunda
		if(*a < *b){
			contador--;
		}
		//la segunda es más pequeña que la primera
		if(*a > *b){
			contador++;
		}
		//se ha terminado de recorrer la cadena a pero la cadena b es de mayor longitud
		if(*a == '\0'){
			contador--;
		}
		//se ha terminado de recorrer b pero a es de mayor longitud
		if(*b == '\0'){
			contador++;
		}
		a++;
		b++;
	}

	return(contador);
}

void EncadenarCadena(char *resultado, char *origen){
	//este bucle llega al final de la cadena resultado
	while(*resultado != '\0'){
		resultado++;
	}
	//resultado está apuntando a la última posicion de memoria
	//una vez tengo el final de la cadena lo que hago es sobreescribir los valores desde
	//el '\0' hasta el final de origen

	while(*origen != '\0'){
		*resultado = *origen;
		resultado++;
		origen++;
	}
	//introduzco el '\0' manualmente al final de la cadena
	*resultado = '\0';
}

//copiar la cadena origen en la cadena resultado
char *CopiarCadena(char *resultado, char *origen){
	char *aux = resultado;
	//mientars origen sea distinto del char nulo entonces copia el contenido de la direccion
	//apuntada por origen en la direccion apuntada por resultado
	while(*origen != '\0'){
		*resultado = *origen;
		//incremento origen y resultado para moverme en los vectores
		resultado++;
		origen++;
	}
	//introducimos manualmente el '\0'
	*resultado = '\0';
	return(aux);
}

//recibe la direccion de la primera posición del vector cadena, entero p que será el índice de que partimos
//y l, que es la longitud de la cadena.
void Subcadena(char *cadena, int p, int l){
	//reservo la longitud +1 para poder meter como último char el '\0'
	char resultado[l+1];
	char *res = &resultado[0];
	//creo un puntero que empezará apuntando la primera casilla que nos interesa y se moverá hasta el ptr constante
	//tope, que estará en la última posición que queremos, según la longitud, o hasta que encuentre el '\0'
	char *ptr = &cadena[p];
	
	char *tope = &resultado[l];
	//rellenos se encarga de contabilizar los indices que se van llenando, lo uso para poder el terminador '\0'
	int rellenos = 0;
	
	//mientras ptr no se cruce con tope ó *ptr sea distinto de '\0' , recorremos la subcadena mostrando 
	//los valores a los que va apuntando ptr
	while(res != tope){
		*res = *ptr;
		
		ptr++;
		res++;

		//si la longitud de la subcadena es más grande que cadena se devuelve la menor subcadena encontrada
		if(*ptr == '\0')
			res = &resultado[l];
		rellenos++;
	}
	//para que sea una cadena clasica tiene que tener un '\0' al final
	res = &resultado[rellenos];
	*res = '\0';
	//devuelvo la primera posicion en memoria de resultado
	res = &resultado[0];
	cout << res << endl;
}

void *InvierteCadena(char *original){
	char resultado[LongitudCadena(original)+1];
	char *invertida = &resultado[0];
	char *ptr = &original[(LongitudCadena(original)-1)];
	//fin siempre va a tener la primera posicion de original
	//de forma que si ptr y fin se cruzan el bucle acaba y
	//habremos invertido el vector con exito
	char const *fin = &original[0];

	while (ptr != fin){
		//al objeto apuntado por invertida le asigno el valor del objeto
		//apuntado por original
		*invertida = *ptr;
		//aumento invertida y retrocedo en original
		invertida++;
		ptr --;
	}
	//el primer valor lo tengo que meter manualmente
	*invertida = *fin;
	//el caracter '\0' lo meto manualmente
	invertida = &resultado[LongitudCadena(original)];
	*invertida = '\0';
	//devuelvo la direccion de la primera posicion del vector invertido
	invertida = &resultado[0];
	cout << invertida << endl;
}

//intercambia dos caracteres de posicion de memoria
void Intercambia_Caracteres(char *p1, char *p2){
	char tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}