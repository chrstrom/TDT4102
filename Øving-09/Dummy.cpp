#include "Dummy.h"
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

void dummyTest() {
	Dummy a;
	*a.num = 4;
	Dummy b{ a };
	Dummy c;
	c = a;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl;
	*b.num = 3;
	*c.num = 5;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl;
	cin.get(); // For � hindre at
	// programmet avslutter med en gang
}
/*
utskrift: 4 4 4  5 5 5
Tror programmet kr�sjer pga Dummy b{ a }; og c = a; 
N�r vi avslutter programmet pr�ver vi � deallokere pekere som allerede er deallokert;
siden vi ikke har veldefinert assignment/copy for Dummy, peker pekeren til b og c til samme lokasjon som a*/