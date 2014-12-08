#include "CList.h"
#include "IziAssert.h"

#ifndef TESTUNSIGNED_H_INCLUDED
#define TESTUNSIGNED_H_INCLUDED

using namespace nsSdD;

typedef CList<unsigned> CLUs;

void TestConstructorDefaultUnsigned()
{
    CLUs liste;
    IZI_ASSERT(liste.empty());
}

void TestConstructorWithSizeUnsigned()
{
    CLUs liste(5);
    IZI_ASSERT(liste.size() == 5);
}

void TestConstructorWithValueUnsigned()
{
    CLUs liste(5, 2);
    IZI_ASSERT(liste.back() == 2 && liste.front() == 2);
}

void TestConstructorCopyUnsigned(const CLUs& liste)
{
    CLUs listeCopy(liste);
    IZI_ASSERT(listeCopy.size() == liste.size());
    IZI_ASSERT(listeCopy[5] == liste[5]);
    IZI_ASSERT(listeCopy[1] == liste[1]);
}

void TestEmptyUnsigned(const CLUs& liste)
{
    IZI_ASSERT(liste.empty() == false);
}

void TestBackUnsigned(const CLUs& liste)
{
    IZI_ASSERT(liste.back() == 9);
}

void TestFrontUnsigned(const CLUs& liste)
{
    IZI_ASSERT(liste.front() == 0);
}

void TestSizeUnsigned(const CLUs& liste)
{
    IZI_ASSERT(liste.size() == 10);
}

void TestOperatorAtUnsigned(const CLUs& liste)
{
    IZI_ASSERT(liste[5] == 5);
}

void TestPushFrontUnsigned(CLUs& liste)
{
    liste.push_front(18);
    IZI_ASSERT(liste[0] == 18);
}

void TestPushBackUnsigned(CLUs& liste)
{
    liste.push_back(18);
    IZI_ASSERT(liste[liste.size()-1] == 18);
}

void TestPopBackUnsigned(CLUs& liste)
{
    size_t oldSize = liste.size();
    liste.pop_back();
    IZI_ASSERT(liste.size() == oldSize - 1);
}

void TestPopFrontUnsigned(CLUs& liste)
{
    size_t oldSize = liste.size();
    liste.pop_front();
    IZI_ASSERT(liste.size() == oldSize - 1);
}

void TestOperatorAddUnsigned(CLUs& liste)
{
    CLUs listeTwo(liste);
//    listeTwo += liste;
    IZI_ASSERT(listeTwo.size() == liste.size() + liste.size());
}

void TestOperatorDifferentUnsigned(CLUs& liste)
{
    CLUs listeTwo(liste);
//    IZI_ASSERT((liste != listeTwo) == false);
}

void TestResizeUnsigned(CLUs& liste)
{
    CLUs listeTwo(liste);
    listeTwo.resize(4);
    IZI_ASSERT(listeTwo.size() == 4);
}

void TestClearUnsigned(CLUs& liste)
{
    CLUs listeTwo(liste);
    listeTwo.clear();
    IZI_ASSERT(listeTwo.size() == 0);
}

void TestEraseUnsigned(CLUs& liste)
{
    liste.erase(0);
    IZI_ASSERT(liste.size() == 9);
}

void TestRemoveUnsigned(CLUs& liste)
{
    liste.remove(2);
    IZI_ASSERT(liste.size() == 8);
}

void TestContainsUnsigned(CLUs& liste)
{
   // IZI_ASSERT(liste.contains(2) == false);
}

void TestCountUnsigned(CLUs& liste)
{
   // IZI_ASSERT(liste.count(5) == 1);
}

void TestIndexOfUnsigned(CLUs& liste)
{
   // IZI_ASSERT(liste.indexOf(1) == 0);
}

void TestRemoveOneUnsigned(CLUs& liste)
{
   // IZI_ASSERT(liste.removeOne(1) == true);
}

void TestInsertUnsigned(CLUs& liste)
{
    liste.insert(0,0);
    IZI_ASSERT(liste[0] == 0);
}

void TestSortUnsigned(CLUs&liste)
{
    liste.sort();
    bool test = true;
    for(unsigned i = 1; i < liste.size(); ++i)
        test = liste[i - 1] < liste[i];
    IZI_ASSERT(test);
}

#endif // TESTUNSIGNED_H_INCLUDED
