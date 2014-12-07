#include "CList.h"
#include <iostream>
#include <list>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a, b;
	for (unsigned i = 0; i < 10; ++i)
	{
		a.push_back (rand () % 10);
	}
	const CList <int> c (a);
	a.sort ();
	a.edit ();











	char Char;
	cin >> Char;
}