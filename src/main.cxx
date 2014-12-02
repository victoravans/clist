#include "CList.h"
#include <iostream>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a,b;
	for (unsigned i = 1; i <= 5; ++i)
		a.push_back (i);
	for (unsigned i = 10; i <= 12; ++i)
		b.push_back(i);
	a.AfficherList();
	cout << endl;
	a = b;
	a.AfficherList();
}
