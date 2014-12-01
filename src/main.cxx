#include "CList.h"
#include "CList.cxx"
#include <iostream>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a,b;
	for (unsigned i = 1; i <= 3; ++i)
		a.push_front (i);
	a.resize(5, 10);
	a.AfficherList ();

}
