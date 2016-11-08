//
// CURSO 2015-2016
// Alba Moreno Ontiveros
// 
// Fichero: MiCadenaClasica.h
// Contiene los prototipos de las funciones de la sesion 4
/***************************************************************************/

#ifndef MICADENCLASICA
#define MICADENCLASICA

//devuelve la longitud de la una cadena clasica
int LongitudCadena(char *p);

//devuelve true si la cadena de caracteres se lee igual de derecha a izquierda y viceversa
bool Palindromo(char *p);

//devuelve true si la cadena de caracteres se lee igual de derecha a izquierda y viceversa
int CompararCadenas(char *a, char *b);

//devuelve true si la cadena de caracteres se lee igual de derecha a izquierda y viceversa
void EncadenarCadena(char *resultado, char *original);

//devuelve true si la cadena de caracteres se lee igual de derecha a izquierda y viceversa
char *CopiarCadena(char *resultado, char *original);

//muestra por pantalla una subcadena del primer parámtro empezando por el indice p y con una lingitud l,
//si la longitud sobrepasa el '\0' entonces se mostrará la subcadena hasta el '\0'
void Subcadena(char *cadena, int p, int l);

//devuelve la direccion de memoria de la primera celda de la nueva
//cadena invertida
void *InvierteCadena(char *cadena);

//Intercambia dos caracteres
void Intercambia_Caracteres(char *p1, char *p2);

#endif