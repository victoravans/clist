#include "CList.h"
#include "CList.cxx"
#include <iostream>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a,b;
	for (unsigned i = 1; i <= 5; ++i)
		a.push_back (i);
	for (unsigned i = 1; i <= 5; ++i)
		b.push_back(i);
	a.merge(b);
	a.AfficherList();
	cout << endl;
	a.unique();
	a.AfficherList();
}
