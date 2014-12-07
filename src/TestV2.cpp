#include "CList.h"
#include <iostream>
#include <list>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a, b;
	for (unsigned i = 0; i < 5; ++i)
	{
		a.push_back (2);
	}
	for (unsigned i = 0; i < 3; ++i)
	{
		b.push_back (5);
	}
	
	a.splice (++a.begin(), b);
	cout << endl;
	a.edit ();
	cout << endl;
	b.edit ();











	char Char;
	cin >> Char;
}