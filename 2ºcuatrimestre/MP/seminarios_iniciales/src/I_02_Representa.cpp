#include <iostream>
using namespace std;

struct Celda {
	int d;
	Celda *p1, *p2, *p3;
};

int main(int argc, char *argv[]){
	Celda a,b,c,d;

	a.d=b.d=c.d=d.d=0;

	a.p1 = &c;
	cout << " a.p1: " << a.p1 << endl;
	c.p3 = &d;
	cout << " c.p3: " << c.p3 << endl;
	a.p2 = a.p1->p3;
	cout << " a.p2: " << a.p2 << endl;
	d.p1 = &b;
	cout << " d.p1: " << d.p1 << endl;
	a.p3 = c.p3->p1;
	cout << " d.p1: " << d.p1 << endl;
	cout << " c.p1: " << c.p3 << endl;
	a.p3->p2 = a.p1;
	cout << " a.p3: " << a.p3 << endl;
	cout << " a.p2: " << a.p2 << endl;
	a.p1->p1 = &a;
	cout << " a.p1: " << a.p1 << endl;
	a.p1->p3->p1->p2->p2 = c.p3->p1;
	cout << " a.p1: " << a.p1 << endl;
	cout << " c.p3: " << c.p3 << endl;
	c.p1->p3->p1 =&b;
	cout << " c.p1: " << c.p1 << endl;
	cout << " c.p2: " << c.p2 << endl;
	(*((*(c.p3->p1)).p2->p3)).p3 = a.p1->p3;
	cout << " c.p3: " << c.p3 << endl;
	cout << " a.p1: " << a.p1 << endl;

	a.p1->p2->p2->p1->d = 5;
	cout << " a.p1: " << a.p1 << endl;
	cout << " a.p2: " << a.p2 << endl;
	d.p1->p3->p1->p2->p1->p1->d=7;
	cout << " d.p1: " << d.p1 << endl;
	(*(d.p1->p3)).p3->d=9;
	cout << " d.p3: " << d.p3 << endl;
	c.p1->p2->p3->d = a.p1->p2->d-2;
	cout << " c.p1: " << c.p1 << endl;
	(*(c.p2->p1)).p2->d =10;
	cout << " c.p2: " << c.p2 << endl;

	cout << "a=" << a.d << " b=" << b.d << " c=" << c.d << " d=" << d.d << endl;
}