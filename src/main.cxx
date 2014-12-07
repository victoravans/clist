#include "CList.h"
#include <iostream>
#include <list>
#include "iterator.cpp"

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a;
	for (unsigned i = 1; i < 10; ++i)
		a.push_back (i);
	CList<int>::iterator Iter = a.begin ();
	Iter.cunt ();


	char Char;
	cin >> Char;
}