/*Encuentre los errores de las siguientes funciones:*/

/*1. El return, valor que devuelve la funci�n, debe ir fuera del else.
int ValorAbsoluto (int entero)
 {
	if (entero < 0)
		entero = -entero;
	else
		return entero;
}*/
int ValorAbsoluto (int entero)
 {
	if (entero < 0)
		entero = -entero;
	
	return entero;
}

/*2. Las funciones tipo void no tienen return. 
void Cuadrado (int entero) 
{
	return entero*entero;
}*/
void Cuadrado (int entero)
{
	cuadrado = entero*entero;
}

/*3.La variable valor ya est� declarada con la funci�n. 
void Imprime(double valor)
{
	double valor;
	cout << valor;
}*/
void Imprime(double valor) 
{
	cout << valor;
}

/*4. si el valor es positivo entonces la funci�n devuelv true, pero si el valor es menos que cero, entonces no devuelve nada.
bool EsPositivo(int valor) 
{
	if (valor > 0)
		return true;
}*/
bool EsPositivo(int valor) 
{
	return (valor > 0);
}
