#include "CList.h"
#include <iostream>
#include <list>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a;
	for (unsigned i = 0; i < 10; ++i) a.push_back (i);
	cout << a.size ();



	char Char;
	cin >> Char;
}