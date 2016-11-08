#include <iostream>
#include <cmath>

using namespace std;

/*El programa intercambia variables x=10, y=20, z=30 de forma que x=y y=z y z=x */

int main(int argc, char** argv) {
	
	double equis = 10;
	double igriega = 20;
	double ceta = 30;
	double aux1 = igriega;		//declaramos dos variable auxiliares para que los valores se 
                           		//cambien sin ningún tipo de fallo.		
	aux1 = equis;
	equis =  igriega; 
	igriega = ceta;
   ceta = aux1;
     
	cout <<"\nLos nuevos valores de x, y, z son: " << equis <<" " << igriega <<" "<< ceta << " " "\n\n";
	
	system("PAUSE");
    
    return 0;
}
	

