#include "CList.h"
#include <iostream>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a;
	for (int i = 0; i < 10; ++i)
		a.push_front (rand () % 100);
	a.edit ();

	char c;
	cin >> c;
}
