#include "CList.h"
#include <iostream>
#include <list>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <int> a;
	for (unsigned i = 0; i < 10; ++i) a.push_back (i);
	a.edit ();
	cout << endl;
	auto Iter = a.begin ();
	cout << *++Iter << endl;
	CList<int> b (a);
	b.edit ();
	*b.front () = 2;
	cout << endl;
	b.edit ();
	a.edit ();
	



	char Char;
	cin >> Char;
}