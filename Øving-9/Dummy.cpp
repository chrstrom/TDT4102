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
	cin.get(); // For å hindre at
	// programmet avslutter med en gang
}
/*
utskrift: 4 4 4  5 5 5
Tror programmet kræsjer pga Dummy b{ a }; og c = a; 
Når vi avslutter programmet prøver vi å deallokere pekere som allerede er deallokert;
siden vi ikke har veldefinert assignment/copy for Dummy, peker pekeren til b og c til samme lokasjon som a*/