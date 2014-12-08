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
	const CList<int> c (a);
	a.splice (--a.end(), b, b.begin(), ++b.begin());
	a.edit ();
	cout << endl;
	b.edit ();











	char Char;
	cin >> Char;
}