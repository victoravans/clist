#include "CList.h"
#include <iostream>
#include <list>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a;
	for (unsigned i = 1; i < 10; ++i)
		a.push_back (i);
	CList<int>::iterator b;
	auto c (b);
	char Char;
	cin >> Char;
}