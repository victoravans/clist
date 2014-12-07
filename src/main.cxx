#include "CList.h"
#include <iostream>
#include <list>

using namespace nsSdD;
using namespace std;

int main ()
{
	CList <string> a;
	for (unsigned i = 0; i < 10; ++i) a.push_back ("a");
	cout << a.size ();
	CList<string> b (a);
	



	char Char;
	cin >> Char;
}