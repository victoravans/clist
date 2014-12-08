#include <iostream>
#include "CList.h"
#include "IziAssert.h"
#include "hichemTestUnsigned.h"

using namespace std;
using namespace nsSdD;

void TestCListUnsigned()
{
    CLUs liste;
    for(unsigned i = 0; i < 10; ++i)
        liste.push_back(i);

    TestConstructorDefaultUnsigned();
    TestConstructorWithSizeUnsigned();
    TestConstructorWithValueUnsigned();
    TestConstructorCopyUnsigned(liste);
    TestBackUnsigned(liste);
    TestEmptyUnsigned(liste);
    TestFrontUnsigned(liste);
    TestSizeUnsigned(liste);
    TestOperatorAtUnsigned(liste);
    TestPushBackUnsigned(liste);
    TestPushFrontUnsigned(liste);
    TestPopBackUnsigned(liste);
    TestPopFrontUnsigned(liste);
    //TestOperatorAddUnsigned(liste);
   // TestOperatorDifferentUnsigned(liste);
    TestResizeUnsigned(liste);
    TestClearUnsigned(liste);
    TestEraseUnsigned(liste);
    TestRemoveUnsigned(liste);
    TestContainsUnsigned(liste);
    TestCountUnsigned(liste);
    TestIndexOfUnsigned(liste);
    TestRemoveOneUnsigned(liste);
    TestInsertUnsigned(liste);
    TestSortUnsigned(liste);
}

int Hichem()
{
    TestCListUnsigned();
	char Char;
	cin >> Char;
    return 0;
	
}