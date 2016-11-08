#include<iostream>
 
using namespace std;
 
int main()
{
   int n, i, primero = 0, segundo = 1, prox;
 
   cout << "Numero de terminos que deseas: ";
   cin >> n;
 
   cout << "primeros " << n << " terminos son: \n";
 
   for ( i = 1 ; i <= n ; i++ )
   {
      if ( i <= 1 )
		{
         prox = i;
   	}
      else
      {
         prox = primero + segundo;
         primero = segundo;
         segundo = prox;
      }
      cout << "  " << prox;
   }

}
