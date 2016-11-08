#include <iostream>
using namespace std;

int main(){
	int a = 5, *p;

	*p = *p *a;

	if (a == *p)
		cout << "a es igual a *p" << endl;
	else
		cout << "a no es igual a *p" << endl;
	return 0;
}