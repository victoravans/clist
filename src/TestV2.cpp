#include "CList.h"
#include <iostream>
#include <list>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a;
	for (unsigned i = 0; i < 10; ++i) a.push_back (i);
	CList<int> b (a);
	a.edit ();
	cout << endl;
	b.edit ();
	cout << endl;
	b = a; 
	b.edit ();




	char Char;
	cin >> Char;
}