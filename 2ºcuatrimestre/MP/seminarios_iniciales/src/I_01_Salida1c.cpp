#include <iostream>
using namespace std;

int main(){
	int a = 5, *p = &a;

	*p = *p * a;
	cout << "p: " << *p  << "a: " << a << endl;
	if(a == *p)
		cout << "a es igual a *p" << endl;
	else
		cout << "a es diferente *p" << endl;
	return 0;
}